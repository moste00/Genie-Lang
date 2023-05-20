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
            std::string type;
            GenieExpr init;

            FunctionParam();
            FunctionParam(const FunctionParam&);
            FunctionParam(const std::string&,const std::string&,GenieExpr);

            void free();
        };
        std::vector<FunctionParam> params;
        std::string ret_type;
        GenieBlock* body;

        GenieFunction(std::string,std::vector<FunctionParam>&,std::string,GenieBlock*);

        void free();
    };
}