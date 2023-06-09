#pragma once

#include "Genie-Block.h"
#include "Genie-Expr.h"

namespace genie {
    struct GenieFor {
        std::string var;
        GenieExpr start;
        GenieExpr end;
        GenieExpr step;
        GenieBlock* body;

        GenieFor(const std::string&,const GenieExpr&,const GenieExpr&, const GenieExpr&,GenieBlock*);
    };
}