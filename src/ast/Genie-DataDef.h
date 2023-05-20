#pragma once

#include <string>
#include "Genie-Expr.h"
#include "Genie-TypeDef.h"

namespace genie {
    struct GenieData {
        enum class MutabilitySpecifier {
            VAL,VAR
        };
        MutabilitySpecifier mut_spec;

        std::string name;


        std::string type;

        GenieExpr initializer;

        GenieData(MutabilitySpecifier,const std::string&, const std::string&, const GenieExpr&);

        void free();
    };
}