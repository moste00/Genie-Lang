#pragma once

#include "../parser-invoker/Genie-AstWalker.h"

namespace genie {
    struct JsonAstPrinter : DefaultVoidAstWalker {
        void walk_program(GenieProgram *program) override;

        void walk_simple_module(vector<GenieModule::ModuleElem> *vector) override;

        void walk_compound_module(vector<GenieModule *> *vector) override;

        void walk_int_expr(GenieInt anInt) override;

        void walk_real_expr(GenieReal *real) override;

        void walk_binary_expr(GenieBinaryExpr *expr) override;

        void walk_block_module_element(GenieBlock *block) override;

        void walk_block_block_element(GenieBlock *block) override;

    };
}