#pragma once

#include "../ast/Genie-Ast.hpp"
#include <vector>
using std::vector;

namespace genie {
    template<typename T>
    struct AstWalker {
        virtual T walk_program(GenieProgram*) = 0;

        virtual T walk_module(GenieModule*) = 0;
        virtual T walk_simple_module(vector<GenieModule::ModuleElem>*) = 0;
        virtual T walk_compound_module(vector<GenieModule*>*) = 0;

        virtual T walk_module_element(GenieModule::ModuleElem*) = 0;
        virtual T walk_expr_module_element(GenieExpr) = 0;
        virtual T walk_type_module_element(GenieType*) = 0;
        virtual T walk_data_module_element(GenieData*) = 0;
        virtual T walk_block_module_element(GenieBlock*) = 0;
        virtual T walk_function_module_element(GenieFunction*) = 0;

        virtual T walk_int_expr(GenieInt) = 0;
        virtual T walk_real_expr(GenieReal*) = 0;
        virtual T walk_binary_expr(GenieBinaryExpr*) = 0;
        virtual T walk_absent_expr() = 0;

        virtual T walk_sum_type(GenieType::SumType*) = 0;

        virtual T walk_def_type_annotation(GenieType*) = 0;
        virtual T walk_ref_type_annotation(string*) = 0;
        virtual T walk_absent_type_annotation() = 0;
        virtual T walk_data_init_expr(GenieExpr) = 0;

        virtual T walk_block_element(GenieModule::ModuleElem*) = 0;
        virtual T walk_expr_block_element(GenieExpr) = 0;
        virtual T walk_type_block_element(GenieType*) = 0;
        virtual T walk_data_block_element(GenieData*) = 0;
        virtual T walk_block_block_element(GenieBlock*) = 0;
        virtual T walk_function_block_element(GenieFunction*) = 0;

        virtual T walk_function_param(GenieFunction::FunctionParam*) = 0;
        virtual T walk_function_param_init_expr(GenieExpr) = 0;
        virtual T walk_function_body(GenieBlock*) = 0;
    };

    struct DefaultVoidAstWalker : public AstWalker<void> {
        void walk_program(GenieProgram* program) override {}

        void walk_module(GenieModule* aModule) override {}

        void walk_simple_module(vector<GenieModule::ModuleElem>* vector) override {}

        void walk_compound_module(vector<GenieModule*>* vector) override {}

        void walk_module_element(GenieModule::ModuleElem* elem) override {}

        void walk_expr_module_element(GenieExpr expr) override {}

        void walk_type_module_element(GenieType* type) override {}

        void walk_data_module_element(GenieData* data) override {}

        void walk_block_module_element(GenieBlock* block) override {}

        void walk_function_module_element(GenieFunction* function) override {}

        void walk_int_expr(GenieInt anInt) override {}

        void walk_real_expr(GenieReal* real) override {}

        void walk_binary_expr(GenieBinaryExpr* expr) override {}

        void walk_sum_type(GenieType::SumType* type) override {}

        void walk_def_type_annotation(GenieType* type) override {}

        void walk_ref_type_annotation(string* string1) override {}

        void walk_data_init_expr(GenieExpr expr) override {}

        void walk_block_element(GenieModule::ModuleElem* elem) override {}

        void walk_expr_block_element(GenieExpr expr) override {}

        void walk_type_block_element(GenieType* type) override {}

        void walk_data_block_element(GenieData* data) override {}

        void walk_block_block_element(GenieBlock* block) override {}

        void walk_function_block_element(GenieFunction* function) override {}

        void walk_function_param(GenieFunction::FunctionParam* param) override {}

        void walk_function_param_init_expr(GenieExpr expr) override {}

        void walk_function_body(GenieBlock* block) override {}

        void walk_absent_expr() override {}

        void walk_absent_type_annotation() override {}
    };
}