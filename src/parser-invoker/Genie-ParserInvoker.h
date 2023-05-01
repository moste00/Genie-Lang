#pragma once

#include "../ast/Genie-Program.h"
#include "Genie-AstWalker.h"
namespace genie {
    //The ParserInvoker encapsulates the details of calling a concrete parser and returning an AST
    //The ParserInvoker also owns the resulting AST object and is responsible for freeing it
    //No other modules of the Genie toolchain should know anything about parsing or where the AST comes from,
    // the only thing they ever need to know is that they can call a parser invoker to get an AST,
    // and that this parser invoker needs to stay in scope as long as the AST is in use
    class ParserInvoker {
    protected:
        GenieProgram prog;
    public:
        virtual void add_file(const std::string&) = 0;
        virtual void add_string(const std::string&) = 0;

        template<typename T>
        void run_ast_walker(const AstWalker<T>&);

        virtual ~ParserInvoker() {
            prog.free();
        }
    private:
        template<typename T>
        void run_ast_walker_module(const AstWalker<T>&, GenieModule*);

        template<typename T>
        void run_ast_walker_expr(const AstWalker<T>&, const GenieExpr&);

        template<typename T>
        void run_ast_walker_type(const AstWalker<T>&, GenieType*);

        template<typename T>
        void run_ast_walker_data(const AstWalker<T>&, GenieData*);

        template<typename T>
        void run_ast_walker_block(const AstWalker<T>&, GenieBlock*);

        template<typename T>
        void run_ast_walker_function(const AstWalker<T>&, GenieFunction*);
    };

    template<typename T>
    void ParserInvoker::run_ast_walker(const AstWalker<T>& walker) {
        walker.walk_program(&prog);

        for (GenieModule* mod : prog.modules) {
            walker.walk_module(mod);

            run_ast_walker_module(walker,mod);
        }
    }

    template<typename T>
    void ParserInvoker::run_ast_walker_module(const AstWalker<T>& walker, GenieModule* mod) {
        if (mod->content.t == GenieModule::Type::COMPOUND_MODULE) {
            walker.walk_compound_module(&(mod->content.c.files));

            for (GenieModule* m : mod->content.c.files) {
                run_ast_walker_module(walker,m);
            }
        }
        else {
            walker.walk_simple_module(&(mod->content.c.elems));

            for (GenieModule::ModuleElem mod_elem: mod->content.c.elems) {
                walker.walk_module_element(&mod_elem);

                switch (mod_elem.t) {
                    case GenieModule::ModuleElem::Type::EXPR: {
                        walker.walk_expr_module_element(mod_elem.e.expr);
                        run_ast_walker_expr(walker, mod_elem.e.expr);
                        break;
                    }
                    case GenieModule::ModuleElem::Type::TYPE: {
                        walker.walk_type_module_element(mod_elem.e.type);
                        run_ast_walker_type(walker, mod_elem.e.type);
                        break;
                    }
                    case GenieModule::ModuleElem::Type::DATA: {
                        walker.walk_data_module_element(mod_elem.e.data);
                        run_ast_walker_data(walker, mod_elem.e.data);
                        break;
                    }
                    case GenieModule::ModuleElem::Type::BLOCK: {
                        walker.walk_block_module_element(mod_elem.e.block);
                        run_ast_walker_block(walker, mod_elem.e.block);
                        break;
                    }
                    case GenieModule::ModuleElem::Type::FUNCTION: {
                        walker.walk_function_module_element(mod_elem.e.function);
                        run_ast_walker_function(walker,mod_elem.e.function);
                        break;
                    }
                }
            }
        }
    }

    template<typename T>
    void ParserInvoker::run_ast_walker_expr(const AstWalker<T>& walker,const GenieExpr& expr) {
        switch (expr.type) {
            case GenieExpr::GenieExprType::INT_TYPE: {
                walker.walk_int_expr(expr.e.as_int);
                break;
            }
            case GenieExpr::GenieExprType::REAL_TYPE: {
                walker.walk_real_expr(expr.e.as_real);
                break;
            }
            case GenieExpr::GenieExprType::BINARY_TYPE: {
                walker.walk_binary_expr(expr.e.as_bin);
                break;
            }
            case GenieExpr::GenieExprType::NONE_TYPE: {
                walker.walk_absent_expr();
                break;
            }
        }
    }

    template<typename T>
    void ParserInvoker::run_ast_walker_function(const AstWalker<T>& walker, GenieFunction* function) {
        for (GenieFunction::FunctionParam param : function->params) {
            walker.walk_function_param(param);

            walker.walk_function_param_init_expr(param.init);
            run_ast_walker_expr(walker,param.init);
        }

        walker.walk_function_body(function->body);
    }

    template<typename T>
    void ParserInvoker::run_ast_walker_block(const AstWalker<T>& walker, GenieBlock* block) {
        for (GenieModule::ModuleElem elem : block->elems) {
            walker.walk_block_element(&elem);

            switch (elem.t) {
                case GenieModule::ModuleElem::Type::EXPR: {
                    walker.walk_expr_block_element(elem.e.expr);
                    run_ast_walker_expr(walker,elem.e.expr);
                    break;
                }
                case GenieModule::ModuleElem::Type::TYPE: {
                    walker.walk_type_block_element(elem.e.type);
                    run_ast_walker_type(walker,elem.e.type);
                    break;
                }
                case GenieModule::ModuleElem::Type::DATA: {
                    walker.walk_data_block_element(elem.e.data);
                    run_ast_walker_data(walker,elem.e.data);
                    break;
                }
                case GenieModule::ModuleElem::Type::BLOCK: {
                    walker.walk_block_block_element(elem.e.block);
                    run_ast_walker_block(walker,elem.e.block);
                    break;
                }
                case GenieModule::ModuleElem::Type::FUNCTION: {
                    walker.walk_function_block_element(elem.e.function);
                    run_ast_walker_function(walker,elem.e.function);
                    break;
                }
            }
        }
    }

    template<typename T>
    void ParserInvoker::run_ast_walker_data(const AstWalker<T>& walker, GenieData* data) {
        walker.walk_data_type_annotation(&(data->type));

        walker.walk_data_init_expr(data->initializer);
        run_ast_walker_expr(walker,data->initializer);
    }

    template<typename T>
    void ParserInvoker::run_ast_walker_type(const AstWalker<T>& walker, GenieType* type) {
        walker.walk_sum_type(type->t.as_sum);
    }
}