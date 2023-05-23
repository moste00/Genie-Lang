// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.



// First part of user prologue.
#line 1 "parser.y"

#include <iostream>
#include <string>
#include <vector>

#include "../lexer/Genie-Lexer.hpp"
#include "../../ast/Genie-Ast.hpp"

#line 50 "Genie-Parser.cpp"


#include "Genie-Parser.hpp"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 20 "parser.y"
namespace genie {
#line 148 "Genie-Parser.cpp"

  /// Build a parser object.
  GenieParser::GenieParser (yyscan_t scanner_yyarg, GenieModule*& mod_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      mod (mod_yyarg)
  {}

  GenieParser::~GenieParser ()
  {}

  GenieParser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  GenieParser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_g_assign: // g_assign
        value.copy< GenieAssign* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_block: // g_block
      case symbol_kind::S_g_optional_else: // g_optional_else
        value.copy< GenieBlock* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_data_def: // g_data_def
        value.copy< GenieData* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_data_def_mut_spec: // g_data_def_mut_spec
        value.copy< GenieData::MutabilitySpecifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_expression: // g_expression
      case symbol_kind::S_g_any_expr: // g_any_expr
      case symbol_kind::S_g_expr: // g_expr
      case symbol_kind::S_g_control_expr: // g_control_expr
      case symbol_kind::S_g_optional_init_expr: // g_optional_init_expr
        value.copy< GenieExpr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_func_def: // g_func_def
        value.copy< GenieFunction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_param: // g_param
        value.copy< GenieFunction::FunctionParam > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_source: // g_source
        value.copy< GenieModule* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_module_element: // g_module_element
        value.copy< GenieModule::ModuleElem > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_return: // g_return
        value.copy< GenieRet* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_case: // g_case
        value.copy< GenieSwitch::GenieCase > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_type_def: // g_type_def
        value.copy< GenieType* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_sum_type: // g_sum_type
        value.copy< GenieType::SumType* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_ignored_newlines: // g_ignored_newlines
      case symbol_kind::S_g_param_end: // g_param_end
        value.copy< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_REAL: // REAL
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_g_optional_type_decl: // g_optional_type_decl
      case symbol_kind::S_g_type_decl: // g_type_decl
      case symbol_kind::S_g_optional_ret_type: // g_optional_ret_type
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_for_var_decl: // g_for_var_decl
      case symbol_kind::S_g_fun_call_args: // g_fun_call_args
      case symbol_kind::S_g_rest_of_fun_call_args: // g_rest_of_fun_call_args
        value.copy< std::vector<GenieExpr> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_optional_param_list: // g_optional_param_list
      case symbol_kind::S_g_param_list: // g_param_list
      case symbol_kind::S_g_rest_of_param_list: // g_rest_of_param_list
        value.copy< std::vector<GenieFunction::FunctionParam> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_module_elements: // g_module_elements
        value.copy< std::vector<GenieModule::ModuleElem> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_switch_body: // g_switch_body
      case symbol_kind::S_g_cases: // g_cases
        value.copy< std::vector<GenieSwitch::GenieCase> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_variants: // g_variants
      case symbol_kind::S_g_more_variants: // g_more_variants
        value.copy< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  GenieParser::symbol_kind_type
  GenieParser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  GenieParser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  GenieParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_g_assign: // g_assign
        value.move< GenieAssign* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_g_block: // g_block
      case symbol_kind::S_g_optional_else: // g_optional_else
        value.move< GenieBlock* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_g_data_def: // g_data_def
        value.move< GenieData* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_g_data_def_mut_spec: // g_data_def_mut_spec
        value.move< GenieData::MutabilitySpecifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_g_expression: // g_expression
      case symbol_kind::S_g_any_expr: // g_any_expr
      case symbol_kind::S_g_expr: // g_expr
      case symbol_kind::S_g_control_expr: // g_control_expr
      case symbol_kind::S_g_optional_init_expr: // g_optional_init_expr
        value.move< GenieExpr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_g_func_def: // g_func_def
        value.move< GenieFunction* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_g_param: // g_param
        value.move< GenieFunction::FunctionParam > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_g_source: // g_source
        value.move< GenieModule* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_g_module_element: // g_module_element
        value.move< GenieModule::ModuleElem > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_g_return: // g_return
        value.move< GenieRet* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_g_case: // g_case
        value.move< GenieSwitch::GenieCase > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_g_type_def: // g_type_def
        value.move< GenieType* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_g_sum_type: // g_sum_type
        value.move< GenieType::SumType* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_g_ignored_newlines: // g_ignored_newlines
      case symbol_kind::S_g_param_end: // g_param_end
        value.move< char > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_REAL: // REAL
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_g_optional_type_decl: // g_optional_type_decl
      case symbol_kind::S_g_type_decl: // g_type_decl
      case symbol_kind::S_g_optional_ret_type: // g_optional_ret_type
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_g_for_var_decl: // g_for_var_decl
      case symbol_kind::S_g_fun_call_args: // g_fun_call_args
      case symbol_kind::S_g_rest_of_fun_call_args: // g_rest_of_fun_call_args
        value.move< std::vector<GenieExpr> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_g_optional_param_list: // g_optional_param_list
      case symbol_kind::S_g_param_list: // g_param_list
      case symbol_kind::S_g_rest_of_param_list: // g_rest_of_param_list
        value.move< std::vector<GenieFunction::FunctionParam> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_g_module_elements: // g_module_elements
        value.move< std::vector<GenieModule::ModuleElem> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_g_switch_body: // g_switch_body
      case symbol_kind::S_g_cases: // g_cases
        value.move< std::vector<GenieSwitch::GenieCase> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_g_variants: // g_variants
      case symbol_kind::S_g_more_variants: // g_more_variants
        value.move< std::vector<std::string> > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  GenieParser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  GenieParser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  GenieParser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  GenieParser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  GenieParser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  GenieParser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  GenieParser::symbol_kind_type
  GenieParser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  GenieParser::symbol_kind_type
  GenieParser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  GenieParser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  GenieParser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  GenieParser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  GenieParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  GenieParser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  GenieParser::symbol_kind_type
  GenieParser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  GenieParser::stack_symbol_type::stack_symbol_type ()
  {}

  GenieParser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_g_assign: // g_assign
        value.YY_MOVE_OR_COPY< GenieAssign* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_block: // g_block
      case symbol_kind::S_g_optional_else: // g_optional_else
        value.YY_MOVE_OR_COPY< GenieBlock* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_data_def: // g_data_def
        value.YY_MOVE_OR_COPY< GenieData* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_data_def_mut_spec: // g_data_def_mut_spec
        value.YY_MOVE_OR_COPY< GenieData::MutabilitySpecifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_expression: // g_expression
      case symbol_kind::S_g_any_expr: // g_any_expr
      case symbol_kind::S_g_expr: // g_expr
      case symbol_kind::S_g_control_expr: // g_control_expr
      case symbol_kind::S_g_optional_init_expr: // g_optional_init_expr
        value.YY_MOVE_OR_COPY< GenieExpr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_func_def: // g_func_def
        value.YY_MOVE_OR_COPY< GenieFunction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_param: // g_param
        value.YY_MOVE_OR_COPY< GenieFunction::FunctionParam > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_source: // g_source
        value.YY_MOVE_OR_COPY< GenieModule* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_module_element: // g_module_element
        value.YY_MOVE_OR_COPY< GenieModule::ModuleElem > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_return: // g_return
        value.YY_MOVE_OR_COPY< GenieRet* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_case: // g_case
        value.YY_MOVE_OR_COPY< GenieSwitch::GenieCase > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_type_def: // g_type_def
        value.YY_MOVE_OR_COPY< GenieType* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_sum_type: // g_sum_type
        value.YY_MOVE_OR_COPY< GenieType::SumType* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_ignored_newlines: // g_ignored_newlines
      case symbol_kind::S_g_param_end: // g_param_end
        value.YY_MOVE_OR_COPY< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_REAL: // REAL
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_g_optional_type_decl: // g_optional_type_decl
      case symbol_kind::S_g_type_decl: // g_type_decl
      case symbol_kind::S_g_optional_ret_type: // g_optional_ret_type
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_for_var_decl: // g_for_var_decl
      case symbol_kind::S_g_fun_call_args: // g_fun_call_args
      case symbol_kind::S_g_rest_of_fun_call_args: // g_rest_of_fun_call_args
        value.YY_MOVE_OR_COPY< std::vector<GenieExpr> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_optional_param_list: // g_optional_param_list
      case symbol_kind::S_g_param_list: // g_param_list
      case symbol_kind::S_g_rest_of_param_list: // g_rest_of_param_list
        value.YY_MOVE_OR_COPY< std::vector<GenieFunction::FunctionParam> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_module_elements: // g_module_elements
        value.YY_MOVE_OR_COPY< std::vector<GenieModule::ModuleElem> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_switch_body: // g_switch_body
      case symbol_kind::S_g_cases: // g_cases
        value.YY_MOVE_OR_COPY< std::vector<GenieSwitch::GenieCase> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_variants: // g_variants
      case symbol_kind::S_g_more_variants: // g_more_variants
        value.YY_MOVE_OR_COPY< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  GenieParser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_g_assign: // g_assign
        value.move< GenieAssign* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_block: // g_block
      case symbol_kind::S_g_optional_else: // g_optional_else
        value.move< GenieBlock* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_data_def: // g_data_def
        value.move< GenieData* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_data_def_mut_spec: // g_data_def_mut_spec
        value.move< GenieData::MutabilitySpecifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_expression: // g_expression
      case symbol_kind::S_g_any_expr: // g_any_expr
      case symbol_kind::S_g_expr: // g_expr
      case symbol_kind::S_g_control_expr: // g_control_expr
      case symbol_kind::S_g_optional_init_expr: // g_optional_init_expr
        value.move< GenieExpr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_func_def: // g_func_def
        value.move< GenieFunction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_param: // g_param
        value.move< GenieFunction::FunctionParam > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_source: // g_source
        value.move< GenieModule* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_module_element: // g_module_element
        value.move< GenieModule::ModuleElem > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_return: // g_return
        value.move< GenieRet* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_case: // g_case
        value.move< GenieSwitch::GenieCase > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_type_def: // g_type_def
        value.move< GenieType* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_sum_type: // g_sum_type
        value.move< GenieType::SumType* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_ignored_newlines: // g_ignored_newlines
      case symbol_kind::S_g_param_end: // g_param_end
        value.move< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_REAL: // REAL
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_g_optional_type_decl: // g_optional_type_decl
      case symbol_kind::S_g_type_decl: // g_type_decl
      case symbol_kind::S_g_optional_ret_type: // g_optional_ret_type
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_for_var_decl: // g_for_var_decl
      case symbol_kind::S_g_fun_call_args: // g_fun_call_args
      case symbol_kind::S_g_rest_of_fun_call_args: // g_rest_of_fun_call_args
        value.move< std::vector<GenieExpr> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_optional_param_list: // g_optional_param_list
      case symbol_kind::S_g_param_list: // g_param_list
      case symbol_kind::S_g_rest_of_param_list: // g_rest_of_param_list
        value.move< std::vector<GenieFunction::FunctionParam> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_module_elements: // g_module_elements
        value.move< std::vector<GenieModule::ModuleElem> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_switch_body: // g_switch_body
      case symbol_kind::S_g_cases: // g_cases
        value.move< std::vector<GenieSwitch::GenieCase> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_variants: // g_variants
      case symbol_kind::S_g_more_variants: // g_more_variants
        value.move< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  GenieParser::stack_symbol_type&
  GenieParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_g_assign: // g_assign
        value.copy< GenieAssign* > (that.value);
        break;

      case symbol_kind::S_g_block: // g_block
      case symbol_kind::S_g_optional_else: // g_optional_else
        value.copy< GenieBlock* > (that.value);
        break;

      case symbol_kind::S_g_data_def: // g_data_def
        value.copy< GenieData* > (that.value);
        break;

      case symbol_kind::S_g_data_def_mut_spec: // g_data_def_mut_spec
        value.copy< GenieData::MutabilitySpecifier > (that.value);
        break;

      case symbol_kind::S_g_expression: // g_expression
      case symbol_kind::S_g_any_expr: // g_any_expr
      case symbol_kind::S_g_expr: // g_expr
      case symbol_kind::S_g_control_expr: // g_control_expr
      case symbol_kind::S_g_optional_init_expr: // g_optional_init_expr
        value.copy< GenieExpr > (that.value);
        break;

      case symbol_kind::S_g_func_def: // g_func_def
        value.copy< GenieFunction* > (that.value);
        break;

      case symbol_kind::S_g_param: // g_param
        value.copy< GenieFunction::FunctionParam > (that.value);
        break;

      case symbol_kind::S_g_source: // g_source
        value.copy< GenieModule* > (that.value);
        break;

      case symbol_kind::S_g_module_element: // g_module_element
        value.copy< GenieModule::ModuleElem > (that.value);
        break;

      case symbol_kind::S_g_return: // g_return
        value.copy< GenieRet* > (that.value);
        break;

      case symbol_kind::S_g_case: // g_case
        value.copy< GenieSwitch::GenieCase > (that.value);
        break;

      case symbol_kind::S_g_type_def: // g_type_def
        value.copy< GenieType* > (that.value);
        break;

      case symbol_kind::S_g_sum_type: // g_sum_type
        value.copy< GenieType::SumType* > (that.value);
        break;

      case symbol_kind::S_g_ignored_newlines: // g_ignored_newlines
      case symbol_kind::S_g_param_end: // g_param_end
        value.copy< char > (that.value);
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_REAL: // REAL
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_g_optional_type_decl: // g_optional_type_decl
      case symbol_kind::S_g_type_decl: // g_type_decl
      case symbol_kind::S_g_optional_ret_type: // g_optional_ret_type
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_g_for_var_decl: // g_for_var_decl
      case symbol_kind::S_g_fun_call_args: // g_fun_call_args
      case symbol_kind::S_g_rest_of_fun_call_args: // g_rest_of_fun_call_args
        value.copy< std::vector<GenieExpr> > (that.value);
        break;

      case symbol_kind::S_g_optional_param_list: // g_optional_param_list
      case symbol_kind::S_g_param_list: // g_param_list
      case symbol_kind::S_g_rest_of_param_list: // g_rest_of_param_list
        value.copy< std::vector<GenieFunction::FunctionParam> > (that.value);
        break;

      case symbol_kind::S_g_module_elements: // g_module_elements
        value.copy< std::vector<GenieModule::ModuleElem> > (that.value);
        break;

      case symbol_kind::S_g_switch_body: // g_switch_body
      case symbol_kind::S_g_cases: // g_cases
        value.copy< std::vector<GenieSwitch::GenieCase> > (that.value);
        break;

      case symbol_kind::S_g_variants: // g_variants
      case symbol_kind::S_g_more_variants: // g_more_variants
        value.copy< std::vector<std::string> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  GenieParser::stack_symbol_type&
  GenieParser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_g_assign: // g_assign
        value.move< GenieAssign* > (that.value);
        break;

      case symbol_kind::S_g_block: // g_block
      case symbol_kind::S_g_optional_else: // g_optional_else
        value.move< GenieBlock* > (that.value);
        break;

      case symbol_kind::S_g_data_def: // g_data_def
        value.move< GenieData* > (that.value);
        break;

      case symbol_kind::S_g_data_def_mut_spec: // g_data_def_mut_spec
        value.move< GenieData::MutabilitySpecifier > (that.value);
        break;

      case symbol_kind::S_g_expression: // g_expression
      case symbol_kind::S_g_any_expr: // g_any_expr
      case symbol_kind::S_g_expr: // g_expr
      case symbol_kind::S_g_control_expr: // g_control_expr
      case symbol_kind::S_g_optional_init_expr: // g_optional_init_expr
        value.move< GenieExpr > (that.value);
        break;

      case symbol_kind::S_g_func_def: // g_func_def
        value.move< GenieFunction* > (that.value);
        break;

      case symbol_kind::S_g_param: // g_param
        value.move< GenieFunction::FunctionParam > (that.value);
        break;

      case symbol_kind::S_g_source: // g_source
        value.move< GenieModule* > (that.value);
        break;

      case symbol_kind::S_g_module_element: // g_module_element
        value.move< GenieModule::ModuleElem > (that.value);
        break;

      case symbol_kind::S_g_return: // g_return
        value.move< GenieRet* > (that.value);
        break;

      case symbol_kind::S_g_case: // g_case
        value.move< GenieSwitch::GenieCase > (that.value);
        break;

      case symbol_kind::S_g_type_def: // g_type_def
        value.move< GenieType* > (that.value);
        break;

      case symbol_kind::S_g_sum_type: // g_sum_type
        value.move< GenieType::SumType* > (that.value);
        break;

      case symbol_kind::S_g_ignored_newlines: // g_ignored_newlines
      case symbol_kind::S_g_param_end: // g_param_end
        value.move< char > (that.value);
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_REAL: // REAL
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_g_optional_type_decl: // g_optional_type_decl
      case symbol_kind::S_g_type_decl: // g_type_decl
      case symbol_kind::S_g_optional_ret_type: // g_optional_ret_type
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_g_for_var_decl: // g_for_var_decl
      case symbol_kind::S_g_fun_call_args: // g_fun_call_args
      case symbol_kind::S_g_rest_of_fun_call_args: // g_rest_of_fun_call_args
        value.move< std::vector<GenieExpr> > (that.value);
        break;

      case symbol_kind::S_g_optional_param_list: // g_optional_param_list
      case symbol_kind::S_g_param_list: // g_param_list
      case symbol_kind::S_g_rest_of_param_list: // g_rest_of_param_list
        value.move< std::vector<GenieFunction::FunctionParam> > (that.value);
        break;

      case symbol_kind::S_g_module_elements: // g_module_elements
        value.move< std::vector<GenieModule::ModuleElem> > (that.value);
        break;

      case symbol_kind::S_g_switch_body: // g_switch_body
      case symbol_kind::S_g_cases: // g_cases
        value.move< std::vector<GenieSwitch::GenieCase> > (that.value);
        break;

      case symbol_kind::S_g_variants: // g_variants
      case symbol_kind::S_g_more_variants: // g_more_variants
        value.move< std::vector<std::string> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  GenieParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  GenieParser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  GenieParser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  GenieParser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  GenieParser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  GenieParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  GenieParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  GenieParser::debug_level_type
  GenieParser::debug_level () const
  {
    return yydebug_;
  }

  void
  GenieParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  GenieParser::state_type
  GenieParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  GenieParser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  GenieParser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  GenieParser::operator() ()
  {
    return parse ();
  }

  int
  GenieParser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location, scanner, mod));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_g_assign: // g_assign
        yylhs.value.emplace< GenieAssign* > ();
        break;

      case symbol_kind::S_g_block: // g_block
      case symbol_kind::S_g_optional_else: // g_optional_else
        yylhs.value.emplace< GenieBlock* > ();
        break;

      case symbol_kind::S_g_data_def: // g_data_def
        yylhs.value.emplace< GenieData* > ();
        break;

      case symbol_kind::S_g_data_def_mut_spec: // g_data_def_mut_spec
        yylhs.value.emplace< GenieData::MutabilitySpecifier > ();
        break;

      case symbol_kind::S_g_expression: // g_expression
      case symbol_kind::S_g_any_expr: // g_any_expr
      case symbol_kind::S_g_expr: // g_expr
      case symbol_kind::S_g_control_expr: // g_control_expr
      case symbol_kind::S_g_optional_init_expr: // g_optional_init_expr
        yylhs.value.emplace< GenieExpr > ();
        break;

      case symbol_kind::S_g_func_def: // g_func_def
        yylhs.value.emplace< GenieFunction* > ();
        break;

      case symbol_kind::S_g_param: // g_param
        yylhs.value.emplace< GenieFunction::FunctionParam > ();
        break;

      case symbol_kind::S_g_source: // g_source
        yylhs.value.emplace< GenieModule* > ();
        break;

      case symbol_kind::S_g_module_element: // g_module_element
        yylhs.value.emplace< GenieModule::ModuleElem > ();
        break;

      case symbol_kind::S_g_return: // g_return
        yylhs.value.emplace< GenieRet* > ();
        break;

      case symbol_kind::S_g_case: // g_case
        yylhs.value.emplace< GenieSwitch::GenieCase > ();
        break;

      case symbol_kind::S_g_type_def: // g_type_def
        yylhs.value.emplace< GenieType* > ();
        break;

      case symbol_kind::S_g_sum_type: // g_sum_type
        yylhs.value.emplace< GenieType::SumType* > ();
        break;

      case symbol_kind::S_g_ignored_newlines: // g_ignored_newlines
      case symbol_kind::S_g_param_end: // g_param_end
        yylhs.value.emplace< char > ();
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_REAL: // REAL
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_g_optional_type_decl: // g_optional_type_decl
      case symbol_kind::S_g_type_decl: // g_type_decl
      case symbol_kind::S_g_optional_ret_type: // g_optional_ret_type
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_g_for_var_decl: // g_for_var_decl
      case symbol_kind::S_g_fun_call_args: // g_fun_call_args
      case symbol_kind::S_g_rest_of_fun_call_args: // g_rest_of_fun_call_args
        yylhs.value.emplace< std::vector<GenieExpr> > ();
        break;

      case symbol_kind::S_g_optional_param_list: // g_optional_param_list
      case symbol_kind::S_g_param_list: // g_param_list
      case symbol_kind::S_g_rest_of_param_list: // g_rest_of_param_list
        yylhs.value.emplace< std::vector<GenieFunction::FunctionParam> > ();
        break;

      case symbol_kind::S_g_module_elements: // g_module_elements
        yylhs.value.emplace< std::vector<GenieModule::ModuleElem> > ();
        break;

      case symbol_kind::S_g_switch_body: // g_switch_body
      case symbol_kind::S_g_cases: // g_cases
        yylhs.value.emplace< std::vector<GenieSwitch::GenieCase> > ();
        break;

      case symbol_kind::S_g_variants: // g_variants
      case symbol_kind::S_g_more_variants: // g_more_variants
        yylhs.value.emplace< std::vector<std::string> > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // g_source: g_module_elements
#line 109 "parser.y"
                                                        {yylhs.value.as < GenieModule* > () = new GenieModule(yystack_[0].value.as < std::vector<GenieModule::ModuleElem> > ()); mod = yylhs.value.as < GenieModule* > ();}
#line 1317 "Genie-Parser.cpp"
    break;

  case 3: // g_module_elements: %empty
#line 111 "parser.y"
                                                        {yylhs.value.as < std::vector<GenieModule::ModuleElem> > () = std::vector<GenieModule::ModuleElem>{};}
#line 1323 "Genie-Parser.cpp"
    break;

  case 4: // g_module_elements: g_module_elements g_ignored_newlines g_module_element
#line 112 "parser.y"
                                                                          {yylhs.value.as < std::vector<GenieModule::ModuleElem> > () = yystack_[2].value.as < std::vector<GenieModule::ModuleElem> > (); yylhs.value.as < std::vector<GenieModule::ModuleElem> > ().push_back(yystack_[0].value.as < GenieModule::ModuleElem > ());}
#line 1329 "Genie-Parser.cpp"
    break;

  case 5: // g_ignored_newlines: %empty
#line 114 "parser.y"
                                                        {yylhs.value.as < char > () = ' ';}
#line 1335 "Genie-Parser.cpp"
    break;

  case 6: // g_ignored_newlines: g_ignored_newlines G_EOL
#line 115 "parser.y"
                                                        {yylhs.value.as < char > () = '\n';}
#line 1341 "Genie-Parser.cpp"
    break;

  case 7: // g_module_element: g_expression
#line 116 "parser.y"
                                {yylhs.value.as < GenieModule::ModuleElem > () = GenieModule::ModuleElem(yystack_[0].value.as < GenieExpr > ());}
#line 1347 "Genie-Parser.cpp"
    break;

  case 8: // g_module_element: g_block
#line 117 "parser.y"
                                {yylhs.value.as < GenieModule::ModuleElem > () = GenieModule::ModuleElem(yystack_[0].value.as < GenieBlock* > ());}
#line 1353 "Genie-Parser.cpp"
    break;

  case 9: // g_module_element: g_data_def
#line 118 "parser.y"
                                {yylhs.value.as < GenieModule::ModuleElem > () = GenieModule::ModuleElem(yystack_[0].value.as < GenieData* > ());}
#line 1359 "Genie-Parser.cpp"
    break;

  case 10: // g_module_element: g_func_def
#line 119 "parser.y"
                                {yylhs.value.as < GenieModule::ModuleElem > () = GenieModule::ModuleElem(yystack_[0].value.as < GenieFunction* > ());}
#line 1365 "Genie-Parser.cpp"
    break;

  case 11: // g_module_element: g_type_def
#line 120 "parser.y"
                                {yylhs.value.as < GenieModule::ModuleElem > () = GenieModule::ModuleElem(yystack_[0].value.as < GenieType* > ());}
#line 1371 "Genie-Parser.cpp"
    break;

  case 12: // g_module_element: g_assign
#line 121 "parser.y"
                                {yylhs.value.as < GenieModule::ModuleElem > () = GenieModule::ModuleElem(yystack_[0].value.as < GenieAssign* > ());}
#line 1377 "Genie-Parser.cpp"
    break;

  case 13: // g_module_element: g_return
#line 122 "parser.y"
                                {yylhs.value.as < GenieModule::ModuleElem > () = GenieModule::ModuleElem(yystack_[0].value.as < GenieRet* > ());}
#line 1383 "Genie-Parser.cpp"
    break;

  case 14: // g_expression: g_expr G_EOL
#line 128 "parser.y"
                              {yylhs.value.as < GenieExpr > () = yystack_[1].value.as < GenieExpr > ();}
#line 1389 "Genie-Parser.cpp"
    break;

  case 15: // g_expression: g_control_expr
#line 129 "parser.y"
                              {yylhs.value.as < GenieExpr > () = yystack_[0].value.as < GenieExpr > ();}
#line 1395 "Genie-Parser.cpp"
    break;

  case 16: // g_any_expr: g_expr
#line 130 "parser.y"
                              {yylhs.value.as < GenieExpr > () = yystack_[0].value.as < GenieExpr > ();}
#line 1401 "Genie-Parser.cpp"
    break;

  case 17: // g_any_expr: g_control_expr
#line 131 "parser.y"
                              {yylhs.value.as < GenieExpr > () = yystack_[0].value.as < GenieExpr > ();}
#line 1407 "Genie-Parser.cpp"
    break;

  case 18: // g_expr: INT
#line 133 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(GenieInt(yystack_[0].value.as < std::string > ())); }
#line 1413 "Genie-Parser.cpp"
    break;

  case 19: // g_expr: REAL
#line 134 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieReal(yystack_[0].value.as < std::string > ()));}
#line 1419 "Genie-Parser.cpp"
    break;

  case 20: // g_expr: g_expr PLUS g_expr
#line 135 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieBinaryExpr(yystack_[2].value.as < GenieExpr > (),yystack_[0].value.as < GenieExpr > (),GenieBinaryExpr::GenieBinaryOp::PLUS_OP)); }
#line 1425 "Genie-Parser.cpp"
    break;

  case 21: // g_expr: g_expr MINUS g_expr
#line 136 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieBinaryExpr(yystack_[2].value.as < GenieExpr > (),yystack_[0].value.as < GenieExpr > (),GenieBinaryExpr::GenieBinaryOp::MINUS_OP));}
#line 1431 "Genie-Parser.cpp"
    break;

  case 22: // g_expr: g_expr MULT g_expr
#line 137 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieBinaryExpr(yystack_[2].value.as < GenieExpr > (),yystack_[0].value.as < GenieExpr > (),GenieBinaryExpr::GenieBinaryOp::MULT_OP)); }
#line 1437 "Genie-Parser.cpp"
    break;

  case 23: // g_expr: g_expr DIV g_expr
#line 138 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieBinaryExpr(yystack_[2].value.as < GenieExpr > (),yystack_[0].value.as < GenieExpr > (),GenieBinaryExpr::GenieBinaryOp::DIV_OP));  }
#line 1443 "Genie-Parser.cpp"
    break;

  case 24: // g_expr: g_expr MOD g_expr
#line 139 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieBinaryExpr(yystack_[2].value.as < GenieExpr > (),yystack_[0].value.as < GenieExpr > (),GenieBinaryExpr::GenieBinaryOp::MOD_OP));  }
#line 1449 "Genie-Parser.cpp"
    break;

  case 25: // g_expr: g_expr EXP g_expr
#line 140 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieBinaryExpr(yystack_[2].value.as < GenieExpr > (),yystack_[0].value.as < GenieExpr > (),GenieBinaryExpr::GenieBinaryOp::EXP_OP));  }
#line 1455 "Genie-Parser.cpp"
    break;

  case 26: // g_expr: g_expr LESS_THAN g_expr
#line 141 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieBinaryExpr(yystack_[2].value.as < GenieExpr > (),yystack_[0].value.as < GenieExpr > (),GenieBinaryExpr::GenieBinaryOp::LT_OP));   }
#line 1461 "Genie-Parser.cpp"
    break;

  case 27: // g_expr: g_expr GREATER_THAN g_expr
#line 142 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieBinaryExpr(yystack_[2].value.as < GenieExpr > (),yystack_[0].value.as < GenieExpr > (),GenieBinaryExpr::GenieBinaryOp::GT_OP));   }
#line 1467 "Genie-Parser.cpp"
    break;

  case 28: // g_expr: g_expr LESS_THAN_EQ g_expr
#line 143 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieBinaryExpr(yystack_[2].value.as < GenieExpr > (),yystack_[0].value.as < GenieExpr > (),GenieBinaryExpr::GenieBinaryOp::LTE_OP));  }
#line 1473 "Genie-Parser.cpp"
    break;

  case 29: // g_expr: g_expr GREATER_THAN_EQ g_expr
#line 144 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieBinaryExpr(yystack_[2].value.as < GenieExpr > (),yystack_[0].value.as < GenieExpr > (),GenieBinaryExpr::GenieBinaryOp::GTE_OP));  }
#line 1479 "Genie-Parser.cpp"
    break;

  case 30: // g_expr: g_expr IS_EQUAL_TO g_expr
#line 145 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieBinaryExpr(yystack_[2].value.as < GenieExpr > (),yystack_[0].value.as < GenieExpr > (),GenieBinaryExpr::GenieBinaryOp::EQ_OP));   }
#line 1485 "Genie-Parser.cpp"
    break;

  case 31: // g_expr: g_expr IS_NOT_EQUAL_TO g_expr
#line 146 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieBinaryExpr(yystack_[2].value.as < GenieExpr > (),yystack_[0].value.as < GenieExpr > (),GenieBinaryExpr::GenieBinaryOp::NEQ_OP));  }
#line 1491 "Genie-Parser.cpp"
    break;

  case 32: // g_expr: g_expr OR g_expr
#line 147 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieBinaryExpr(yystack_[2].value.as < GenieExpr > (),yystack_[0].value.as < GenieExpr > (),GenieBinaryExpr::GenieBinaryOp::OR_OP));   }
#line 1497 "Genie-Parser.cpp"
    break;

  case 33: // g_expr: g_expr AND g_expr
#line 148 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieBinaryExpr(yystack_[2].value.as < GenieExpr > (),yystack_[0].value.as < GenieExpr > (),GenieBinaryExpr::GenieBinaryOp::AND_OP));  }
#line 1503 "Genie-Parser.cpp"
    break;

  case 34: // g_expr: NOT g_expr
#line 149 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieBinaryExpr(yystack_[0].value.as < GenieExpr > (),GenieBinaryExpr::GenieBinaryOp::NOT_OP));     }
#line 1509 "Genie-Parser.cpp"
    break;

  case 35: // g_expr: OPEN_PAREN g_expr CLOSED_PAREN
#line 150 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = yystack_[1].value.as < GenieExpr > ();}
#line 1515 "Genie-Parser.cpp"
    break;

  case 36: // g_expr: ID OPEN_SQ_BRACKET g_fun_call_args CLOSED_SQ_BRACKET
#line 153 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieFunCall(yystack_[3].value.as < std::string > (),yystack_[1].value.as < std::vector<GenieExpr> > ()));}
#line 1521 "Genie-Parser.cpp"
    break;

  case 37: // g_expr: ID
#line 154 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(yystack_[0].value.as < std::string > ());}
#line 1527 "Genie-Parser.cpp"
    break;

  case 38: // g_control_expr: SWITCH g_any_expr g_switch_body
#line 156 "parser.y"
                                                           {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieSwitch(yystack_[1].value.as < GenieExpr > (),yystack_[0].value.as < std::vector<GenieSwitch::GenieCase> > ()));}
#line 1533 "Genie-Parser.cpp"
    break;

  case 39: // g_control_expr: WHILE g_any_expr g_block
#line 157 "parser.y"
                                                           {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieWhile(yystack_[1].value.as < GenieExpr > (),yystack_[0].value.as < GenieBlock* > ()));}
#line 1539 "Genie-Parser.cpp"
    break;

  case 40: // g_control_expr: REP g_block UNTIL g_expression
#line 158 "parser.y"
                                                           {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieRepUntil(yystack_[0].value.as < GenieExpr > (),yystack_[2].value.as < GenieBlock* > ()));}
#line 1545 "Genie-Parser.cpp"
    break;

  case 41: // g_control_expr: FOR ID EQUAL g_for_var_decl g_block
#line 159 "parser.y"
                                                           {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieFor(yystack_[3].value.as < std::string > (),yystack_[1].value.as < std::vector<GenieExpr> > ()[0],yystack_[1].value.as < std::vector<GenieExpr> > ()[1],yystack_[1].value.as < std::vector<GenieExpr> > ()[2],yystack_[0].value.as < GenieBlock* > ()));}
#line 1551 "Genie-Parser.cpp"
    break;

  case 42: // g_control_expr: IF g_any_expr g_block g_optional_else
#line 160 "parser.y"
                                                           {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieIfElse(yystack_[2].value.as < GenieExpr > (),yystack_[1].value.as < GenieBlock* > (),yystack_[0].value.as < GenieBlock* > ()));}
#line 1557 "Genie-Parser.cpp"
    break;

  case 43: // g_return: RETURN g_expression
#line 165 "parser.y"
                               {yylhs.value.as < GenieRet* > () = new GenieRet(yystack_[0].value.as < GenieExpr > ());}
#line 1563 "Genie-Parser.cpp"
    break;

  case 44: // g_block: OPEN_CURLY g_module_elements CLOSED_CURLY
#line 170 "parser.y"
                                                    {yylhs.value.as < GenieBlock* > () = new GenieBlock(yystack_[1].value.as < std::vector<GenieModule::ModuleElem> > ());}
#line 1569 "Genie-Parser.cpp"
    break;

  case 45: // g_switch_body: OPEN_CURLY g_cases CLOSED_CURLY
#line 172 "parser.y"
                                                    {yylhs.value.as < std::vector<GenieSwitch::GenieCase> > () = yystack_[1].value.as < std::vector<GenieSwitch::GenieCase> > ();}
#line 1575 "Genie-Parser.cpp"
    break;

  case 46: // g_cases: %empty
#line 173 "parser.y"
                                                    {yylhs.value.as < std::vector<GenieSwitch::GenieCase> > () = std::vector<GenieSwitch::GenieCase>{};}
#line 1581 "Genie-Parser.cpp"
    break;

  case 47: // g_cases: g_cases g_case
#line 174 "parser.y"
                                                    {yylhs.value.as < std::vector<GenieSwitch::GenieCase> > () = yystack_[1].value.as < std::vector<GenieSwitch::GenieCase> > (); yylhs.value.as < std::vector<GenieSwitch::GenieCase> > ().push_back(yystack_[0].value.as < GenieSwitch::GenieCase > ());}
#line 1587 "Genie-Parser.cpp"
    break;

  case 48: // g_case: CASE g_any_expr g_block
#line 175 "parser.y"
                                                    {yylhs.value.as < GenieSwitch::GenieCase > () = GenieSwitch::GenieCase(yystack_[1].value.as < GenieExpr > (),yystack_[0].value.as < GenieBlock* > ());}
#line 1593 "Genie-Parser.cpp"
    break;

  case 49: // g_for_var_decl: g_any_expr COLON g_any_expr STEP g_any_expr
#line 177 "parser.y"
                                                             {yylhs.value.as < std::vector<GenieExpr> > () = std::vector<GenieExpr>{yystack_[4].value.as < GenieExpr > (),yystack_[2].value.as < GenieExpr > (),yystack_[0].value.as < GenieExpr > ()};}
#line 1599 "Genie-Parser.cpp"
    break;

  case 50: // g_optional_else: %empty
#line 179 "parser.y"
                                                    {yylhs.value.as < GenieBlock* > () = nullptr;}
#line 1605 "Genie-Parser.cpp"
    break;

  case 51: // g_optional_else: ELSE g_block
#line 180 "parser.y"
                                                    {yylhs.value.as < GenieBlock* > () = yystack_[0].value.as < GenieBlock* > ();}
#line 1611 "Genie-Parser.cpp"
    break;

  case 52: // g_assign: ID EQUAL g_expression
#line 185 "parser.y"
                                 {yylhs.value.as < GenieAssign* > () = new GenieAssign(yystack_[2].value.as < std::string > (),yystack_[0].value.as < GenieExpr > ());}
#line 1617 "Genie-Parser.cpp"
    break;

  case 53: // g_data_def: g_data_def_mut_spec ID g_optional_type_decl g_optional_init_expr G_EOL
#line 194 "parser.y"
                                                {yylhs.value.as < GenieData* > () = new GenieData(yystack_[4].value.as < GenieData::MutabilitySpecifier > (),yystack_[3].value.as < std::string > (),yystack_[2].value.as < std::string > (),yystack_[1].value.as < GenieExpr > ());}
#line 1623 "Genie-Parser.cpp"
    break;

  case 54: // g_data_def_mut_spec: VAR
#line 196 "parser.y"
                                                {yylhs.value.as < GenieData::MutabilitySpecifier > () = GenieData::MutabilitySpecifier::VAR;}
#line 1629 "Genie-Parser.cpp"
    break;

  case 55: // g_data_def_mut_spec: VAL
#line 197 "parser.y"
                                                {yylhs.value.as < GenieData::MutabilitySpecifier > () = GenieData::MutabilitySpecifier::VAL;}
#line 1635 "Genie-Parser.cpp"
    break;

  case 56: // g_optional_type_decl: %empty
#line 198 "parser.y"
                                                {yylhs.value.as < std::string > () = std::string("");}
#line 1641 "Genie-Parser.cpp"
    break;

  case 57: // g_optional_type_decl: g_type_decl
#line 199 "parser.y"
                                                {yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 1647 "Genie-Parser.cpp"
    break;

  case 58: // g_type_decl: COLON ID
#line 200 "parser.y"
                                                {yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 1653 "Genie-Parser.cpp"
    break;

  case 59: // g_optional_init_expr: %empty
#line 201 "parser.y"
                                                {yylhs.value.as < GenieExpr > () = GenieExpr();}
#line 1659 "Genie-Parser.cpp"
    break;

  case 60: // g_optional_init_expr: EQUAL g_expr
#line 202 "parser.y"
                                                {yylhs.value.as < GenieExpr > () = yystack_[0].value.as < GenieExpr > ();}
#line 1665 "Genie-Parser.cpp"
    break;

  case 61: // g_func_def: FUN ID g_optional_param_list g_optional_ret_type g_block
#line 207 "parser.y"
                                                                      {yylhs.value.as < GenieFunction* > () = new GenieFunction(yystack_[3].value.as < std::string > (),yystack_[2].value.as < std::vector<GenieFunction::FunctionParam> > (),yystack_[1].value.as < std::string > (),yystack_[0].value.as < GenieBlock* > ());}
#line 1671 "Genie-Parser.cpp"
    break;

  case 62: // g_optional_param_list: %empty
#line 209 "parser.y"
                                                       {yylhs.value.as < std::vector<GenieFunction::FunctionParam> > () = std::vector<GenieFunction::FunctionParam>{};}
#line 1677 "Genie-Parser.cpp"
    break;

  case 63: // g_optional_param_list: g_param_list
#line 210 "parser.y"
                                                       {yylhs.value.as < std::vector<GenieFunction::FunctionParam> > () = yystack_[0].value.as < std::vector<GenieFunction::FunctionParam> > ();}
#line 1683 "Genie-Parser.cpp"
    break;

  case 64: // g_param_list: g_param g_rest_of_param_list
#line 212 "parser.y"
                                                       {yylhs.value.as < std::vector<GenieFunction::FunctionParam> > () = std::vector<GenieFunction::FunctionParam>{yystack_[1].value.as < GenieFunction::FunctionParam > ()}; yylhs.value.as < std::vector<GenieFunction::FunctionParam> > ().insert(yylhs.value.as < std::vector<GenieFunction::FunctionParam> > ().end(),yystack_[0].value.as < std::vector<GenieFunction::FunctionParam> > ().begin(),yystack_[0].value.as < std::vector<GenieFunction::FunctionParam> > ().end());}
#line 1689 "Genie-Parser.cpp"
    break;

  case 65: // g_rest_of_param_list: %empty
#line 214 "parser.y"
                                                                {yylhs.value.as < std::vector<GenieFunction::FunctionParam> > () = std::vector<GenieFunction::FunctionParam>{};}
#line 1695 "Genie-Parser.cpp"
    break;

  case 66: // g_rest_of_param_list: g_param_end g_param g_rest_of_param_list
#line 215 "parser.y"
                                                                {yylhs.value.as < std::vector<GenieFunction::FunctionParam> > () = std::vector<GenieFunction::FunctionParam>{yystack_[1].value.as < GenieFunction::FunctionParam > ()}; yylhs.value.as < std::vector<GenieFunction::FunctionParam> > ().insert(yylhs.value.as < std::vector<GenieFunction::FunctionParam> > ().end(),yystack_[0].value.as < std::vector<GenieFunction::FunctionParam> > ().begin(),yystack_[0].value.as < std::vector<GenieFunction::FunctionParam> > ().end());}
#line 1701 "Genie-Parser.cpp"
    break;

  case 67: // g_param: ID g_optional_type_decl g_optional_init_expr
#line 217 "parser.y"
                                                       {yylhs.value.as < GenieFunction::FunctionParam > () = GenieFunction::FunctionParam(yystack_[2].value.as < std::string > (),yystack_[1].value.as < std::string > (),yystack_[0].value.as < GenieExpr > ());}
#line 1707 "Genie-Parser.cpp"
    break;

  case 68: // g_optional_ret_type: %empty
#line 219 "parser.y"
                                        {yylhs.value.as < std::string > () = "";}
#line 1713 "Genie-Parser.cpp"
    break;

  case 69: // g_optional_ret_type: RET_TYPE_MARK ID
#line 220 "parser.y"
                                        {yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 1719 "Genie-Parser.cpp"
    break;

  case 70: // g_param_end: G_EOL
#line 221 "parser.y"
                         {yylhs.value.as < char > () = ' ';}
#line 1725 "Genie-Parser.cpp"
    break;

  case 71: // g_param_end: COMMA
#line 222 "parser.y"
                         {yylhs.value.as < char > () = ' ';}
#line 1731 "Genie-Parser.cpp"
    break;

  case 72: // g_fun_call_args: %empty
#line 225 "parser.y"
                                                                         {yylhs.value.as < std::vector<GenieExpr> > () = std::vector<GenieExpr>{};}
#line 1737 "Genie-Parser.cpp"
    break;

  case 73: // g_fun_call_args: g_any_expr g_rest_of_fun_call_args
#line 226 "parser.y"
                                                                         {yylhs.value.as < std::vector<GenieExpr> > () = std::vector<GenieExpr>{yystack_[1].value.as < GenieExpr > ()}; yylhs.value.as < std::vector<GenieExpr> > ().insert(yylhs.value.as < std::vector<GenieExpr> > ().end(),yystack_[0].value.as < std::vector<GenieExpr> > ().begin(),yystack_[0].value.as < std::vector<GenieExpr> > ().end());}
#line 1743 "Genie-Parser.cpp"
    break;

  case 74: // g_rest_of_fun_call_args: %empty
#line 227 "parser.y"
                                                                         {yylhs.value.as < std::vector<GenieExpr> > () = std::vector<GenieExpr>{};}
#line 1749 "Genie-Parser.cpp"
    break;

  case 75: // g_rest_of_fun_call_args: g_param_end g_any_expr g_rest_of_fun_call_args
#line 228 "parser.y"
                                                                         {yylhs.value.as < std::vector<GenieExpr> > () = std::vector<GenieExpr>{yystack_[1].value.as < GenieExpr > ()};yylhs.value.as < std::vector<GenieExpr> > ().insert(yylhs.value.as < std::vector<GenieExpr> > ().end(),yystack_[0].value.as < std::vector<GenieExpr> > ().begin(),yystack_[0].value.as < std::vector<GenieExpr> > ().end());}
#line 1755 "Genie-Parser.cpp"
    break;

  case 76: // g_type_def: g_sum_type
#line 233 "parser.y"
                                                   {yylhs.value.as < GenieType* > () = new GenieType(yystack_[0].value.as < GenieType::SumType* > ());}
#line 1761 "Genie-Parser.cpp"
    break;

  case 77: // g_sum_type: SUM ID EQUAL g_variants
#line 234 "parser.y"
                                                   {yylhs.value.as < GenieType::SumType* > () = new GenieType::SumType(yystack_[2].value.as < std::string > (),yystack_[0].value.as < std::vector<std::string> > ());}
#line 1767 "Genie-Parser.cpp"
    break;

  case 78: // g_variants: ID g_more_variants
#line 235 "parser.y"
                                                   {yylhs.value.as < std::vector<std::string> > () = std::vector<std::string>{yystack_[1].value.as < std::string > ()}; yylhs.value.as < std::vector<std::string> > ().insert(yylhs.value.as < std::vector<std::string> > ().end(),yystack_[0].value.as < std::vector<std::string> > ().begin(),yystack_[0].value.as < std::vector<std::string> > ().end());}
#line 1773 "Genie-Parser.cpp"
    break;

  case 79: // g_more_variants: %empty
#line 236 "parser.y"
                                                   {yylhs.value.as < std::vector<std::string> > () = std::vector<std::string>{};}
#line 1779 "Genie-Parser.cpp"
    break;

  case 80: // g_more_variants: ALT ID g_more_variants G_EOL
#line 237 "parser.y"
                                                   {yylhs.value.as < std::vector<std::string> > () = std::vector<std::string>{yystack_[2].value.as < std::string > ()}; yylhs.value.as < std::vector<std::string> > ().insert(yylhs.value.as < std::vector<std::string> > ().end(),yystack_[1].value.as < std::vector<std::string> > ().begin(),yystack_[1].value.as < std::vector<std::string> > ().end());}
#line 1785 "Genie-Parser.cpp"
    break;


#line 1789 "Genie-Parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  GenieParser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  GenieParser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char GenieParser::yypact_ninf_ = -79;

  const signed char GenieParser::yytable_ninf_ = -3;

  const short
  GenieParser::yypact_[] =
  {
     -79,    10,    17,   -79,   199,     2,   -79,   -79,   -79,   -20,
     -19,   219,   219,   219,    13,   219,    -8,   -79,   -79,   -79,
      -7,     2,   -79,   -79,    79,   -79,   -79,   -79,   -79,   -79,
      -6,   -79,   -79,   -79,    12,   101,    14,    -2,    26,   -79,
      18,   146,   -79,    13,     1,    13,    27,   219,   219,    52,
       2,     2,     2,     2,     2,     2,   -79,     2,     2,     2,
       2,     2,     2,     2,     2,    29,   -79,   -79,    29,     4,
     -79,   -12,     8,   -79,   -79,   -79,   219,    19,   219,   -12,
      33,   -79,     7,     7,    42,    42,    42,    42,   154,    52,
     160,   160,   160,   160,   160,   160,    23,    35,   -79,    35,
      24,    13,   -79,   -79,   -79,    -2,    30,   -79,    -9,   -79,
      13,   -79,    47,    13,   219,   -79,   -79,   -79,     2,    54,
     -79,   -79,   -79,   -12,    51,   -79,   -79,   219,   -79,   -79,
     219,   -79,   -12,   146,   -79,   -79,    30,    13,    57,   -79,
      59,   -79,   219,   -79,   -79
  };

  const signed char
  GenieParser::yydefact_[] =
  {
       3,     0,     5,     1,     0,     0,     3,    54,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     6,    18,    19,
      37,     0,     4,     7,     0,    15,    13,     8,    12,     9,
       0,    10,    11,    76,    37,     0,     5,    62,     0,    43,
       0,    16,    17,     0,     0,     0,     0,    72,     0,    34,
       0,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,     0,     0,     0,     0,    56,    35,    44,    56,    68,
      63,    65,     0,    46,    38,    39,     0,    50,     0,    74,
       0,    52,    20,    21,    22,    23,    25,    24,    32,    33,
      26,    27,    28,    29,    30,    31,     0,    59,    57,    59,
       0,     0,    71,    70,    64,     0,    79,    77,     0,    40,
       0,    42,     0,     0,     0,    73,    36,    58,     0,     0,
      67,    69,    61,    65,     0,    78,    45,     0,    47,    51,
       0,    41,    74,    60,    53,    66,    79,     0,     0,    75,
       0,    48,     0,    80,    49
  };

  const signed char
  GenieParser::yypgoto_[] =
  {
     -79,   -79,    45,   -79,   -79,    -4,   -13,    16,     5,   -79,
     -10,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,    34,
     -79,    11,   -79,   -79,   -79,   -11,    15,   -79,   -78,   -79,
     -17,   -79,   -79,   -79,    -5
  };

  const unsigned char
  GenieParser::yydefgoto_[] =
  {
       0,     1,     2,     4,    22,    23,    40,    41,    42,    26,
      27,    74,   108,   128,   113,   111,    28,    29,    30,    97,
      98,   119,    31,    69,    70,   104,    71,   101,   105,    80,
     115,    32,    33,   107,   125
  };

  const short
  GenieParser::yytable_[] =
  {
      43,   114,    45,   126,    44,   102,    47,    39,    48,    25,
       3,     5,    52,    53,    54,    55,    25,    -2,    37,    38,
      24,    35,   103,   127,     6,    47,    67,    24,   100,    73,
      46,    76,    65,    75,    79,    77,    68,    49,    18,    19,
      34,    72,    78,    21,    81,    96,   106,   116,   110,    54,
     118,    36,   124,    25,   114,    50,    51,    52,    53,    54,
      55,   117,   121,   130,    24,   112,    82,    83,    84,    85,
      86,    87,   109,    88,    89,    90,    91,    92,    93,    94,
      95,    25,    50,    51,    52,    53,    54,    55,   134,   136,
     142,   122,    24,   143,    59,    60,    61,    62,    63,    64,
     129,   132,    99,   131,    50,    51,    52,    53,    54,    55,
     120,    66,   135,    56,   137,   139,     0,   138,    57,    58,
     123,    59,    60,    61,    62,    63,    64,   141,     0,   144,
       0,   140,     0,     0,   133,     0,     0,     0,     0,     0,
      57,    58,     0,    59,    60,    61,    62,    63,    64,    50,
      51,    52,    53,    54,    55,     0,     0,    50,    51,    52,
      53,    54,    55,    50,    51,    52,    53,    54,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    57,    58,     0,    59,    60,
      61,    62,    63,    64,    58,     0,    59,    60,    61,    62,
      63,    64,    -3,    -3,    -3,    -3,    -3,    -3,     5,     0,
       6,     0,     0,     0,     0,     0,     0,     7,     8,     9,
      10,     0,    11,     0,    12,    13,    14,    15,     5,     0,
      16,     0,     0,    17,     0,    18,    19,    20,     0,     0,
      21,     0,     0,     0,    12,    13,    14,    15,     0,     0,
      16,     0,     0,     0,     0,    18,    19,    34,     0,     0,
      21
  };

  const short
  GenieParser::yycheck_[] =
  {
      13,    79,    15,    12,    14,    17,    13,    11,    15,     4,
       0,     9,     5,     6,     7,     8,    11,     0,    38,    38,
       4,     5,    34,    32,    11,    13,    12,    11,    24,    11,
      38,    30,    38,    43,    47,    45,    38,    21,    36,    37,
      38,    15,    15,    41,    48,    16,    38,    14,    29,     7,
      15,     6,    22,    48,   132,     3,     4,     5,     6,     7,
       8,    38,    38,    16,    48,    78,    50,    51,    52,    53,
      54,    55,    76,    57,    58,    59,    60,    61,    62,    63,
      64,    76,     3,     4,     5,     6,     7,     8,    34,    38,
      33,   101,    76,    34,    42,    43,    44,    45,    46,    47,
     110,   114,    68,   113,     3,     4,     5,     6,     7,     8,
      99,    10,   123,    34,   127,   132,    -1,   130,    39,    40,
     105,    42,    43,    44,    45,    46,    47,   137,    -1,   142,
      -1,   136,    -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,
      39,    40,    -1,    42,    43,    44,    45,    46,    47,     3,
       4,     5,     6,     7,     8,    -1,    -1,     3,     4,     5,
       6,     7,     8,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    -1,    42,    43,
      44,    45,    46,    47,    40,    -1,    42,    43,    44,    45,
      46,    47,    42,    43,    44,    45,    46,    47,     9,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      21,    -1,    23,    -1,    25,    26,    27,    28,     9,    -1,
      31,    -1,    -1,    34,    -1,    36,    37,    38,    -1,    -1,
      41,    -1,    -1,    -1,    25,    26,    27,    28,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,    -1,
      41
  };

  const signed char
  GenieParser::yystos_[] =
  {
       0,    49,    50,     0,    51,     9,    11,    18,    19,    20,
      21,    23,    25,    26,    27,    28,    31,    34,    36,    37,
      38,    41,    52,    53,    55,    56,    57,    58,    64,    65,
      66,    70,    79,    80,    38,    55,    50,    38,    38,    53,
      54,    55,    56,    54,    58,    54,    38,    13,    15,    55,
       3,     4,     5,     6,     7,     8,    34,    39,    40,    42,
      43,    44,    45,    46,    47,    38,    10,    12,    38,    71,
      72,    74,    15,    11,    59,    58,    30,    58,    15,    54,
      77,    53,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    16,    67,    68,    67,
      24,    75,    17,    34,    73,    76,    38,    81,    60,    53,
      29,    63,    54,    62,    76,    78,    14,    38,    15,    69,
      69,    38,    58,    74,    22,    82,    12,    32,    61,    58,
      16,    58,    54,    55,    34,    73,    38,    54,    54,    78,
      82,    58,    33,    34,    54
  };

  const signed char
  GenieParser::yyr1_[] =
  {
       0,    48,    49,    50,    50,    51,    51,    52,    52,    52,
      52,    52,    52,    52,    53,    53,    54,    54,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    56,    56,
      56,    56,    56,    57,    58,    59,    60,    60,    61,    62,
      63,    63,    64,    65,    66,    66,    67,    67,    68,    69,
      69,    70,    71,    71,    72,    73,    73,    74,    75,    75,
      76,    76,    77,    77,    78,    78,    79,    80,    81,    82,
      82
  };

  const signed char
  GenieParser::yyr2_[] =
  {
       0,     2,     1,     0,     3,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     4,     1,     3,     3,
       4,     5,     4,     2,     3,     3,     0,     2,     3,     5,
       0,     2,     3,     5,     1,     1,     0,     1,     2,     0,
       2,     5,     0,     1,     2,     0,     3,     3,     0,     2,
       1,     1,     0,     2,     0,     3,     1,     4,     2,     0,
       4
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const GenieParser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "PLUS", "MINUS",
  "MULT", "DIV", "EXP", "MOD", "OPEN_PAREN", "CLOSED_PAREN", "OPEN_CURLY",
  "CLOSED_CURLY", "OPEN_SQ_BRACKET", "CLOSED_SQ_BRACKET", "EQUAL", "COLON",
  "COMMA", "VAR", "VAL", "FUN", "SUM", "ALT", "RETURN", "RET_TYPE_MARK",
  "SWITCH", "WHILE", "REP", "IF", "ELSE", "UNTIL", "FOR", "CASE", "STEP",
  "G_EOL", "UNKNOWN", "INT", "REAL", "ID", "OR", "AND", "NOT", "LESS_THAN",
  "GREATER_THAN", "LESS_THAN_EQ", "GREATER_THAN_EQ", "IS_EQUAL_TO",
  "IS_NOT_EQUAL_TO", "$accept", "g_source", "g_module_elements",
  "g_ignored_newlines", "g_module_element", "g_expression", "g_any_expr",
  "g_expr", "g_control_expr", "g_return", "g_block", "g_switch_body",
  "g_cases", "g_case", "g_for_var_decl", "g_optional_else", "g_assign",
  "g_data_def", "g_data_def_mut_spec", "g_optional_type_decl",
  "g_type_decl", "g_optional_init_expr", "g_func_def",
  "g_optional_param_list", "g_param_list", "g_rest_of_param_list",
  "g_param", "g_optional_ret_type", "g_param_end", "g_fun_call_args",
  "g_rest_of_fun_call_args", "g_type_def", "g_sum_type", "g_variants",
  "g_more_variants", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  GenieParser::yyrline_[] =
  {
       0,   109,   109,   111,   112,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   128,   129,   130,   131,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   154,   156,   157,
     158,   159,   160,   165,   170,   172,   173,   174,   175,   177,
     179,   180,   185,   190,   196,   197,   198,   199,   200,   201,
     202,   207,   209,   210,   212,   214,   215,   217,   219,   220,
     221,   222,   225,   226,   227,   228,   233,   234,   235,   236,
     237
  };

  void
  GenieParser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  GenieParser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  GenieParser::symbol_kind_type
  GenieParser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
    };
    // Last valid token kind.
    const int code_max = 302;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 20 "parser.y"
} // genie
#line 2280 "Genie-Parser.cpp"

#line 238 "parser.y"

void genie::GenieParser::error(const location_type& t,const std::string& msg) {
    std::cerr << msg <<" at line "<<t.begin.line<<'\n';
}
