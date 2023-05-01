cmake_minimum_required(VERSION 3.4)
set(CMAKE_CXX_STANDARD 14)

project(Genie)

add_executable(Genie
               "src/main.cpp"

               "src/gen/lexer/Genie-Lexer.cpp"
               "src/gen/parser/Genie-Parser.cpp"

                "src/ast/Genie-Int.cpp"
                "src/ast/Genie-Real.cpp"
                "src/ast/Genie-Binary.cpp"
                "src/ast/Genie-Expr.cpp"
                "src/ast/Genie-DataDef.cpp"
                "src/ast/Genie-Block.cpp"
                "src/ast/Genie-FunctionDef.cpp"
                "src/ast/Genie-TypeDef.cpp"
                "src/ast/Genie-Module.cpp"
                "src/ast/Genie-Program.cpp" src/parser-invoker/Genie-ParserInvoker.h src/parser-invoker/Genie-AstWalker.h src/pretty-printers/Genie-JsonAstPrinter.cpp src/pretty-printers/Genie-JsonAstPrinter.h src/parser-invoker/bison-invoker/Genie-BisonInvoker.cpp src/parser-invoker/bison-invoker/Genie-BisonInvoker.h)

target_link_libraries(Genie "/usr/local/lib/libgmp.a" "/usr/local/lib/libgmpxx.a")