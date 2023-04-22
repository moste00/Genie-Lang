#include "Genie-Binary.h"

namespace genie {

    GenieBinaryExpr::GenieBinaryExpr(GenieExpr l, GenieExpr r, GenieBinaryExpr::GenieBinaryOp o) {
        left = l;
        right = r;
        op = o;
    }

    void GenieBinaryExpr::free() {
        right.free();
        left.free();
    }
}