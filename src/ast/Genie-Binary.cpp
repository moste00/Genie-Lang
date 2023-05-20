#include "Genie-Binary.h"

namespace genie {
    GenieBinaryExpr::GenieBinaryExpr(const GenieExpr& l, const GenieExpr& r, GenieBinaryExpr::GenieBinaryOp o) {
        left = l;
        right = r;
        op = o;
    }
    GenieBinaryExpr::GenieBinaryExpr(const GenieExpr& l, GenieBinaryExpr::GenieBinaryOp o) {
        left = l;
        op = o;
    }

    void GenieBinaryExpr::free() {
        right.free();
        left.free();
    }


}