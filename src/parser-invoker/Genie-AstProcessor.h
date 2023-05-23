#pragma once

#include "../ast/Genie-Ast.hpp"

#include <functional>

namespace genie {
    struct AstProcessor {
        std::function<void(GenieProgram)> process_prog;

        std::function<void(std::vector<GenieModule*>           )> process_complex_mod;
        std::function<void(std::vector<GenieModule::ModuleElem>)> process_simple_mod;

        std::function<void(GenieType::SumType*)> process_enum;

        std::function<void(GenieFunction*)> preprocess_function;
        std::function<void(GenieFunction*)> process_function;

        std::function<void(GenieBlock*)> process_block;
        std::function<void(GenieBlock*)> postprocess_block;

        std::function<void(GenieData*)> process_data_declaration;

        std::function<void(GenieInt        )> process_int;
        std::function<void(GenieReal*      )> process_real;
        std::function<void(GenieBinaryExpr*)> process_binary;
        std::function<void(std::string*    )> process_identifier;
        std::function<void(GenieFunCall*   )> process_funcall;


        std::function<void(GenieSwitch*    )> process_switch;
        std::function<void(GenieSwitch*    )> postprocess_switchcond_preprocess_all_cases;
        std::function<void(GenieSwitch*,int)> postprocess_caseexpr_preprocess_casebody;
        std::function<void(GenieSwitch*,int)> postprocess_casebody_preprcocess_nextcase;

        std::function<void(GenieIfElse*    )> process_if_else;
        std::function<void(GenieIfElse*    )> postprocess_ifcond_preprocess_ifthen;
        std::function<void(GenieIfElse*    )> postprocess_ifthen_preprocess_ifelse;

        std::function<void(GenieWhile*     )> preprocess_while;
        std::function<void(GenieWhile*     )> process_while;
        std::function<void(GenieWhile*     )> postprocess_whilecond_preprocess_whilebody;

        std::function<void(GenieRepUntil*  )> preprocess_rep_until;
        std::function<void(GenieRepUntil*  )> process_rep_until;


        std::function<void(GenieFor*)       > postprocess_forstart_preprocess_forend;
        std::function<void(GenieFor*)       > postprocess_forend_preprocess_forbody ;
        std::function<void(GenieFor*)       > postprocess_forbody_preprocess_forstep;
        std::function<void(GenieFor*)       > preprocess_for;
        std::function<void(GenieFor*       )> process_for;


        std::function<void(GenieAssign*    )> process_assignment;
        std::function<void(GenieRet*       )> process_ret;
        AstProcessor();
    };
}