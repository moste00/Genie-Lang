
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
                expr_ast_for_each(expr.e.as_for->start,processor);
                expr_ast_for_each(expr.e.as_for->end,processor);
                expr_ast_for_each(expr.e.as_for->step,processor);
                block_ast_for_each(expr.e.as_for->body,processor);
                processor.process_for(expr.e.as_for);
                break;
            }
            case GenieExpr::GenieExprType::WHILE_TYPE: {
                expr_ast_for_each(expr.e.as_while->cond,processor);
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
                block_ast_for_each(expr.e.as_repuntil->body,processor);
                expr_ast_for_each(expr.e.as_repuntil->cond,processor);
                processor.process_rep_until(expr.e.as_repuntil);
                break;
            }
            case GenieExpr::GenieExprType::NONE_TYPE: {
                break;
            }
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
        for(GenieModule::ModuleElem elem : block->elems) {
            dispatch_mod_elem(elem,processor);
        }
    }

    void ParserInvoker::function_ast_for_each(GenieFunction* function, AstProcessor& processor) {
        if (!function) return;
        block_ast_for_each(function->body,processor);
        processor.process_function(function);
    }
}