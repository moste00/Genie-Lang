#pragma once

#include "Genie-Expr.h"

namespace genie {
    struct GenieFunCall {
        std::string fun_name;
        std::vector<GenieExpr> args;

        GenieFunCall(std::string, const std::vector<GenieExpr>&);
    };
}