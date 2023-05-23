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
                "src/ast/Genie-Program.cpp"
                "src/ast/Genie-Switch.cpp"
                "src/ast/Genie-IfElse.cpp"
                "src/ast/Genie-While.cpp"
                "src/ast/Genie-RepeatUntil.cpp"
                "src/ast/Genie-For.cpp"
                "src/ast/Genie-FunctionCall.cpp"
                "src/ast/Genie-Assignment.cpp"
                "src/ast/Genie-Return.cpp"

                "src/parser-invoker/Genie-ParserInvoker.cpp"
                "src/parser-invoker/Genie-AstProcessor.cpp"
                "src/parser-invoker/bison-invoker/Genie-BisonInvoker.cpp"

                "src/pretty-printers/Genie-JsonAstPrinter.cpp"

                "src/compiler/Genie-Compiler.cpp"

                "src/bytecode/Genie-ByteCodeBuffer.cpp"
                "src/bytecode/Genie-ByteCodeEmitter.cpp"
                "src/symbol-table/Genie-Scope.cpp"
                "src/symbol-table/Genie-SymbolTable.cpp"
        src/semantic-analyzer/Genie-SemanticAnalyzer.cpp src/semantic-analyzer/Genie-SemanticAnalyzer.h)

target_link_libraries(Genie "/usr/local/lib/libgmp.a" "/usr/local/lib/libgmpxx.a")