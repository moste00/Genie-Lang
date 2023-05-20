#include "SymbolTable.h"

namespace genie {
    SymbolTable::SymbolTable() {
        curr_scope = &global_scope;
    }

    void SymbolTable::enter_new_scope() {
        if (curr_scope->first_child == nullptr) {
            curr_scope->first_child = new Scope();
            curr_scope->first_child->parent = curr_scope;

            curr_scope->curr_child = curr_scope->first_child;
        }
        else if (curr_scope->curr_child->next == nullptr) {
                curr_scope->curr_child->next = new Scope();
                curr_scope->curr_child->next->parent = curr_scope;
                curr_scope->curr_child->next->prev = curr_scope->curr_child;

                curr_scope->curr_child = curr_scope->curr_child->next;
        }
        curr_scope = curr_scope->curr_child;
    }

    void SymbolTable::leave_current_scope() {
        if (curr_scope->parent != nullptr) {
            curr_scope = curr_scope->parent;
        }
    }
    Scope::VarInfo* SymbolTable::lookup_var(const std::string& name) {
        Scope *lookup_scope = curr_scope;
        while (lookup_scope != &global_scope) {
            auto it = lookup_scope->variables.find(name);

            if (it == lookup_scope->variables.end()) {
                lookup_scope = lookup_scope->parent;
            } else {
                return &(it->second);
            }
        }
        auto it = global_scope.variables.find((name));
        if (it != global_scope.variables.end()) return &(it->second);

        return nullptr;
    }

    Scope::FuncInfo* SymbolTable::lookup_fun(const std::string& name) {
        Scope *lookup_scope = curr_scope;
        while (lookup_scope != &global_scope) {
            auto it = lookup_scope->functions.find(name);

            if (it == lookup_scope->functions.end()) {
                lookup_scope = lookup_scope->parent;
            } else {
                return &(it->second);
            }
        }
        auto it = global_scope.functions.find((name));
        if (it != global_scope.functions.end()) return &(it->second);

        return nullptr;
    }

    Scope::EnumInfo* SymbolTable::lookup_enm(const std::string& name) {
        Scope *lookup_scope = curr_scope;
        while (lookup_scope != &global_scope) {
            auto it = lookup_scope->enums.find(name);

            if (it == lookup_scope->enums.end()) {
                lookup_scope = lookup_scope->parent;
            } else {
                return &(it->second);
            }
        }
        auto it = global_scope.enums.find((name));
        if (it != global_scope.enums.end()) return &(it->second);

        return nullptr;
    }

    bool SymbolTable::put_var(const std::string& name,Scope::VarInfo info) {
        auto it = curr_scope->variables.find(name);
        if (it == curr_scope->variables.end()) {
            curr_scope->variables[name] = info;
            return true;
        }
        return false;
    }

    bool SymbolTable::put_fun(const std::string& name,Scope::FuncInfo info) {
        auto it = curr_scope->functions.find(name);
        if (it == curr_scope->functions.end()) {
            curr_scope->functions[name] = info;
            return true;
        }
        return false;
    }

    bool SymbolTable::put_enm(const std::string& name,Scope::EnumInfo info) {
        auto it = curr_scope->enums.find(name);
        if (it == curr_scope->enums.end()) {
            curr_scope->enums[name] = info;
            return true;
        }
        return false;
    }

    void SymbolTable::reset() {
        reset_scope(&global_scope);
    }

    void SymbolTable::reset_scope(Scope* scope) {
        if (scope->first_child == nullptr) {
            return;
        }
        scope->curr_child = scope->first_child;

        Scope* child = scope->first_child;
        while (child != nullptr) {
            reset_scope(child);
            child = child->next;
        }
    }
}