
#include "Genie-AstProcessor.h"

namespace genie {
    AstProcessor::AstProcessor() {
        process_prog = [](auto) {};
        process_simple_mod = [](auto) {};
        process_complex_mod = [](auto) {};

        process_enum = [](auto) {};
        process_data_declaration = [](auto) {};
        process_function = [](auto) {};
        process_block = [](auto) {};

        process_int = [](auto) {};
        process_real = [](auto) {};
        process_binary = [](auto) {};
        process_identifier = [](auto) {};

        process_if_else = [](auto) {};
        postprocess_ifcond_preprocess_ifthen = [](auto){};
        postprocess_ifthen_preprocess_ifelse = [](auto){};

        process_switch = [](auto) {};
        postprocess_switchcond_preprocess_all_cases = [](auto){};
        postprocess_caseexpr_preprocess_casebody = [](auto,auto){};
        postprocess_casebody_preprcocess_nextcase = [](auto,auto){};

        process_while = [](auto) {};

        process_for = [](auto) {};

        process_rep_until = [](auto) {};
    }
}