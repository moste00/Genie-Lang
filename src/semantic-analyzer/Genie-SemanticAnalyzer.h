#pragma once
#include "../parser-invoker/Genie-AstProcessor.h"
#include "../symbol-table/Genie-SymbolTable.h"
#include <iostream>
#include <sstream>
#include <stack>

namespace genie {
    class GenieSemanticAnalyzer : public AstProcessor {

        struct VarType : public GenieScope::AdditionalInfo {
            std::string type;

            VarType(std::string t) : type(std::move(t)) {}

            std::string serialize() override {
                return "Type="+type;
            }
        };
        std::stack<std::string> types;
        GenieSymbolTable symbol_table;
        std::stringstream type_errors;
        std::stringstream scope_errors;
    public:
        GenieSemanticAnalyzer();

        GenieSymbolTable* symbols();

        std::string type_errs();
        std::string scope_errs();
        std::string all_errs();
        bool ok();

        void whenever_symbol_table_changes(std::function<void(GenieSymbolTable*)>);
    };
}