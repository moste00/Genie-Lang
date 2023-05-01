#pragma once

#include "Genie-Int.h"
#include "Genie-Real.h"
//no include for Genie-Binary, because it needs to include us and that will create a circular dependency
namespace genie {
    class GenieBinaryExpr;

    struct GenieExpr {
        enum class GenieExprType {
            INT_TYPE,REAL_TYPE,BINARY_TYPE,IDENT_TYPE,NONE_TYPE
        };
        GenieExprType type;

        union _ {
            GenieInt as_int;
            GenieReal* as_real;
            GenieBinaryExpr* as_bin;
            std::string* as_ident;
            _(){}
            ~_(){}
        } e;

        GenieExpr();
        GenieExpr(const GenieExpr&);
        GenieExpr(const GenieInt&);
        GenieExpr(GenieReal*);
        GenieExpr(GenieBinaryExpr*);
        GenieExpr(const std::string&);

        void free();
    };
}