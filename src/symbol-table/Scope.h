#pragma once

#include "../ast/Genie-FunctionDef.h"
#include <unordered_map>
#include <string>
#include <vector>

namespace genie {
    struct Scope {
        struct AdditionalInfo {};

        struct FuncInfo {
            GenieFunction* func;
        };
        struct EnumInfo {
            GenieType* enm;
        };
        struct VarInfo {
            bool is_mutable;
            std::vector<AdditionalInfo*> additional_info;
        };

        std::unordered_map<std::string, VarInfo> variables;
        std::unordered_map<std::string, FuncInfo> functions;
        std::unordered_map<std::string, EnumInfo> enums;

        Scope* parent;
        Scope* prev;
        Scope* next;
        Scope* first_child;

        //for iteration
        Scope* curr_child;
        Scope() {
            parent = nullptr;
            prev = nullptr;
            next = nullptr;
            first_child = nullptr;
            curr_child = nullptr;
        }
    };
}