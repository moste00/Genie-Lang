
################## Generate the lexer and the parser ##################
#1- Remove all previously generated files
cd src/gen/lexer
rm -f Genie-Lexer.*
cd ../parser
rm -f Genie-Parser.*
#2- Generate all lexer files and the parser files
bison parser.y
cd ../lexer
flex lexer.l
cd ..
cd ..
################## Compile the entire project ##################
g++ -o ../target/genie \
            main.cpp \
            gen/lexer/Genie-Lexer.cpp \
            gen/parser/Genie-Parser.cpp \
            ast/Genie-Ast.cpp \
            -lgmp
cd ..
