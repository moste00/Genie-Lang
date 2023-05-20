#include "Genie-IfElse.h"

namespace genie {
    GenieIfElse::GenieIfElse(const genie::GenieExpr& c, GenieBlock* thn,GenieBlock* el) {
        cond = c;
        then = thn;
        els  = el;
    }
}
