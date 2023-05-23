
#include "Genie-AstProcessor.h"

namespace genie {
    AstProcessor::AstProcessor() {
        process_prog = [](auto) {};
        process_simple_mod = [](auto) {};
        process_complex_mod = [](auto) {};

        process_enum = [](auto) {};

        process_data_declaration = [](auto) {};

        preprocess_function = [](auto){};
        process_function = [](auto) {};

        process_block = [](auto) {};
        postprocess_block = [](auto){};

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

        preprocess_while = [](auto){};
        postprocess_whilecond_preprocess_whilebody = [](auto) {};
        process_while = [](auto) {};

        process_for = [](auto) {};
        postprocess_forstart_preprocess_forend = [](auto) {};
        postprocess_forend_preprocess_forbody  = [](auto) {};
        postprocess_forbody_preprocess_forstep = [](auto) {};
        preprocess_for = [](auto){};

        preprocess_rep_until = [](auto){};
        process_rep_until = [](auto) {};

        process_funcall = [](auto){};
        process_ret = [](auto){};
    }
}