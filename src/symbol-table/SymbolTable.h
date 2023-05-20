#pragma once

#include "Scope.h"

namespace genie {
    class SymbolTable {
        Scope global_scope;
        Scope* curr_scope;

    public:
        SymbolTable();
        void enter_new_scope();
        void leave_current_scope();
        void reset();

        Scope::VarInfo*  lookup_var(const std::string&);
        Scope::FuncInfo* lookup_fun(const std::string&);
        Scope::EnumInfo* lookup_enm(const std::string&);

        bool put_var(const std::string&,Scope::VarInfo);
        bool put_fun(const std::string&,Scope::FuncInfo);
        bool put_enm(const std::string&,Scope::EnumInfo);

    private:
        static void reset_scope(Scope* scope);
    };
}