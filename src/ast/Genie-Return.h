#pragma once

#include "Genie-Expr.h"

namespace genie {
    struct GenieRet {
        GenieExpr e;

        GenieRet(GenieExpr);
    };
}