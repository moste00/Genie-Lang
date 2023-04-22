#pragma once

#include <vector>

#include "Genie-Expr.h"
#include "Genie-DataDef.h"
#include "Genie-FunctionDef.h"
#include "Genie-TypeDef.h"
//no include for Genie-Block, it needs to include us so we can't circularly include it
namespace genie {
    class GenieBlock;

    struct GenieModule {
        struct ModuleElem {
            enum class Type {EXPR,TYPE,DATA,BLOCK,FUNCTION};
            Type t;
            union _ {
                GenieExpr expr;
                GenieType* type;
                GenieData* data;
                GenieBlock* block;
                GenieFunction* function;

                _(){}
                ~_(){}
            } e;
            ModuleElem();
            ModuleElem(const ModuleElem&);
            ModuleElem(GenieExpr);
            ModuleElem(GenieType*);
            ModuleElem(GenieData*);
            ModuleElem(GenieBlock*);
            ModuleElem(GenieFunction*);
        };

        enum class Type {SIMPLE_MODULE,COMPOUND_MODULE};
        struct ModuleContent {
            Type t;
            union _ {
                std::vector<ModuleElem> elems;
                std::vector<GenieModule*> files;

                _(std::vector<ModuleElem>&);
                _(std::vector<GenieModule*>&);
                ~_(){}
            } c;
            ModuleContent(std::vector<ModuleElem>&);
            ModuleContent(std::vector<GenieModule*>&);
        };
        ModuleContent content;

        GenieModule(std::vector<ModuleElem>&);
        GenieModule(std::vector<GenieModule*>&);
    };
}