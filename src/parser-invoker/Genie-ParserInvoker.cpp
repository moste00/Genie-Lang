
#include "Genie-ParserInvoker.h"

namespace genie {
    void ParserInvoker::ast_for_each(AstProcessor& p) {
        p.process_prog(prog);

        for (GenieModule* mod : prog.modules) {
            mod_ast_for_each(mod,p);
        }
    }

    void ParserInvoker::mod_ast_for_each(GenieModule* mod,AstProcessor& p) {
        if (!mod) return;
        if (mod->content.t == GenieModule::Type::SIMPLE_MODULE) {
            p.process_simple_mod(mod->content.c.elems);

            for (GenieModule::ModuleElem elem : mod->content.c.elems) {
                dispatch_mod_elem(elem,p);
            }
        }
        else {
            p.process_complex_mod(mod->content.c.files);
            for (GenieModule* m : mod->content.c.files) {
                mod_ast_for_each(m,p);
            }
        }
    }

    void ParserInvoker::dispatch_mod_elem(GenieModule::ModuleElem& elem,AstProcessor& p) {
        switch (elem.t) {
            case GenieModule::ModuleElem::Type::EXPR: {
                expr_ast_for_each(elem.e.expr, p);
                break;
            }
            case GenieModule::ModuleElem::Type::TYPE: {
                type_ast_for_each(elem.e.type, p);
                break;
            }
            case GenieModule::ModuleElem::Type::DATA: {
                data_ast_for_each(elem.e.data, p);
                break;
            }
            case GenieModule::ModuleElem::Type::BLOCK: {
                block_ast_for_each(elem.e.block, p);
                break;
            }
            case GenieModule::ModuleElem::Type::FUNCTION: {
                function_ast_for_each(elem.e.function, p);
                break;
            }
            case GenieModule::ModuleElem::Type::ASSIGN: {
                assignment_ast_for_each(elem.e.assignment,p);
                break;
            }
            case GenieModule::ModuleElem::Type::RET: {
                ret_ast_for_each(elem.e.ret,p);
                break;
            }
        }
    }

    void ParserInvoker::expr_ast_for_each(GenieExpr expr, AstProcessor& processor) {
        switch (expr.type) {
            case GenieExpr::GenieExprType::INT_TYPE: {
                processor.process_int(expr.e.as_int);
                break;
            }
            case GenieExpr::GenieExprType::REAL_TYPE: {
                processor.process_real(expr.e.as_real);
                break;
            }
            case GenieExpr::GenieExprType::BINARY_TYPE: {
                expr_ast_for_each(expr.e.as_bin->left,processor);
                expr_ast_for_each(expr.e.as_bin->right,processor);
                processor.process_binary(expr.e.as_bin);
                break;
            }
            case GenieExpr::GenieExprType::IDENT_TYPE: {
                processor.process_identifier(expr.e.as_ident);
                break;
            }
            case GenieExpr::GenieExprType::FOR_TYPE: {
                processor.preprocess_for(expr.e.as_for);
                expr_ast_for_each(expr.e.as_for->start,processor);
                processor.postprocess_forstart_preprocess_forend(expr.e.as_for);

                expr_ast_for_each(expr.e.as_for->end,processor);
                processor.postprocess_forend_preprocess_forbody(expr.e.as_for);

                block_ast_for_each(expr.e.as_for->body,processor);
                processor.postprocess_forbody_preprocess_forstep(expr.e.as_for);

                expr_ast_for_each(expr.e.as_for->step,processor);
                processor.process_for(expr.e.as_for);
                break;
            }
            case GenieExpr::GenieExprType::WHILE_TYPE: {
                processor.preprocess_while(expr.e.as_while);
                expr_ast_for_each(expr.e.as_while->cond,processor);
                processor.postprocess_whilecond_preprocess_whilebody(expr.e.as_while);
                block_ast_for_each(expr.e.as_while->body,processor);
                processor.process_while(expr.e.as_while);
                break;
            }
            case GenieExpr::GenieExprType::SWITCH_TYPE: {
                expr_ast_for_each(expr.e.as_switch->cond,processor);

                int i = 0 ;
                processor.postprocess_switchcond_preprocess_all_cases(expr.e.as_switch);
                for (GenieSwitch::GenieCase& cas : expr.e.as_switch->cases) {
                    expr_ast_for_each(cas.guard,processor);

                    processor.postprocess_caseexpr_preprocess_casebody(expr.e.as_switch,i);

                    block_ast_for_each(cas.target,processor);

                    processor.postprocess_casebody_preprcocess_nextcase(expr.e.as_switch,i);
                    i++;
                }

                processor.process_switch(expr.e.as_switch);
                break;
            }
            case GenieExpr::GenieExprType::IFELSE_TYPE: {
                expr_ast_for_each(expr.e.as_ifelse->cond,processor);

                processor.postprocess_ifcond_preprocess_ifthen(expr.e.as_ifelse);
                block_ast_for_each(expr.e.as_ifelse->then,processor);

                processor.postprocess_ifthen_preprocess_ifelse(expr.e.as_ifelse);
                block_ast_for_each(expr.e.as_ifelse->els,processor);

                processor.process_if_else(expr.e.as_ifelse);
                break;
            }
            case GenieExpr::GenieExprType::REPUNTIL_TYPE: {
                processor.preprocess_rep_until(expr.e.as_repuntil);
                block_ast_for_each(expr.e.as_repuntil->body,processor);
                expr_ast_for_each(expr.e.as_repuntil->cond,processor);
                processor.process_rep_until(expr.e.as_repuntil);
                break;
            }
            case GenieExpr::GenieExprType::NONE_TYPE: {
                break;
            }
            case GenieExpr::GenieExprType::FUNCALL_TYPE:
                for(const auto & arg : expr.e.as_funcall->args) {
                    expr_ast_for_each(arg,processor);
                }
                processor.process_funcall(expr.e.as_funcall);
                break;
        }
    }

    void ParserInvoker::type_ast_for_each(GenieType* type, AstProcessor& processor) {
        if (!type) return;
        processor.process_enum(type->t.as_sum);
    }

    void ParserInvoker::data_ast_for_each(GenieData* data, AstProcessor& processor) {
        if (!data) return;
        expr_ast_for_each(data->initializer,processor);
        processor.process_data_declaration(data);
    }

    void ParserInvoker::block_ast_for_each(GenieBlock* block, AstProcessor& processor) {
        if (!block) return;
        processor.process_block(block);
        for(GenieModule::ModuleElem elem : block->elems) {
            dispatch_mod_elem(elem,processor);
        }
        processor.postprocess_block(block);
    }

    void ParserInvoker::function_ast_for_each(GenieFunction* function, AstProcessor& processor) {
        if (!function) return;
        processor.preprocess_function(function);
        block_ast_for_each(function->body,processor);
        processor.process_function(function);
    }

    void ParserInvoker::assignment_ast_for_each(GenieAssign* assign,AstProcessor& processor) {
        expr_ast_for_each(assign->rhs,processor);
        processor.process_assignment(assign);
    }

    void ParserInvoker::ret_ast_for_each(GenieRet* ret, AstProcessor& processor) {
        expr_ast_for_each(ret->e,processor);
        processor.process_ret(ret);
    }
}