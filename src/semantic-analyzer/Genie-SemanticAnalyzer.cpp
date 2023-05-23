#include "Genie-SemanticAnalyzer.h"

#include <utility>

namespace genie {
    GenieSemanticAnalyzer::GenieSemanticAnalyzer() {
        process_block = [this](GenieBlock* block) {
            symbol_table.enter_new_scope();
        };
        postprocess_block = [this](GenieBlock* block) {
            symbol_table.leave_current_scope();
        };

        process_data_declaration = [this](GenieData* decl) {
            GenieScope::VarInfo info;
            info.is_mutable = decl->mut_spec == GenieData::MutabilitySpecifier::VAR;

            if (decl->initializer.type != GenieExpr::GenieExprType::NONE_TYPE) {
                std::string inferred_type = types.top(); types.pop();

                if (decl->type.empty()) decl->type = inferred_type;
                else {
                    if (decl->type != inferred_type) {
                        type_errors << "Type Error : variable " << decl->name << " has declared type " << decl->type
                                    << " but is initialized with expression of type " << inferred_type << "\n";
                        decl->type = "!!!INVALID!!!";
                    }
                }
            }
            else {
                if (decl->type.empty()) {
                    type_errors << "Type Error : variable " << decl->name << " has no declared type and no initializer (so no inferred type).";
                    type_errors << "Variables must have at least one of the following : a declared type, and an initializer.\n";
                    decl->type = "!!!INVALID!!!";
                }
            }
            info.additional_info.push_back(new VarType(decl->type));
            symbol_table.put_var(decl->name,info);
        };
        
        process_int = [this](GenieInt i) {
            types.emplace("int");
        };
        process_real = [this](GenieReal* r) {
            types.emplace("real");
        };
        process_binary = [this](GenieBinaryExpr* b) {
            std::string right_type = types.top(); types.pop();
            std::string left_type = types.top(); types.pop();
            switch (b->op) {
                case GenieBinaryExpr::GenieBinaryOp::PLUS_OP:
                case GenieBinaryExpr::GenieBinaryOp::MINUS_OP:
                case GenieBinaryExpr::GenieBinaryOp::MULT_OP:
                case GenieBinaryExpr::GenieBinaryOp::DIV_OP:
                case GenieBinaryExpr::GenieBinaryOp::MOD_OP:
                case GenieBinaryExpr::GenieBinaryOp::EXP_OP: {
                    if (left_type == "real" && right_type == "real") {
                        types.emplace("real");
                    } else if (left_type == "int" && right_type == "int") {
                        types.emplace("int");
                    } else {
                        type_errors << "Type Error : Arithmetic Operator '"
                                    << ((b->op == GenieBinaryExpr::GenieBinaryOp::PLUS_OP ) ? "+" :
                                        (b->op == GenieBinaryExpr::GenieBinaryOp::MINUS_OP) ? "+" :
                                        (b->op == GenieBinaryExpr::GenieBinaryOp::MULT_OP ) ? "*" :
                                        (b->op == GenieBinaryExpr::GenieBinaryOp::DIV_OP  ) ? "/" :
                                        (b->op == GenieBinaryExpr::GenieBinaryOp::MOD_OP  ) ? "%" : "**");
                        if (left_type != right_type) {
                           type_errors << "' can't operate on mixed arguments.";
                        }
                        else {
                            type_errors << "' can't operate on non-integer or non-real arguments.";
                        }
                        type_errors << " Left argument's type is " << left_type
                                    << " while right argument's type is " << right_type << "\n";
                        types.emplace("!!!INVALID!!!");
                    }
                }
                    break;

                case GenieBinaryExpr::GenieBinaryOp::AND_OP:
                case GenieBinaryExpr::GenieBinaryOp::OR_OP:
                case GenieBinaryExpr::GenieBinaryOp::NOT_OP: {
                    if (left_type == "bool" && right_type == "bool") {
                        types.emplace("bool");
                    } else {
                        type_errors << "Type Error : One or both of the arguments for boolean operator"
                                    << ((b->op == GenieBinaryExpr::GenieBinaryOp::AND_OP) ? "and":
                                        (b->op == GenieBinaryExpr::GenieBinaryOp::OR_OP ) ? "or" :"not");
                        type_errors << " is not of boolean type.";
                        type_errors << " Left argument's type is " << left_type
                                    << " while right argument's type is " << right_type << "\n";
                        types.emplace("!!!INVALID!!!");
                    }
                }
                    break;

                case GenieBinaryExpr::GenieBinaryOp::EQ_OP:
                case GenieBinaryExpr::GenieBinaryOp::NEQ_OP:
                case GenieBinaryExpr::GenieBinaryOp::LT_OP:
                case GenieBinaryExpr::GenieBinaryOp::GT_OP:
                case GenieBinaryExpr::GenieBinaryOp::LTE_OP:
                case GenieBinaryExpr::GenieBinaryOp::GTE_OP: {
                    if ((left_type == "int"  || left_type == "real")
                    &&  (right_type == "int" || right_type == "real")) {
                        types.emplace("bool");
                    }
                    else {
                        type_errors << "Type Error : One or both of the arguments for the comparison operator "
                                    << ((b->op == GenieBinaryExpr::GenieBinaryOp::EQ_OP ) ? "is" :
                                        (b->op == GenieBinaryExpr::GenieBinaryOp::NEQ_OP) ? "~is" :
                                        (b->op == GenieBinaryExpr::GenieBinaryOp::LT_OP ) ? "<" :
                                        (b->op == GenieBinaryExpr::GenieBinaryOp::GT_OP ) ? ">" :
                                        (b->op == GenieBinaryExpr::GenieBinaryOp::LTE_OP) ? "<=" : ">=");
                        type_errors << " is neither an int nor a real. The 2 arguments of a comparison operator must be either ints or reals (mixed types are okay).";
                        type_errors << " is not of boolean type.";
                        type_errors << " Left argument's type is " << left_type
                                    << " while right argument's type is " << right_type << "\n";
                        types.emplace("!!!INVALID!!!");
                    }
                }
                    break;
            }
        };
        process_identifier = [this](std::string* id) {
            GenieScope::VarInfo* inf = symbol_table.lookup_var(*id);
            if (inf == nullptr) {
                    scope_errors << "Variable "<<*id<<" is never declared or not in scope.";
                    types.emplace("!!!INVALID!!!");
            } else {
                auto x = dynamic_cast<VarType*>(inf->additional_info[inf->additional_info.size()-1]);
                types.emplace(x->type);
            }
        };

        postprocess_ifcond_preprocess_ifthen = [this](GenieIfElse* ifelse) {
            if (types.top() != "bool") {
                type_errors << "Type Error : If's condition must have type bool, instead found type "<<types.top();
            }
            types.pop();
        };

        process_assignment = [this](GenieAssign* assign) {
            GenieScope::VarInfo* inf = symbol_table.lookup_var(assign->lhs);
            if (inf == nullptr) {
                scope_errors<<"Scope Error : Variable "<<assign->lhs<<" was never defined.\n";
            }
            else {
                VarType* type = dynamic_cast<VarType*>(inf->additional_info[inf->additional_info.size()-1]);
                if (types.top() == type->type) {
                    types.pop();
                }
                else {
                    type_errors<<"Type Error : Variable "<<assign->lhs<<" of type "<<type->type<<" is assigned an expression of type "<<types.top()<<".\n";
                }
            }
        };
        preprocess_for = [this](GenieFor* forr) {
            symbol_table.enter_new_scope();
            GenieScope::VarInfo inf;
            inf.is_mutable = true;
            inf.additional_info.push_back(new VarType("int"));
            symbol_table.put_var(forr->var,inf);
        };

        preprocess_function = [this](GenieFunction* f) {
            GenieScope::FuncInfo inf{};
            inf.func = f;
            symbol_table.put_fun(f->name,inf);
            symbol_table.enter_new_scope();

            for (auto& param : f->params) {
                GenieScope::VarInfo info;
                info.is_mutable = false;
                if (!param.type.empty()) info.additional_info.push_back((new VarType(param.type)));

                symbol_table.put_var(param.name,info);
            }
        };
        process_function = [this](GenieFunction* f) {
            symbol_table.leave_current_scope();
        };

        process_funcall = [this](GenieFunCall* r) {
        };
    }

    std::string GenieSemanticAnalyzer::type_errs() {
        return type_errors.str();
    }

    std::string GenieSemanticAnalyzer::scope_errs() {
        return scope_errors.str();
    }

    std::string GenieSemanticAnalyzer::all_errs() {
        return type_errs() +"\n --- \n"+ scope_errs();
    }

    bool GenieSemanticAnalyzer::ok() {
        return type_errors.str().empty() && scope_errors.str().empty();
    }

    GenieSymbolTable* GenieSemanticAnalyzer::symbols() {
        return &symbol_table;
    }

    void GenieSemanticAnalyzer::whenever_symbol_table_changes(std::function<void(GenieSymbolTable*)> f) {
        symbol_table.on_every_change(std::move(f));
    }
}