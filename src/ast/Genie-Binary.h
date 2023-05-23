#pragma once

#include "Genie-Expr.h"

namespace genie {
    struct GenieBinaryExpr {
        enum class GenieBinaryOp {
            PLUS_OP,MINUS_OP,MULT_OP,DIV_OP,MOD_OP,EXP_OP,
            AND_OP,OR_OP,NOT_OP,EQ_OP,NEQ_OP,LT_OP,GT_OP,LTE_OP,GTE_OP,

            };
        GenieBinaryOp op;
        GenieExpr left;
        GenieExpr right;

        GenieBinaryExpr(const GenieExpr&,const GenieExpr&,GenieBinaryOp);
        GenieBinaryExpr(const GenieExpr&,GenieBinaryOp);
        void free();
    };
}