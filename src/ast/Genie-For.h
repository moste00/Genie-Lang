#pragma once

#include "Genie-Block.h"
#include "Genie-Expr.h"

namespace genie {
    struct GenieFor {
        GenieExpr start;
        GenieExpr end;
        GenieExpr step;
        GenieBlock* body;

        GenieFor(const GenieExpr&,const GenieExpr&, const GenieExpr&,GenieBlock*);
    };
}