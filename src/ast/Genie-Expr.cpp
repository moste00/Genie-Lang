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
                delete e.as_bin;
                break;
            }
            case GenieExprType::IDENT_TYPE:
                break;
            case GenieExprType::FOR_TYPE:
                break;
            case GenieExprType::WHILE_TYPE:
                break;
            case GenieExprType::SWITCH_TYPE:
                break;
            case GenieExprType::IFELSE_TYPE:
                break;
            case GenieExprType::REPUNTIL_TYPE:
                break;
            case GenieExprType::NONE_TYPE:
                break;
        }
    }

    GenieExpr::GenieExpr(const GenieExpr& copy) {
        type = copy.type;
        e = copy.e;
    }

    GenieExpr::GenieExpr(const string& id) {
        type = GenieExprType::IDENT_TYPE;
        e.as_ident = new std::string(id);
    }

    GenieExpr::GenieExpr(GenieFor* loop) {
        type = GenieExprType::FOR_TYPE;
        e.as_for = loop;
    }

    GenieExpr::GenieExpr(GenieWhile* loop) {
        type = GenieExprType::WHILE_TYPE;
        e.as_while = loop;
    }

    GenieExpr::GenieExpr(GenieSwitch* switsh) {
        type = GenieExprType::SWITCH_TYPE;
        e.as_switch = switsh;
    }

    GenieExpr::GenieExpr(GenieIfElse* ifels) {
        type=  GenieExprType::IFELSE_TYPE;
        e.as_ifelse = ifels;
    }

    GenieExpr::GenieExpr(GenieRepUntil* loop) {
        type = GenieExprType::REPUNTIL_TYPE;
        e.as_repuntil = loop;
    }

    GenieExpr::GenieExpr(GenieFunCall* funcall) {
        type = GenieExprType::FUNCALL_TYPE;
        e.as_funcall = funcall;
    }
}