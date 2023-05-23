#pragma once

#include <functional>
#include "Genie-Scope.h"

namespace genie {
    class GenieSymbolTable {
        GenieScope global_scope;
        GenieScope* curr_scope;

        std::vector<std::function<void(GenieSymbolTable*)>> change_obvservers;
    public:
        GenieSymbolTable();
        void enter_new_scope();
        void leave_current_scope();
        void reset();

        GenieScope::VarInfo*  lookup_var(const std::string&);
        GenieScope::FuncInfo* lookup_fun(const std::string&);
        GenieScope::EnumInfo* lookup_enm(const std::string&);

        bool put_var(const std::string&, GenieScope::VarInfo);
        bool put_fun(const std::string&, GenieScope::FuncInfo);
        bool put_enm(const std::string&, GenieScope::EnumInfo);

        bool current_scope_is_global_scope();

        std::string serialize_to_dot(std::string);

        void on_every_change(std::function<void(GenieSymbolTable*)>);
    private:
        static void reset_scope(GenieScope* scope);
        static std::string serialize_scope_to_dot(std::string,GenieScope*);

        void notify_observers();
    };
}