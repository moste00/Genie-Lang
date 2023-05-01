%{
#include <iostream>
#include <string>
#include <vector>

#include "../lexer/Genie-Lexer.hpp"
#include "../../ast/Genie-Ast.hpp"
%}

%require "3.3.0"
%language "C++"
%defines  "Genie-Parser.hpp"
%output   "Genie-Parser.cpp"

%locations
%define parse.trace

%define api.parser.class {GenieParser}
%define api.value.type variant
%define api.namespace {genie}

%param {yyscan_t scanner}
%param {GenieModule*& mod}

%code requires {
    #include "../../ast/Genie-Ast.hpp"
}

%code provides {
    #define YY_DECL \
        int yylex(genie::GenieParser::semantic_type *yylval, genie::GenieParser::location_type* yylloc, yyscan_t yyscanner,genie::GenieModule*& mod)
    YY_DECL;
}

%token PLUS MINUS MULT DIV EXP MOD
%token OPEN_PAREN CLOSED_PAREN OPEN_CURLY CLOSED_CURLY OPEN_SQ_BRACKET CLOSED_SQ_BRACKET
%token EQUAL COLON COMMA VAR VAL FUN SUM ALT
%token SWITCH WHILE REP IF ELSE UNTIL FOR CASE STEP
%token G_EOL UNKNOWN
%token <std::string>  INT
%token <std::string>  REAL
%token <std::string>  ID

%nonassoc            OR
%nonassoc            AND
%nonassoc            NOT
%nonassoc            LESS_THAN GREATER_THAN LESS_THAN_EQ GREATER_THAN_EQ IS_EQUAL_TO IS_NOT_EQUAL_TO
%left               PLUS MINUS
%left               MULT DIV MOD
%right              EXP

//----------------------------------------------------------------------------------
%nterm <GenieModule*>                   g_source
//----------------------------------------------------------------------------------
%nterm <std::vector<
            GenieModule::ModuleElem>>   g_module_elements
//----------------------------------------------------------------------------------
%nterm <GenieModule::ModuleElem>        g_module_element
//----------------------------------------------------------------------------------
%nterm <GenieExpr>                      g_expression g_expr g_control_expr g_any_expr
//---------------TODO : type those symbols properly and write their action rules after defining AST nodes to represent them
%nterm <GenieBlock*> g_switch_body g_cases g_case g_for_var_decl g_optional_else g_assign g_fun_call_args g_rest_of_fun_call_args
//----------------------------------------------------------------------------------
%nterm <GenieBlock*>                    g_block
//----------------------------------------------------------------------------------
%nterm <GenieData*>                     g_data_def
//----------------------------------------------------------------------------------
%nterm <GenieData::MutabilitySpecifier> g_data_def_mut_spec
//----------------------------------------------------------------------------------
%nterm <std::string>                    g_optional_type_decl
//----------------------------------------------------------------------------------
%nterm <std::string>                    g_type_decl
//----------------------------------------------------------------------------------
%nterm <GenieExpr>                      g_optional_init_expr
//----------------------------------------------------------------------------------
%nterm <GenieFunction*>                 g_func_def
//----------------------------------------------------------------------------------
%nterm <std::vector<GenieFunction::FunctionParam>>
                                        g_optional_param_list g_param_list g_rest_of_param_list
//----------------------------------------------------------------------------------
%nterm <GenieFunction::FunctionParam>   g_param
//----------------------------------------------------------------------------------
%nterm <char>                           g_param_end
//----------------------------------------------------------------------------------
%nterm <GenieType*>                     g_type_def
//----------------------------------------------------------------------------------
%nterm <GenieType::SumType*>             g_sum_type
//----------------------------------------------------------------------------------
%nterm <std::vector<std::string>>       g_variants g_more_variants
//----------------------------------------------------------------------------------
%%
g_source : g_module_elements                            {$$ = new GenieModule($1); mod = $$;}

g_module_elements : %empty                              {$$ = std::vector<GenieModule::ModuleElem>{};}
                  | g_module_elements g_module_element  {$$ = $1; $$.push_back($2);}

g_module_element : g_expression {$$ = GenieModule::ModuleElem($1);}
                 | g_block      {$$ = GenieModule::ModuleElem($1);}
                 | g_data_def   {$$ = GenieModule::ModuleElem($1);}
                 | g_func_def   {$$ = GenieModule::ModuleElem($1);}
                 | g_type_def   {$$ = GenieModule::ModuleElem($1);}
                 | g_assign     {$$ = GenieModule::ModuleElem();  }
g_expression : g_expr G_EOL   {$$ = $1;}
             | g_control_expr {$$ = $1;}
g_any_expr : g_expr           {$$ = $1;}
           | g_control_expr   {$$ = $1;}

g_expr : INT                            {$$ = GenieExpr(GenieInt($1));}
       | REAL                           {$$ = GenieExpr(); }
       | g_expr PLUS  g_expr            {$$ = GenieExpr(new GenieBinaryExpr($1,$3,GenieBinaryExpr::GenieBinaryOp::PLUS_OP));}
       | g_expr MINUS g_expr            {$$ = GenieExpr(new GenieBinaryExpr($1,$3,GenieBinaryExpr::GenieBinaryOp::MINUS_OP)); }
       | g_expr MULT  g_expr            {$$ = GenieExpr(new GenieBinaryExpr($1,$3,GenieBinaryExpr::GenieBinaryOp::MULT_OP)); }
       | g_expr DIV   g_expr            {$$ = GenieExpr(new GenieBinaryExpr($1,$3,GenieBinaryExpr::GenieBinaryOp::DIV_OP));}
       | g_expr MOD   g_expr            {$$ = GenieExpr(new GenieBinaryExpr($1,$3,GenieBinaryExpr::GenieBinaryOp::MOD_OP));}
       | g_expr EXP   g_expr            {$$ = GenieExpr(new GenieBinaryExpr($1,$3,GenieBinaryExpr::GenieBinaryOp::EXP_OP));}
       | g_expr LESS_THAN  g_expr       {$$ = GenieExpr(); }
       | g_expr GREATER_THAN g_expr     {$$ = GenieExpr(); }
       | g_expr LESS_THAN_EQ  g_expr    {$$ = GenieExpr(); }
       | g_expr GREATER_THAN_EQ g_expr  {$$ = GenieExpr(); }
       | g_expr IS_EQUAL_TO   g_expr    {$$ = GenieExpr(); }
       | g_expr IS_NOT_EQUAL_TO g_expr  {$$ = GenieExpr(); }
       | g_expr OR  g_expr              {$$ = GenieExpr(); }
       | g_expr AND g_expr              {$$ = GenieExpr(); }
       | NOT g_expr                     {$$ = GenieExpr(); }
       | OPEN_PAREN g_expr CLOSED_PAREN {$$ = GenieExpr(); }
       | ID OPEN_SQ_BRACKET
         g_fun_call_args
         CLOSED_SQ_BRACKET             {$$ = GenieExpr(); }
       | ID                             {$$ = GenieExpr($1);}

g_control_expr : SWITCH g_any_expr g_switch_body           {$$ = GenieExpr();}
               | WHILE  g_any_expr g_block                 {$$ = GenieExpr();}
               | REP g_block UNTIL g_expression            {$$ = GenieExpr();}
               | FOR g_for_var_decl g_block                {$$ = GenieExpr();}
               | IF g_any_expr g_block g_optional_else     {$$ = GenieExpr();}

g_block : OPEN_CURLY g_module_elements CLOSED_CURLY {$$ = new GenieBlock($2);}

g_switch_body : OPEN_CURLY g_cases CLOSED_CURLY     {$$ = nullptr;}
g_cases : %empty                                    {$$ = nullptr;}
        | g_cases g_case                            {$$ = nullptr;}
g_case : CASE g_any_expr g_block                    {$$ = nullptr;}

g_for_var_decl : ID EQUAL g_any_expr COLON g_any_expr STEP g_any_expr {$$ = nullptr;}

g_optional_else : %empty                            {$$ = nullptr;}
                | ELSE g_block                      {$$ = nullptr;}

g_assign : ID EQUAL g_expression {$$ = nullptr;}


g_data_def : g_data_def_mut_spec
             ID
             g_optional_type_decl
             g_optional_init_expr
             G_EOL                              {$$ = new GenieData($1,$2,$3,$4);}

g_data_def_mut_spec : VAR                       {$$ = GenieData::MutabilitySpecifier::VAR;}
                    | VAL                       {$$ = GenieData::MutabilitySpecifier::VAL;}
g_optional_type_decl: %empty                    {$$ = std::string("");}
                    | g_type_decl               {$$ = $1;}
g_type_decl : COLON ID                          {$$ = $2;}
g_optional_init_expr : %empty                   {$$ = GenieExpr();}
                     | EQUAL g_expr             {$$ = $2;}

g_func_def : FUN ID g_optional_param_list g_block {$$ = new GenieFunction($2,$3,$4);}

g_optional_param_list : %empty                         {$$ = std::vector<GenieFunction::FunctionParam>{};}
                      | g_param_list                   {$$ = $1;}

g_param_list : g_param g_rest_of_param_list            {$$ = std::vector<GenieFunction::FunctionParam>{$1}; $$.insert($$.end(),$2.begin(),$2.end());}

g_rest_of_param_list : %empty                          {$$ = std::vector<GenieFunction::FunctionParam>{};}
                     | g_param_end g_param g_rest_of_param_list {$$ = std::vector<GenieFunction::FunctionParam>{$2}; $$.insert($$.end(),$3.begin(),$3.end());}

g_param : ID g_optional_type_decl g_optional_init_expr {$$ = GenieFunction::FunctionParam($1,$2,$3);}

g_param_end : G_EOL      {$$ = ' ';}
            | COMMA      {$$ = ' ';} //IRRELEVANT
g_fun_call_args : %empty                                  {$$ = nullptr;}
                | g_any_expr g_rest_of_fun_call_args  {$$ = nullptr;}
g_rest_of_fun_call_args : %empty                      {$$ = nullptr;}
                        | g_param_end g_any_expr g_rest_of_fun_call_args {$$ = nullptr;}
g_type_def : g_sum_type                            {$$ = new GenieType($1);}
g_sum_type : SUM ID EQUAL g_variants               {$$ = new GenieType::SumType($2,$4);}
g_variants : ID g_more_variants                    {$$ = std::vector<std::string>{$1}; $$.insert($$.end(),$2.begin(),$2.end());}
g_more_variants : %empty                           {$$ = std::vector<std::string>{};}
                | ALT ID g_more_variants G_EOL     {$$ = std::vector<std::string>{$2}; $$.insert($$.end(),$3.begin(),$3.end());}
%%
void genie::GenieParser::error(const location_type& t,const std::string& msg) {
    std::cerr << msg <<" at line "<<t.begin.line<<'\n';
}
