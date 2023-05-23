#include <sstream>
#include "Genie-Compiler.h"
#include "../semantic-analyzer/Genie-SemanticAnalyzer.h"

namespace genie {
    GenieCompiler::GenieCompiler(GenieSymbolTable* symbol_table) {
        symbol_table->reset();

        process_int = [this](GenieInt i) {
            auto reg = byc.emit_integer_literal_mov(i,GenieByteCodeEmitter::MovType::GLOBAL);
            used_regs.push(reg);
        };
        process_real = [this](GenieReal* r) {
            auto reg = byc.emit_real_literal_mov(r,GenieByteCodeEmitter::MovType::GLOBAL);
            used_regs.push(reg);
        };
        process_binary = [this](GenieBinaryExpr* expr) {
            auto right_result = used_regs.top();
            used_regs.pop();
            auto left_result = used_regs.top();
            used_regs.pop();
            auto reg = byc.emit_binary_instruction(left_result,right_result,expr->op);
            used_regs.push(reg);
        };

        postprocess_ifcond_preprocess_ifthen = [this](GenieIfElse* ifElse) {
            auto cond_result = used_regs.top();
            used_regs.pop();

            auto if_id = reinterpret_cast<long long int>(ifElse);
            std::stringstream then_label,else_label;
            then_label << "then!!!"<<if_id;
            else_label << "else!!!"<<if_id;

            byc.register_label(then_label.str());
            byc.register_label(else_label.str());

            byc.emit_2way_conditional_branch(cond_result,then_label.str(),else_label.str());
            byc.set_label_to_curr_buffer_pos(then_label.str());
        };
        postprocess_ifthen_preprocess_ifelse = [this](GenieIfElse* ifElse) {
            auto if_id = reinterpret_cast<long long int>(ifElse);
            std::stringstream else_label,endif_label;
            else_label << "else!!!"<<if_id;
            endif_label << "endif!!!"<<if_id;

            byc.register_label(endif_label.str());
            byc.emit_unconditional_branch(endif_label.str());
            byc.set_label_to_curr_buffer_pos(else_label.str());
        };
        process_if_else = [this](GenieIfElse* ifElse) {
            auto if_id = reinterpret_cast<long long int>(ifElse);
            std::stringstream endif_label;
            endif_label << "endif!!!"<<if_id;
            byc.set_label_to_curr_buffer_pos(endif_label.str());
        };

        postprocess_switchcond_preprocess_all_cases = [this](GenieSwitch* swtch) {
            auto switch_id = reinterpret_cast<long long int>(swtch);

            for (size_t i = 0; i < swtch->cases.size(); i++) {
                std::stringstream endcase_label;
                endcase_label<<"endcase!!!"<<switch_id<<"_"<<i;
                byc.register_label(endcase_label.str());
            }

            used_regs_for_switch_conds.push(used_regs.top());
            used_regs.pop();
        };
        postprocess_caseexpr_preprocess_casebody = [this](GenieSwitch* swtch,int i) {
            auto switch_id = reinterpret_cast<long long int>(swtch);
            std::stringstream endcase_label;
            endcase_label<<"endcase!!!"<<switch_id<<"_"<<i;

            auto switchcond_reg = used_regs_for_switch_conds.top();
            auto caseexpr_reg = used_regs.top();
            auto result = byc.emit_binary_instruction(switchcond_reg,caseexpr_reg,GenieBinaryExpr::GenieBinaryOp::EQ_OP);
            byc.emit_1way_falsey_conditional_branch(result,endcase_label.str());
        };
        postprocess_casebody_preprcocess_nextcase = [this](GenieSwitch* swtch,int i) {
            auto switch_id = reinterpret_cast<long long int>(swtch);

            std::stringstream endswitch_label;
            endswitch_label<<"endcase!!!"<<switch_id<<"_"<<swtch->cases.size()-1;
            byc.emit_unconditional_branch(endswitch_label.str());

            std::stringstream endcase_label;
            endcase_label<<"endcase!!!"<<switch_id<<"_"<<i;
            byc.set_label_to_curr_buffer_pos(endcase_label.str());

        };
        process_switch = [this](GenieSwitch* swtch) {
            used_regs_for_switch_conds.pop();
        };

        process_data_declaration = [this,symbol_table](GenieData* d) {
            if (d->initializer.type != GenieExpr::GenieExprType::NONE_TYPE) {
                GenieScope::VarInfo* inf = symbol_table->lookup_var(d->name);
                auto reg = byc.emit_reg_mov(
                                used_regs.top(),
                                (symbol_table->current_scope_is_global_scope())? GenieByteCodeEmitter::MovType::GLOBAL : GenieByteCodeEmitter::MovType::LOCAL);
                inf->additional_info.push_back(new VarReg(reg));
                used_regs.pop();
            }
        };
        process_assignment = [this,symbol_table](GenieAssign* assign) {
            GenieScope::VarInfo* inf = symbol_table->lookup_var(assign->lhs);
            VarReg* vr = dynamic_cast<VarReg*>(inf->additional_info[inf->additional_info.size()-1]);

            if (vr == nullptr) {
                auto reg = byc.emit_reg_mov(
                                used_regs.top(),
                                (symbol_table->current_scope_is_global_scope())? GenieByteCodeEmitter::MovType::GLOBAL : GenieByteCodeEmitter::MovType::LOCAL);
                inf->additional_info.push_back(new VarReg(reg));
            }
            else {
                byc.emit_reg_mov(used_regs.top(),vr->reg);
            }
            used_regs.pop();

        };
        process_identifier = [this,symbol_table](std::string* id) {
            auto var_info = symbol_table->lookup_var(*id);
            auto additional_var_info = var_info->additional_info;
            auto var_reg = dynamic_cast<VarReg*>(additional_var_info[additional_var_info.size()-1]);

            used_regs.push(var_reg->reg);
        };

        process_block = [this,symbol_table](GenieBlock* b) {
            symbol_table->enter_new_scope();
        };
        postprocess_block = [this,symbol_table](GenieBlock* b) {
            symbol_table->leave_current_scope();
        };


        preprocess_for = [this,symbol_table](GenieFor*) {
            symbol_table->enter_new_scope();
        };
        postprocess_forstart_preprocess_forend = [this,symbol_table](GenieFor* forr) {
            auto reg = byc.emit_reg_mov(used_regs.top(),GenieByteCodeEmitter::MovType::LOCAL);
            auto inf = symbol_table->lookup_var(forr->var);
            inf->additional_info.push_back(new VarReg(reg));

            auto for_id = reinterpret_cast<long long int>(forr);
            byc.register_label("for!!!" + std::to_string(for_id));
            byc.set_label_to_curr_buffer_pos("for!!!" + std::to_string(for_id));
        };
        postprocess_forend_preprocess_forbody = [this,symbol_table](GenieFor* forr) {
            auto for_id = reinterpret_cast<long long int>(forr);
            auto for_end = used_regs.top();
            used_regs.pop();

            auto for_var_info = symbol_table->lookup_var(forr->var);
            auto for_var_reg_info = for_var_info->additional_info[for_var_info->additional_info.size()-1];
            auto for_var_reg= dynamic_cast<VarReg*>(for_var_reg_info)->reg;
            auto result = byc.emit_binary_instruction(for_var_reg,for_end,GenieBinaryExpr::GenieBinaryOp::LTE_OP);

            byc.register_label("endfor!!!"+std::to_string(for_id));
            byc.emit_1way_falsey_conditional_branch(result,"endfor!!!"+std::to_string(for_id));

        };
        process_for = [this,symbol_table](GenieFor* forr) {
            auto for_id = reinterpret_cast<long long int>(forr);
            auto for_step = used_regs.top();

            GenieScope::VarInfo* inf = symbol_table->lookup_var(forr->var);
            VarReg* vr = dynamic_cast<VarReg*>(inf->additional_info[inf->additional_info.size()-1]);
            byc.emit_reg_mov(for_step,vr->reg);

            byc.emit_unconditional_branch("for!!!" + std::to_string(for_id));
            byc.set_label_to_curr_buffer_pos("endfor!!!"+std::to_string(for_id));
            symbol_table->leave_current_scope();
        };

        preprocess_while = [this,symbol_table](GenieWhile* whil) {
            auto while_id = reinterpret_cast<long long int>(whil);
            byc.register_label("while!!!"+std::to_string(while_id));
            byc.set_label_to_curr_buffer_pos("while!!!"+std::to_string(while_id));
        };
        postprocess_whilecond_preprocess_whilebody = [this,symbol_table](GenieWhile* whil) {
            auto while_id = reinterpret_cast<long long int>(whil);
            byc.register_label("endwhile!!!"+std::to_string(while_id));
            byc.emit_1way_falsey_conditional_branch(used_regs.top(),"endwhile!!!"+std::to_string(while_id));
        };
        process_while = [this,symbol_table](GenieWhile* whil) {
            auto while_id = reinterpret_cast<long long int>(whil);
            byc.emit_unconditional_branch("while!!!"+std::to_string(while_id));
            byc.set_label_to_curr_buffer_pos("endwhile!!!"+std::to_string(while_id));
        };

        preprocess_rep_until = [this,symbol_table](GenieRepUntil* repuntil) {
            auto repuntil_id = reinterpret_cast<long long int>(repuntil);

            byc.register_label("repeatuntil!!!"+std::to_string(repuntil_id));
            byc.set_label_to_curr_buffer_pos("repeatuntil!!!"+std::to_string(repuntil_id));
        };
        process_rep_until = [this,symbol_table](GenieRepUntil* repuntil) {
            auto repuntil_id = reinterpret_cast<long long int>(repuntil);
            byc.emit_1way_falsey_conditional_branch(used_regs.top(),"repeatuntil!!!"+std::to_string(repuntil_id));
        };

        preprocess_function = [this,symbol_table](GenieFunction* f) {
            symbol_table->enter_new_scope();
            byc.enter_function();

            for (auto const& p : f->params) {
                auto p_info = symbol_table->lookup_var(p.name);
                p_info->additional_info.push_back(
                        new VarReg(byc.mk_arg_reg(p.type))
                );
            }


            std::string label = "FUNCTION_"+ f->name +"!!!"+ std::to_string(reinterpret_cast<long long int>(f));
            byc.register_if_not_already_registered(label);
            byc.set_label_to_curr_buffer_pos(label);
            byc.emit_no_op();
        };
        process_function = [this,symbol_table](GenieFunction* f) {
            symbol_table->leave_current_scope();
            byc.leave_function();

            std::string label = "ENDFUNCTION_"+ f->name +"!!!"+ std::to_string(reinterpret_cast<long long int>(f));
            byc.register_if_not_already_registered(label);
            byc.set_label_to_curr_buffer_pos(label);
        };

        process_ret = [this,symbol_table](GenieRet* r) {
            if (r->e.type != GenieExpr::GenieExprType::NONE_TYPE) {
                byc.emit_ret(used_regs.top());
                used_regs.pop();
            }
            else {
                byc.emit_ret();
            }
        };

        process_funcall = [this,symbol_table](GenieFunCall* call) {
            auto fun_info = symbol_table->lookup_fun(call->fun_name);
            auto fun_def = fun_info->func;

            std::vector<GenieByteCodeEmitter::RegId> args;
            for (size_t i = 0; i < fun_def->params.size(); ++i) {
                args.push_back(used_regs.top());
                used_regs.pop();
            }
            std::reverse(args.begin(),args.end());

            auto result = byc.emit_function_call(
                    "FUNCTION_" + fun_def->name + "!!!" + std::to_string(reinterpret_cast<long long int>(fun_def)),
                    args,
                    fun_def->ret_type
            );

            if (fun_def->ret_type != "void") used_regs.push(result);
        };
    }
}