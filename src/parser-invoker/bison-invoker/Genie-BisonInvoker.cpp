#include "../../gen/lexer/Genie-Lexer.hpp"
#include "../../gen/parser/Genie-Parser.hpp"
#include "Genie-BisonInvoker.h"

namespace genie {
    void BisonInvoker::add_file(const string& filepath) {
        yyscan_t scanner;
        yylex_init(&scanner);

        FILE* f = fopen(filepath.c_str(),"r");
        if (f == NULL) {
            std::cerr << "Couldn't open given file";
            exit(-1);
        }
        yyset_in(f,scanner);

        GenieModule* mod;
        GenieParser parser(scanner,mod);

        //parser.set_debug_level(1);
        int failed = parser.parse();
        if (failed != 0) {
            std::cerr << "Couldn't parse input \n";
            exit(-1);
        }

        std::cout<<"Done Parsing !!!";
        yylex_destroy(scanner);
        prog.modules.push_back(mod);
    }

    void BisonInvoker::add_string(const string &string1) {
        throw "UNIMPLEMENTED";
    }
}