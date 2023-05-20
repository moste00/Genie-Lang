#include "Genie-Expr.h"
#include "Genie-Block.h"

namespace genie {
    struct GenieWhile {
        GenieExpr cond;
        GenieBlock* body;

        GenieWhile(const GenieExpr&,GenieBlock*);
    };
}