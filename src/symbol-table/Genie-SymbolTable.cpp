#include <sstream>
#include <stack>
#include "Genie-SymbolTable.h"

namespace genie {
    GenieSymbolTable::GenieSymbolTable() {
        curr_scope = &global_scope;
    }

    void GenieSymbolTable::enter_new_scope() {
        if (curr_scope->first_child == nullptr) {
            curr_scope->first_child = new GenieScope();
            curr_scope->first_child->parent = curr_scope;

            curr_scope->curr_child = curr_scope->first_child;
        }
        else if (curr_scope->curr_child == nullptr) {
            curr_scope->curr_child = curr_scope->first_child;
        }
        else  {
            if (curr_scope->curr_child->next == nullptr) {
                curr_scope->curr_child->next = new GenieScope();
                curr_scope->curr_child->next->parent = curr_scope;
                curr_scope->curr_child->next->prev = curr_scope->curr_child;
            }
                curr_scope->curr_child = curr_scope->curr_child->next;
        }
        curr_scope = curr_scope->curr_child;
    }

    void GenieSymbolTable::leave_current_scope() {
        if (curr_scope->parent != nullptr) {
            curr_scope = curr_scope->parent;
        }
    }
    GenieScope::VarInfo* GenieSymbolTable::lookup_var(const std::string& name) {
        GenieScope *lookup_scope = curr_scope;
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

    GenieScope::FuncInfo* GenieSymbolTable::lookup_fun(const std::string& name) {
        GenieScope *lookup_scope = curr_scope;
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

    GenieScope::EnumInfo* GenieSymbolTable::lookup_enm(const std::string& name) {
        GenieScope *lookup_scope = curr_scope;
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

    bool GenieSymbolTable::put_var(const std::string& name, GenieScope::VarInfo info) {
        auto it = curr_scope->variables.find(name);
        if (it == curr_scope->variables.end()) {
            curr_scope->variables[name] = info;
            notify_observers();
            return true;
        }
        return false;
    }

    bool GenieSymbolTable::put_fun(const std::string& name, GenieScope::FuncInfo info) {
        auto it = curr_scope->functions.find(name);
        if (it == curr_scope->functions.end()) {
            curr_scope->functions[name] = info;
            notify_observers();
            return true;
        }
        return false;
    }

    bool GenieSymbolTable::put_enm(const std::string& name, GenieScope::EnumInfo info) {
        auto it = curr_scope->enums.find(name);
        if (it == curr_scope->enums.end()) {
            curr_scope->enums[name] = info;
            notify_observers();
            return true;
        }
        return false;
    }

    void GenieSymbolTable::reset() {
        reset_scope(&global_scope);
    }

    void GenieSymbolTable::reset_scope(GenieScope* scope) {
        if (scope->first_child == nullptr) {
            return;
        }
        scope->curr_child = nullptr;

        GenieScope* child = scope->first_child;
        while (child != nullptr) {
            reset_scope(child);
            child = child->next;
        }
    }

    bool GenieSymbolTable::current_scope_is_global_scope() {
        return curr_scope == &global_scope;
    }

    std::string GenieSymbolTable::serialize_to_dot(std::string graph_name) {
        return serialize_scope_to_dot(graph_name,&global_scope);
    }

    std::string GenieSymbolTable::serialize_scope_to_dot(std::string graph_name,GenieScope* s) {
        std::unordered_map<GenieScope*,std::string> dot_descriptions;

        std::stack<GenieScope*> unprocessed_scopes;
        unprocessed_scopes.push(s);

        while (!unprocessed_scopes.empty()) {
            auto scope = unprocessed_scopes.top();
            unprocessed_scopes.pop();

            std::stringstream dot;

            dot << '"';
            for (const auto &it: scope->variables) {
                dot << ((it.second.is_mutable) ? "var" : "val") << " ";
                dot << it.first;
                if (!it.second.additional_info.empty()) {
                    dot << " | Additional Info :";
                    for (auto additional_info: it.second.additional_info) {
                        dot << additional_info->serialize() << " -- ";
                    }
                }
                dot << "\n";
            }
            dot << '"';

            GenieScope* child = scope->first_child;
            while (child != nullptr) {
                unprocessed_scopes.push(child);
                child = child->next;
            }

            dot_descriptions[scope] = dot.str();
        }

        std::stringstream dot;
        dot << "digraph " << graph_name << " {";
        dot << "\n label="<<'"'<<graph_name<<'"'<<";\n";
        unprocessed_scopes.push(s);
        while (!unprocessed_scopes.empty()) {
            GenieScope* scope = unprocessed_scopes.top();
            unprocessed_scopes.pop();

            std::string dot_description = dot_descriptions[scope];
            dot << dot_description << "\n";
            GenieScope* child = scope->first_child;
            while (child != nullptr) {
                unprocessed_scopes.push(child);
                std::string child_dot_description = dot_descriptions[child];
                if (child_dot_description != "\"\"") {
                    dot << dot_description << " -> " << child_dot_description << "\n";
                }
                child = child->next;
            }
        }
        dot << "\n}";
        return dot.str();
    }

    void GenieSymbolTable::on_every_change(std::function<void(GenieSymbolTable *)> f) {
        change_obvservers.push_back(f);
    }

    void GenieSymbolTable::notify_observers() {
        for (const auto &ob : change_obvservers) {
            ob(this);
        }
    }
}