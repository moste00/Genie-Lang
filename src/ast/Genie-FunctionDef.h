#pragma once

#include <string>
#include "Genie-TypeDef.h"
#include "Genie-Expr.h"
#include "Genie-DataDef.h"
namespace genie {
    class GenieBlock;

    struct GenieFunction {
        std::string name;

        struct FunctionParam {
            std::string name;
            GenieData::TypeAnnotation annot;
            GenieExpr init;

            FunctionParam();
            FunctionParam(const FunctionParam&);
            FunctionParam(std::string,GenieData::TypeAnnotation,GenieExpr);
        };
        std::vector<FunctionParam> params;
        GenieBlock* body;

        GenieFunction(std::string,std::vector<FunctionParam>&,GenieBlock*);
    };
}