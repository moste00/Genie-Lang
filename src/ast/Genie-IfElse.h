#include "Genie-Expr.h"
#include "Genie-Block.h"

namespace genie {
    struct GenieIfElse {
        GenieExpr cond;
        GenieBlock* then;
        GenieBlock* els;

        GenieIfElse(const GenieExpr&,GenieBlock*,GenieBlock*);
    };
}