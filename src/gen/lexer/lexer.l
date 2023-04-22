%{
#include <string>
#include "../parser/Genie-Parser.hpp"
%}

%option reentrant interactive noyywrap noyylineno nodefault outfile="Genie-Lexer.cpp" header="Genie-Lexer.hpp"

non_newline_ws    (" "|"\t"|"\r"|"\v"|"\f")
newline           "\n"
OPEN_CURLY_BRACE   ("{"{newline}*)
CLOSED_CURLY_BRACE ("}"{newline}*)
decimal_digits    ([0-9]+)
binary_digits     ([0-1]+)
octal_digits      ([0-7]+)
hex_digits        ([0-9a-fA-F]+)
integer           (({decimal_digits})|("b"{binary_digits})|("o"{octal_digits})|("x"{hex_digits}))
real_fractional_part  ("."{integer})
real_integral_part    ({integer}".")
real                  (({integer}?{real_fractional_part})|({real_integral_part}{integer}?))
id                ([a-zA-Z?~_$!\\]+)
%%

"var"              return genie::GenieParser::token::VAR;
"val"              return genie::GenieParser::token::VAL;
"enum"             return genie::GenieParser::token::SUM;
"fun"              return genie::GenieParser::token::FUN;
"+"                return genie::GenieParser::token::PLUS;
"-"                return genie::GenieParser::token::MINUS;
"*"                return genie::GenieParser::token::MULT;
"/"                return genie::GenieParser::token::DIV;
"**"               return genie::GenieParser::token::EXP;
"%"                return genie::GenieParser::token::MOD;
"|"                return genie::GenieParser::token::ALT;
"("                return genie::GenieParser::token::OPEN_PAREN;
")"                return genie::GenieParser::token::CLOSED_PAREN;
{OPEN_CURLY_BRACE}   return genie::GenieParser::token::OPEN_CURLY;
{CLOSED_CURLY_BRACE} return genie::GenieParser::token::CLOSED_CURLY;
"="                return genie::GenieParser::token::EQUAL;
":"                return genie::GenieParser::token::COLON;
","                return genie::GenieParser::token::COMMA;
{integer}          {yylval->emplace<std::string>(yytext);return genie::GenieParser::token::INT;}
{real}             {yylval->emplace<std::string>(yytext);return genie::GenieParser::token::REAL;}
{id}               {yylval->emplace<std::string>(yytext);return genie::GenieParser::token::ID;}
{non_newline_ws}       /*   whitespace is ignored   */
{newline}+         return genie::GenieParser::token::G_EOL;
<<EOF>>            return genie::GenieParser::token::YYEOF;
.                  return genie::GenieParser::token::UNKNOWN;
%%
