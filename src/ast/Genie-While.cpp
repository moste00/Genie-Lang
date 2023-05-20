#include "Genie-While.h"

namespace genie {
    GenieWhile::GenieWhile(const genie::GenieExpr& e, genie::GenieBlock* b) {
        cond = e;
        body = b;
    }
}
