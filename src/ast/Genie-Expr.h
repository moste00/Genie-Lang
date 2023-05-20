#pragma once

#include <vector>
#include "Genie-Int.h"
#include "Genie-Real.h"
//no include for all of this, because they need to include us and that will create a circular dependency
//we will simpy forward-declare them, and thus we will only be able to use them as pointers
//#include "Genie-Binary.h"
//#include "Genie-IfElse.h"
//#include "Genie-For.h"
//#include "Genie-FunctionCall.h"
//#include "Genie-RepeatUntil.h"
//#include "Genie-While.h"
//#include "Genie-Switch.h"
//#include "Genie-FunctionCall.h"
namespace genie {
    class GenieBinaryExpr;
    class GenieFor;
    class GenieWhile;
    class GenieIfElse;
    class GenieRepUntil;
    class GenieSwitch;
    class GenieFunCall;
    struct GenieExpr {
        enum class GenieExprType {
            INT_TYPE,REAL_TYPE,BINARY_TYPE,
            IDENT_TYPE,
            FOR_TYPE,WHILE_TYPE,SWITCH_TYPE,IFELSE_TYPE,REPUNTIL_TYPE, FUNCALL_TYPE,
            NONE_TYPE
        };
        GenieExprType type;

        union _ {
            GenieInt as_int;
            GenieReal* as_real;
            GenieBinaryExpr* as_bin;

            std::string* as_ident;

            GenieFor* as_for;
            GenieWhile* as_while;
            GenieSwitch* as_switch;
            GenieIfElse* as_ifelse;
            GenieRepUntil* as_repuntil;
            GenieFunCall*  as_funcall;
            _(){}
            ~_(){}
        } e;

        GenieExpr();
        GenieExpr(const GenieExpr&);
        GenieExpr(const GenieInt&);
        GenieExpr(GenieReal*);
        GenieExpr(GenieBinaryExpr*);
        GenieExpr(const std::string&);
        GenieExpr(GenieFor*);
        GenieExpr(GenieWhile*);
        GenieExpr(GenieSwitch*);
        GenieExpr(GenieIfElse*);
        GenieExpr(GenieRepUntil*);
        GenieExpr(GenieFunCall*);
        void free();
    };
}