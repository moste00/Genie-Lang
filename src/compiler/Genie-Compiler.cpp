#include <sstream>
#include "Genie-Compiler.h"
namespace genie {
    GenieCompiler::GenieCompiler() {
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
    }
}