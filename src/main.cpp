#include "gen/lexer/Genie-Lexer.hpp"
#include "gen/parser/Genie-Parser.hpp"
#include "ast/Genie-Ast.hpp"
#include "iostream"

int main() {
    yyscan_t scanner;
    yylex_init(&scanner);
    FILE* f = fopen("tests/genie/02-blocks.geni","r");
    yyset_in(f,scanner);

    genie::GenieModule* mod;
    genie::GenieParser parser(scanner,mod);

    int failed = parser.parse();
    if (failed != 0) {
        std::cout << "Couldn't parse input \n";
        exit(-1);
    }
    std::cout<<"Done Parsing !";

    yylex_destroy(scanner);
}
