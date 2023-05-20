#pragma once

#include "Genie-Expr.h"

namespace genie {
    struct GenieAssign {
        std::string lhs;
        GenieExpr rhs;

        GenieAssign(std::string,GenieExpr);
    };
}