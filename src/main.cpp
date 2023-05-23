#include "parser-invoker/bison-invoker/Genie-BisonInvoker.h"
#include "compiler/Genie-Compiler.h"
#include "semantic-analyzer/Genie-SemanticAnalyzer.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
int main(int argc,char* argv[]) {
    if (argc < 3) {
        std::cout<<"Call as follows : genie <input geni file> <interactive flag>";
        exit(-1);
    }
    genie::BisonInvoker invoker;
    invoker.add_file(argv[1]);

    genie::GenieSemanticAnalyzer analyzer;

    if (std::string(argv[2]) == "--interactive") {
        int symbol_table_id = 0;
        analyzer.whenever_symbol_table_changes([&symbol_table_id](auto table) -> void {
            std::stringstream filename;
            filename << "Symbol_Table_" << symbol_table_id;
            std::ofstream file(".symdump/" + filename.str());
            if (file.is_open()) {
                file << table->serialize_to_dot(filename.str());
                file.close();
                symbol_table_id++;

                std::stringstream open_command;
                open_command << "dot -Tx11 " << ".symdump/" << filename.str();

                system(open_command.str().c_str());
            } else {
                std::cerr << "Couldn't open file " << filename.str() << " to dump the symbol table";
            }
        });
    }

    invoker.ast_for_each(analyzer);

    if (!analyzer.ok()) {
        std::cout<<analyzer.all_errs();
    }
    else {
        std::ofstream bytecode_file(argv[1]+std::string(".bc"));
        if (bytecode_file.is_open()) {
            genie::GenieCompiler compiler(analyzer.symbols());
            invoker.ast_for_each(compiler);
            bytecode_file << compiler.serialize_bytecode_to_lisp();

            bytecode_file.close();
        }
        else {
            std::cerr<<"Couldn't open file "<<argv[1]+std::string(".bc")<<" to write the bytecode";
        }
    }
    return 0;
}