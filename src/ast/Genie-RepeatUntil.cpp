#include "Genie-RepeatUntil.h"

namespace genie {

    GenieRepUntil::GenieRepUntil(const GenieExpr& e, GenieBlock* b) {
        cond = e;
        body = b;
    }
}