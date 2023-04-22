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

        struct TypeAnnotation {
            enum class TypeType {REF,DEF,NONE};
            union _ {
                GenieType* typdef;
                std::string typref;
                _(GenieType*);
                _(std::string);
                _(){}
                ~_(){}
            } ref_or_def;
            TypeType typ;

            TypeAnnotation();
            TypeAnnotation(std::string);
            TypeAnnotation(GenieType*);
            TypeAnnotation(const TypeAnnotation&);
            TypeAnnotation& operator=(const TypeAnnotation&);
        };
        TypeAnnotation type;

        GenieExpr initializer;

        GenieData(MutabilitySpecifier, std::string, const TypeAnnotation&, GenieExpr);
    };
}