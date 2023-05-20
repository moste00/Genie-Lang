#pragma once

#include "../ast/Genie-Ast.hpp"

#include <functional>

namespace genie {
    struct AstProcessor {
        std::function<void(GenieProgram)> process_prog;

        std::function<void(std::vector<GenieModule*>           )> process_complex_mod;
        std::function<void(std::vector<GenieModule::ModuleElem>)> process_simple_mod;

        std::function<void(GenieType::SumType*)> process_enum;

        std::function<void(GenieFunction*)> process_function;

        std::function<void(GenieBlock*)> process_block;

        std::function<void(GenieData*)> process_data_declaration;

        std::function<void(GenieInt        )> process_int;
        std::function<void(GenieReal*      )> process_real;
        std::function<void(GenieBinaryExpr*)> process_binary;
        std::function<void(std::string*    )> process_identifier;


        std::function<void(GenieSwitch*    )> process_switch;
        std::function<void(GenieSwitch*    )> postprocess_switchcond_preprocess_all_cases;
        std::function<void(GenieSwitch*,int)> postprocess_caseexpr_preprocess_casebody;
        std::function<void(GenieSwitch*,int)> postprocess_casebody_preprcocess_nextcase;

        std::function<void(GenieIfElse*    )> process_if_else;
        std::function<void(GenieIfElse*    )> postprocess_ifcond_preprocess_ifthen;
        std::function<void(GenieIfElse*    )> postprocess_ifthen_preprocess_ifelse;

        std::function<void(GenieWhile*     )> process_while;
        std::function<void(GenieRepUntil*  )> process_rep_until;
        std::function<void(GenieFor*       )> process_for;

        AstProcessor();
    };
}