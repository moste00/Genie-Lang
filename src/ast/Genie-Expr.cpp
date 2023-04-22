#include "Genie-Expr.h"
#include "Genie-Binary.h"

namespace genie {
    GenieExpr::GenieExpr(const GenieInt& i) {
        type = GenieExprType::INT_TYPE;
        e.as_int = i;
    }

    GenieExpr::GenieExpr(GenieReal* r) {
        type = GenieExprType::REAL_TYPE;
        e.as_real = r;
    }

    GenieExpr::GenieExpr(GenieBinaryExpr* b) {
        type = GenieExprType::BINARY_TYPE;
        e.as_bin = b;
    }

    GenieExpr::GenieExpr() {
        type = GenieExprType::NONE_TYPE;
        e.as_bin = nullptr;
    }

    void GenieExpr::free() {
        switch (type) {
            case GenieExprType::INT_TYPE: {
                e.as_int.free();
                break;
            }
            case GenieExprType::REAL_TYPE: {
                //TODO add the free call here after adding the method
                break;
            }
            case GenieExprType::BINARY_TYPE: {
                e.as_bin->free();
                break;
            }
        }
    }

    GenieExpr::GenieExpr(const GenieExpr& copy) {
        type = copy.type;
        e = copy.e;
    }

}