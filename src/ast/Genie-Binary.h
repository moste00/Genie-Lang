#pragma once

#include "Genie-Expr.h"

namespace genie {
    struct GenieBinaryExpr {
        enum class GenieBinaryOp {
            PLUS_OP,MINUS_OP,MULT_OP,DIV_OP,MOD_OP,EXP_OP
        };
        GenieBinaryOp op;
        GenieExpr left;
        GenieExpr right;

        GenieBinaryExpr(GenieExpr,GenieExpr,GenieBinaryOp);

        void free();
    };
}