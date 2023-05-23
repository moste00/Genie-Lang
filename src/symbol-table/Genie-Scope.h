#pragma once

#include "../ast/Genie-FunctionDef.h"
#include <unordered_map>
#include <string>
#include <vector>

namespace genie {
    struct GenieScope {
        struct AdditionalInfo { virtual std::string serialize() = 0; };

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

        GenieScope* parent;
        GenieScope* prev;
        GenieScope* next;
        GenieScope* first_child;

        //for iteration
        GenieScope* curr_child;

        GenieScope() {
            parent = nullptr;
            prev = nullptr;
            next = nullptr;
            first_child = nullptr;
            curr_child = nullptr;
        }
    };
}