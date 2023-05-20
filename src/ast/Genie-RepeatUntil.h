#include "Genie-Expr.h"
#include "Genie-Block.h"

namespace genie {
    struct GenieRepUntil {
        GenieExpr cond;
        GenieBlock* body;

        GenieRepUntil(const GenieExpr&,GenieBlock*);
    };
}