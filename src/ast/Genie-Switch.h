#include "Genie-Expr.h"
#include "Genie-Block.h"

#include <vector>
using std::vector;

namespace genie {
    struct GenieSwitch {
        struct GenieCase {
            GenieExpr guard;
            GenieBlock* target;

            GenieCase(const GenieExpr&,GenieBlock*);
            GenieCase();
        };
        GenieExpr cond;
        vector<GenieCase> cases;

        GenieSwitch(const GenieExpr&,const vector<GenieCase>&);
    };
}