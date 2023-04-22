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
        int yylex(genie::GenieParser::semantic_type *yylval, yyscan_t yyscanner,genie::GenieModule*& mod)
    YY_DECL;
}

%token PLUS MINUS MULT DIV EXP MOD
%token OPEN_PAREN CLOSED_PAREN OPEN_CURLY CLOSED_CURLY
%token EQUAL COLON COMMA VAR VAL FUN SUM ALT
%token G_EOL UNKNOWN
%token <std::string>  INT
%token <std::string>  REAL
%token <std::string>  ID

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
%nterm <GenieExpr>                      g_expression g_expr
//----------------------------------------------------------------------------------
%nterm <GenieBlock*>                    g_block
//----------------------------------------------------------------------------------
%nterm <GenieData*>                     g_data_def
//----------------------------------------------------------------------------------
%nterm <GenieData::MutabilitySpecifier> g_data_def_mut_spec
//----------------------------------------------------------------------------------
%nterm <GenieData::TypeAnnotation>      g_optional_type_decl
//----------------------------------------------------------------------------------
%nterm <GenieData::TypeAnnotation>      g_type_decl g_type_ref_or_def
//----------------------------------------------------------------------------------
%nterm <GenieExpr>                      g_optional_init_expr
//----------------------------------------------------------------------------------
%nterm <GenieFunction*>                 g_func_def
//----------------------------------------------------------------------------------
%nterm <std::vector<GenieFunction::FunctionParam>>
                                        g_optional_param_list
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

g_expression : g_expr G_EOL   {$$ = $1;}

g_expr : INT                  {$$ = GenieExpr(GenieInt($1));}
       | REAL                 {throw "UNIMPLEMENTED"; }
       | g_expr PLUS  g_expr  {$$ = GenieExpr(new GenieBinaryExpr($1,$3,GenieBinaryExpr::GenieBinaryOp::PLUS_OP));}
       | g_expr MINUS g_expr  {$$ = GenieExpr(new GenieBinaryExpr($1,$3,GenieBinaryExpr::GenieBinaryOp::MINUS_OP)); }
       | g_expr MULT  g_expr  {$$ = GenieExpr(new GenieBinaryExpr($1,$3,GenieBinaryExpr::GenieBinaryOp::MULT_OP)); }
       | g_expr DIV   g_expr  {$$ = GenieExpr(new GenieBinaryExpr($1,$3,GenieBinaryExpr::GenieBinaryOp::DIV_OP));}
       | g_expr MOD   g_expr  {$$ = GenieExpr(new GenieBinaryExpr($1,$3,GenieBinaryExpr::GenieBinaryOp::MOD_OP));}
       | g_expr EXP   g_expr  {$$ = GenieExpr(new GenieBinaryExpr($1,$3,GenieBinaryExpr::GenieBinaryOp::EXP_OP));}
       | OPEN_PAREN g_expr CLOSED_PAREN {$$ = $2;}

g_block : OPEN_CURLY g_module_elements CLOSED_CURLY {$$ = new GenieBlock($2);}

g_data_def : g_data_def_mut_spec
             ID
             g_optional_type_decl
             g_optional_init_expr
             G_EOL                              {$$ = new GenieData($1,$2,$3,$4);}

g_data_def_mut_spec : VAR                       {$$ = GenieData::MutabilitySpecifier::VAR;}
                    | VAL                       {$$ = GenieData::MutabilitySpecifier::VAL;}
g_optional_type_decl: %empty                    {$$ = GenieData::TypeAnnotation(nullptr);}
                    | g_type_decl               {$$ = $1;}
g_type_decl : COLON g_type_ref_or_def           {$$ = $2;}
g_type_ref_or_def : ID                          {$$ = GenieData::TypeAnnotation($1);}
                  | g_type_def                  {$$ = GenieData::TypeAnnotation($1);}
g_optional_init_expr : %empty                   {$$ = GenieExpr();}
                     | EQUAL g_expression       {$$ = $2;}

g_func_def : FUN ID g_optional_param_list g_block {$$ = new GenieFunction($2,$3,$4);}

g_optional_param_list : %empty                         {$$ = std::vector<GenieFunction::FunctionParam>{};}
                      | g_optional_param_list g_param  {$$ = $1; $$.push_back($2);}

g_param : ID g_optional_type_decl g_optional_init_expr g_param_end {$$ = GenieFunction::FunctionParam($1,$2,$3);}

g_param_end : G_EOL      {$$ = ' ';}
            | COMMA      {$$ = ' ';} //IRRELEVANT

g_type_def : g_sum_type                      {$$ = new GenieType($1);}
g_sum_type : SUM ID EQUAL g_variants         {$$ = new GenieType::SumType($2,$4);}
g_variants : ID g_more_variants              {$$ = std::vector<std::string>{$1}; $$.insert($$.end(),$2.begin(),$2.end());}
g_more_variants : %empty                     {$$ = std::vector<std::string>{};}
                | ALT ID g_more_variants     {$$ = std::vector<std::string>{$2}; $$.insert($$.end(),$3.begin(),$3.end());}
%%
void genie::GenieParser::error(const std::string& msg) {
    int line = yyget_lineno(scanner);
    std::cerr << msg <<" at line "<<line<<'\n';
}
