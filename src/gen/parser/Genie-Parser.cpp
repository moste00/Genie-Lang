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
      case symbol_kind::S_g_block: // g_block
      case symbol_kind::S_g_switch_body: // g_switch_body
      case symbol_kind::S_g_cases: // g_cases
      case symbol_kind::S_g_case: // g_case
      case symbol_kind::S_g_for_var_decl: // g_for_var_decl
      case symbol_kind::S_g_optional_else: // g_optional_else
      case symbol_kind::S_g_assign: // g_assign
      case symbol_kind::S_g_fun_call_args: // g_fun_call_args
      case symbol_kind::S_g_rest_of_fun_call_args: // g_rest_of_fun_call_args
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

      case symbol_kind::S_g_type_def: // g_type_def
        value.copy< GenieType* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_sum_type: // g_sum_type
        value.copy< GenieType::SumType* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_param_end: // g_param_end
        value.copy< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_REAL: // REAL
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_g_optional_type_decl: // g_optional_type_decl
      case symbol_kind::S_g_type_decl: // g_type_decl
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_module_elements: // g_module_elements
        value.copy< std::vector<
            GenieModule::ModuleElem> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_optional_param_list: // g_optional_param_list
      case symbol_kind::S_g_param_list: // g_param_list
      case symbol_kind::S_g_rest_of_param_list: // g_rest_of_param_list
        value.copy< std::vector<GenieFunction::FunctionParam> > (YY_MOVE (that.value));
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
      case symbol_kind::S_g_block: // g_block
      case symbol_kind::S_g_switch_body: // g_switch_body
      case symbol_kind::S_g_cases: // g_cases
      case symbol_kind::S_g_case: // g_case
      case symbol_kind::S_g_for_var_decl: // g_for_var_decl
      case symbol_kind::S_g_optional_else: // g_optional_else
      case symbol_kind::S_g_assign: // g_assign
      case symbol_kind::S_g_fun_call_args: // g_fun_call_args
      case symbol_kind::S_g_rest_of_fun_call_args: // g_rest_of_fun_call_args
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

      case symbol_kind::S_g_type_def: // g_type_def
        value.move< GenieType* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_g_sum_type: // g_sum_type
        value.move< GenieType::SumType* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_g_param_end: // g_param_end
        value.move< char > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_REAL: // REAL
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_g_optional_type_decl: // g_optional_type_decl
      case symbol_kind::S_g_type_decl: // g_type_decl
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_g_module_elements: // g_module_elements
        value.move< std::vector<
            GenieModule::ModuleElem> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_g_optional_param_list: // g_optional_param_list
      case symbol_kind::S_g_param_list: // g_param_list
      case symbol_kind::S_g_rest_of_param_list: // g_rest_of_param_list
        value.move< std::vector<GenieFunction::FunctionParam> > (YY_MOVE (s.value));
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
      case symbol_kind::S_g_block: // g_block
      case symbol_kind::S_g_switch_body: // g_switch_body
      case symbol_kind::S_g_cases: // g_cases
      case symbol_kind::S_g_case: // g_case
      case symbol_kind::S_g_for_var_decl: // g_for_var_decl
      case symbol_kind::S_g_optional_else: // g_optional_else
      case symbol_kind::S_g_assign: // g_assign
      case symbol_kind::S_g_fun_call_args: // g_fun_call_args
      case symbol_kind::S_g_rest_of_fun_call_args: // g_rest_of_fun_call_args
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

      case symbol_kind::S_g_type_def: // g_type_def
        value.YY_MOVE_OR_COPY< GenieType* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_sum_type: // g_sum_type
        value.YY_MOVE_OR_COPY< GenieType::SumType* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_param_end: // g_param_end
        value.YY_MOVE_OR_COPY< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_REAL: // REAL
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_g_optional_type_decl: // g_optional_type_decl
      case symbol_kind::S_g_type_decl: // g_type_decl
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_module_elements: // g_module_elements
        value.YY_MOVE_OR_COPY< std::vector<
            GenieModule::ModuleElem> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_optional_param_list: // g_optional_param_list
      case symbol_kind::S_g_param_list: // g_param_list
      case symbol_kind::S_g_rest_of_param_list: // g_rest_of_param_list
        value.YY_MOVE_OR_COPY< std::vector<GenieFunction::FunctionParam> > (YY_MOVE (that.value));
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
      case symbol_kind::S_g_block: // g_block
      case symbol_kind::S_g_switch_body: // g_switch_body
      case symbol_kind::S_g_cases: // g_cases
      case symbol_kind::S_g_case: // g_case
      case symbol_kind::S_g_for_var_decl: // g_for_var_decl
      case symbol_kind::S_g_optional_else: // g_optional_else
      case symbol_kind::S_g_assign: // g_assign
      case symbol_kind::S_g_fun_call_args: // g_fun_call_args
      case symbol_kind::S_g_rest_of_fun_call_args: // g_rest_of_fun_call_args
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

      case symbol_kind::S_g_type_def: // g_type_def
        value.move< GenieType* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_sum_type: // g_sum_type
        value.move< GenieType::SumType* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_param_end: // g_param_end
        value.move< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_REAL: // REAL
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_g_optional_type_decl: // g_optional_type_decl
      case symbol_kind::S_g_type_decl: // g_type_decl
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_module_elements: // g_module_elements
        value.move< std::vector<
            GenieModule::ModuleElem> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_optional_param_list: // g_optional_param_list
      case symbol_kind::S_g_param_list: // g_param_list
      case symbol_kind::S_g_rest_of_param_list: // g_rest_of_param_list
        value.move< std::vector<GenieFunction::FunctionParam> > (YY_MOVE (that.value));
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
      case symbol_kind::S_g_block: // g_block
      case symbol_kind::S_g_switch_body: // g_switch_body
      case symbol_kind::S_g_cases: // g_cases
      case symbol_kind::S_g_case: // g_case
      case symbol_kind::S_g_for_var_decl: // g_for_var_decl
      case symbol_kind::S_g_optional_else: // g_optional_else
      case symbol_kind::S_g_assign: // g_assign
      case symbol_kind::S_g_fun_call_args: // g_fun_call_args
      case symbol_kind::S_g_rest_of_fun_call_args: // g_rest_of_fun_call_args
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

      case symbol_kind::S_g_type_def: // g_type_def
        value.copy< GenieType* > (that.value);
        break;

      case symbol_kind::S_g_sum_type: // g_sum_type
        value.copy< GenieType::SumType* > (that.value);
        break;

      case symbol_kind::S_g_param_end: // g_param_end
        value.copy< char > (that.value);
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_REAL: // REAL
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_g_optional_type_decl: // g_optional_type_decl
      case symbol_kind::S_g_type_decl: // g_type_decl
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_g_module_elements: // g_module_elements
        value.copy< std::vector<
            GenieModule::ModuleElem> > (that.value);
        break;

      case symbol_kind::S_g_optional_param_list: // g_optional_param_list
      case symbol_kind::S_g_param_list: // g_param_list
      case symbol_kind::S_g_rest_of_param_list: // g_rest_of_param_list
        value.copy< std::vector<GenieFunction::FunctionParam> > (that.value);
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
      case symbol_kind::S_g_block: // g_block
      case symbol_kind::S_g_switch_body: // g_switch_body
      case symbol_kind::S_g_cases: // g_cases
      case symbol_kind::S_g_case: // g_case
      case symbol_kind::S_g_for_var_decl: // g_for_var_decl
      case symbol_kind::S_g_optional_else: // g_optional_else
      case symbol_kind::S_g_assign: // g_assign
      case symbol_kind::S_g_fun_call_args: // g_fun_call_args
      case symbol_kind::S_g_rest_of_fun_call_args: // g_rest_of_fun_call_args
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

      case symbol_kind::S_g_type_def: // g_type_def
        value.move< GenieType* > (that.value);
        break;

      case symbol_kind::S_g_sum_type: // g_sum_type
        value.move< GenieType::SumType* > (that.value);
        break;

      case symbol_kind::S_g_param_end: // g_param_end
        value.move< char > (that.value);
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_REAL: // REAL
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_g_optional_type_decl: // g_optional_type_decl
      case symbol_kind::S_g_type_decl: // g_type_decl
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_g_module_elements: // g_module_elements
        value.move< std::vector<
            GenieModule::ModuleElem> > (that.value);
        break;

      case symbol_kind::S_g_optional_param_list: // g_optional_param_list
      case symbol_kind::S_g_param_list: // g_param_list
      case symbol_kind::S_g_rest_of_param_list: // g_rest_of_param_list
        value.move< std::vector<GenieFunction::FunctionParam> > (that.value);
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
      case symbol_kind::S_g_block: // g_block
      case symbol_kind::S_g_switch_body: // g_switch_body
      case symbol_kind::S_g_cases: // g_cases
      case symbol_kind::S_g_case: // g_case
      case symbol_kind::S_g_for_var_decl: // g_for_var_decl
      case symbol_kind::S_g_optional_else: // g_optional_else
      case symbol_kind::S_g_assign: // g_assign
      case symbol_kind::S_g_fun_call_args: // g_fun_call_args
      case symbol_kind::S_g_rest_of_fun_call_args: // g_rest_of_fun_call_args
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

      case symbol_kind::S_g_type_def: // g_type_def
        yylhs.value.emplace< GenieType* > ();
        break;

      case symbol_kind::S_g_sum_type: // g_sum_type
        yylhs.value.emplace< GenieType::SumType* > ();
        break;

      case symbol_kind::S_g_param_end: // g_param_end
        yylhs.value.emplace< char > ();
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_REAL: // REAL
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_g_optional_type_decl: // g_optional_type_decl
      case symbol_kind::S_g_type_decl: // g_type_decl
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_g_module_elements: // g_module_elements
        yylhs.value.emplace< std::vector<
            GenieModule::ModuleElem> > ();
        break;

      case symbol_kind::S_g_optional_param_list: // g_optional_param_list
      case symbol_kind::S_g_param_list: // g_param_list
      case symbol_kind::S_g_rest_of_param_list: // g_rest_of_param_list
        yylhs.value.emplace< std::vector<GenieFunction::FunctionParam> > ();
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
#line 92 "parser.y"
                                                        {yylhs.value.as < GenieModule* > () = new GenieModule(yystack_[0].value.as < std::vector<
            GenieModule::ModuleElem> > ()); mod = yylhs.value.as < GenieModule* > ();}
#line 1199 "Genie-Parser.cpp"
    break;

  case 3: // g_module_elements: %empty
#line 94 "parser.y"
                                                        {yylhs.value.as < std::vector<
            GenieModule::ModuleElem> > () = std::vector<GenieModule::ModuleElem>{};}
#line 1206 "Genie-Parser.cpp"
    break;

  case 4: // g_module_elements: g_module_elements g_module_element
#line 95 "parser.y"
                                                        {yylhs.value.as < std::vector<
            GenieModule::ModuleElem> > () = yystack_[1].value.as < std::vector<
            GenieModule::ModuleElem> > (); yylhs.value.as < std::vector<
            GenieModule::ModuleElem> > ().push_back(yystack_[0].value.as < GenieModule::ModuleElem > ());}
#line 1215 "Genie-Parser.cpp"
    break;

  case 5: // g_module_element: g_expression
#line 97 "parser.y"
                                {yylhs.value.as < GenieModule::ModuleElem > () = GenieModule::ModuleElem(yystack_[0].value.as < GenieExpr > ());}
#line 1221 "Genie-Parser.cpp"
    break;

  case 6: // g_module_element: g_block
#line 98 "parser.y"
                                {yylhs.value.as < GenieModule::ModuleElem > () = GenieModule::ModuleElem(yystack_[0].value.as < GenieBlock* > ());}
#line 1227 "Genie-Parser.cpp"
    break;

  case 7: // g_module_element: g_data_def
#line 99 "parser.y"
                                {yylhs.value.as < GenieModule::ModuleElem > () = GenieModule::ModuleElem(yystack_[0].value.as < GenieData* > ());}
#line 1233 "Genie-Parser.cpp"
    break;

  case 8: // g_module_element: g_func_def
#line 100 "parser.y"
                                {yylhs.value.as < GenieModule::ModuleElem > () = GenieModule::ModuleElem(yystack_[0].value.as < GenieFunction* > ());}
#line 1239 "Genie-Parser.cpp"
    break;

  case 9: // g_module_element: g_type_def
#line 101 "parser.y"
                                {yylhs.value.as < GenieModule::ModuleElem > () = GenieModule::ModuleElem(yystack_[0].value.as < GenieType* > ());}
#line 1245 "Genie-Parser.cpp"
    break;

  case 10: // g_module_element: g_assign
#line 102 "parser.y"
                                {yylhs.value.as < GenieModule::ModuleElem > () = GenieModule::ModuleElem();  }
#line 1251 "Genie-Parser.cpp"
    break;

  case 11: // g_expression: g_expr G_EOL
#line 103 "parser.y"
                              {yylhs.value.as < GenieExpr > () = yystack_[1].value.as < GenieExpr > ();}
#line 1257 "Genie-Parser.cpp"
    break;

  case 12: // g_expression: g_control_expr
#line 104 "parser.y"
                              {yylhs.value.as < GenieExpr > () = yystack_[0].value.as < GenieExpr > ();}
#line 1263 "Genie-Parser.cpp"
    break;

  case 13: // g_any_expr: g_expr
#line 105 "parser.y"
                              {yylhs.value.as < GenieExpr > () = yystack_[0].value.as < GenieExpr > ();}
#line 1269 "Genie-Parser.cpp"
    break;

  case 14: // g_any_expr: g_control_expr
#line 106 "parser.y"
                              {yylhs.value.as < GenieExpr > () = yystack_[0].value.as < GenieExpr > ();}
#line 1275 "Genie-Parser.cpp"
    break;

  case 15: // g_expr: INT
#line 108 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(GenieInt(yystack_[0].value.as < std::string > ()));}
#line 1281 "Genie-Parser.cpp"
    break;

  case 16: // g_expr: REAL
#line 109 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(); }
#line 1287 "Genie-Parser.cpp"
    break;

  case 17: // g_expr: g_expr PLUS g_expr
#line 110 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieBinaryExpr(yystack_[2].value.as < GenieExpr > (),yystack_[0].value.as < GenieExpr > (),GenieBinaryExpr::GenieBinaryOp::PLUS_OP));}
#line 1293 "Genie-Parser.cpp"
    break;

  case 18: // g_expr: g_expr MINUS g_expr
#line 111 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieBinaryExpr(yystack_[2].value.as < GenieExpr > (),yystack_[0].value.as < GenieExpr > (),GenieBinaryExpr::GenieBinaryOp::MINUS_OP)); }
#line 1299 "Genie-Parser.cpp"
    break;

  case 19: // g_expr: g_expr MULT g_expr
#line 112 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieBinaryExpr(yystack_[2].value.as < GenieExpr > (),yystack_[0].value.as < GenieExpr > (),GenieBinaryExpr::GenieBinaryOp::MULT_OP)); }
#line 1305 "Genie-Parser.cpp"
    break;

  case 20: // g_expr: g_expr DIV g_expr
#line 113 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieBinaryExpr(yystack_[2].value.as < GenieExpr > (),yystack_[0].value.as < GenieExpr > (),GenieBinaryExpr::GenieBinaryOp::DIV_OP));}
#line 1311 "Genie-Parser.cpp"
    break;

  case 21: // g_expr: g_expr MOD g_expr
#line 114 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieBinaryExpr(yystack_[2].value.as < GenieExpr > (),yystack_[0].value.as < GenieExpr > (),GenieBinaryExpr::GenieBinaryOp::MOD_OP));}
#line 1317 "Genie-Parser.cpp"
    break;

  case 22: // g_expr: g_expr EXP g_expr
#line 115 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieBinaryExpr(yystack_[2].value.as < GenieExpr > (),yystack_[0].value.as < GenieExpr > (),GenieBinaryExpr::GenieBinaryOp::EXP_OP));}
#line 1323 "Genie-Parser.cpp"
    break;

  case 23: // g_expr: g_expr LESS_THAN g_expr
#line 116 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(); }
#line 1329 "Genie-Parser.cpp"
    break;

  case 24: // g_expr: g_expr GREATER_THAN g_expr
#line 117 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(); }
#line 1335 "Genie-Parser.cpp"
    break;

  case 25: // g_expr: g_expr LESS_THAN_EQ g_expr
#line 118 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(); }
#line 1341 "Genie-Parser.cpp"
    break;

  case 26: // g_expr: g_expr GREATER_THAN_EQ g_expr
#line 119 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(); }
#line 1347 "Genie-Parser.cpp"
    break;

  case 27: // g_expr: g_expr IS_EQUAL_TO g_expr
#line 120 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(); }
#line 1353 "Genie-Parser.cpp"
    break;

  case 28: // g_expr: g_expr IS_NOT_EQUAL_TO g_expr
#line 121 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(); }
#line 1359 "Genie-Parser.cpp"
    break;

  case 29: // g_expr: g_expr OR g_expr
#line 122 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(); }
#line 1365 "Genie-Parser.cpp"
    break;

  case 30: // g_expr: g_expr AND g_expr
#line 123 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(); }
#line 1371 "Genie-Parser.cpp"
    break;

  case 31: // g_expr: NOT g_expr
#line 124 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(); }
#line 1377 "Genie-Parser.cpp"
    break;

  case 32: // g_expr: OPEN_PAREN g_expr CLOSED_PAREN
#line 125 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(); }
#line 1383 "Genie-Parser.cpp"
    break;

  case 33: // g_expr: ID OPEN_SQ_BRACKET g_fun_call_args CLOSED_SQ_BRACKET
#line 128 "parser.y"
                                       {yylhs.value.as < GenieExpr > () = GenieExpr(); }
#line 1389 "Genie-Parser.cpp"
    break;

  case 34: // g_expr: ID
#line 129 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = GenieExpr(yystack_[0].value.as < std::string > ());}
#line 1395 "Genie-Parser.cpp"
    break;

  case 35: // g_control_expr: SWITCH g_any_expr g_switch_body
#line 131 "parser.y"
                                                           {yylhs.value.as < GenieExpr > () = GenieExpr();}
#line 1401 "Genie-Parser.cpp"
    break;

  case 36: // g_control_expr: WHILE g_any_expr g_block
#line 132 "parser.y"
                                                           {yylhs.value.as < GenieExpr > () = GenieExpr();}
#line 1407 "Genie-Parser.cpp"
    break;

  case 37: // g_control_expr: REP g_block UNTIL g_expression
#line 133 "parser.y"
                                                           {yylhs.value.as < GenieExpr > () = GenieExpr();}
#line 1413 "Genie-Parser.cpp"
    break;

  case 38: // g_control_expr: FOR g_for_var_decl g_block
#line 134 "parser.y"
                                                           {yylhs.value.as < GenieExpr > () = GenieExpr();}
#line 1419 "Genie-Parser.cpp"
    break;

  case 39: // g_control_expr: IF g_any_expr g_block g_optional_else
#line 135 "parser.y"
                                                           {yylhs.value.as < GenieExpr > () = GenieExpr();}
#line 1425 "Genie-Parser.cpp"
    break;

  case 40: // g_block: OPEN_CURLY g_module_elements CLOSED_CURLY
#line 137 "parser.y"
                                                    {yylhs.value.as < GenieBlock* > () = new GenieBlock(yystack_[1].value.as < std::vector<
            GenieModule::ModuleElem> > ());}
#line 1432 "Genie-Parser.cpp"
    break;

  case 41: // g_switch_body: OPEN_CURLY g_cases CLOSED_CURLY
#line 139 "parser.y"
                                                    {yylhs.value.as < GenieBlock* > () = nullptr;}
#line 1438 "Genie-Parser.cpp"
    break;

  case 42: // g_cases: %empty
#line 140 "parser.y"
                                                    {yylhs.value.as < GenieBlock* > () = nullptr;}
#line 1444 "Genie-Parser.cpp"
    break;

  case 43: // g_cases: g_cases g_case
#line 141 "parser.y"
                                                    {yylhs.value.as < GenieBlock* > () = nullptr;}
#line 1450 "Genie-Parser.cpp"
    break;

  case 44: // g_case: CASE g_any_expr g_block
#line 142 "parser.y"
                                                    {yylhs.value.as < GenieBlock* > () = nullptr;}
#line 1456 "Genie-Parser.cpp"
    break;

  case 45: // g_for_var_decl: ID EQUAL g_any_expr COLON g_any_expr STEP g_any_expr
#line 144 "parser.y"
                                                                      {yylhs.value.as < GenieBlock* > () = nullptr;}
#line 1462 "Genie-Parser.cpp"
    break;

  case 46: // g_optional_else: %empty
#line 146 "parser.y"
                                                    {yylhs.value.as < GenieBlock* > () = nullptr;}
#line 1468 "Genie-Parser.cpp"
    break;

  case 47: // g_optional_else: ELSE g_block
#line 147 "parser.y"
                                                    {yylhs.value.as < GenieBlock* > () = nullptr;}
#line 1474 "Genie-Parser.cpp"
    break;

  case 48: // g_assign: ID EQUAL g_expression
#line 149 "parser.y"
                                 {yylhs.value.as < GenieBlock* > () = nullptr;}
#line 1480 "Genie-Parser.cpp"
    break;

  case 49: // g_data_def: g_data_def_mut_spec ID g_optional_type_decl g_optional_init_expr G_EOL
#line 156 "parser.y"
                                                {yylhs.value.as < GenieData* > () = new GenieData(yystack_[4].value.as < GenieData::MutabilitySpecifier > (),yystack_[3].value.as < std::string > (),yystack_[2].value.as < std::string > (),yystack_[1].value.as < GenieExpr > ());}
#line 1486 "Genie-Parser.cpp"
    break;

  case 50: // g_data_def_mut_spec: VAR
#line 158 "parser.y"
                                                {yylhs.value.as < GenieData::MutabilitySpecifier > () = GenieData::MutabilitySpecifier::VAR;}
#line 1492 "Genie-Parser.cpp"
    break;

  case 51: // g_data_def_mut_spec: VAL
#line 159 "parser.y"
                                                {yylhs.value.as < GenieData::MutabilitySpecifier > () = GenieData::MutabilitySpecifier::VAL;}
#line 1498 "Genie-Parser.cpp"
    break;

  case 52: // g_optional_type_decl: %empty
#line 160 "parser.y"
                                                {yylhs.value.as < std::string > () = std::string("");}
#line 1504 "Genie-Parser.cpp"
    break;

  case 53: // g_optional_type_decl: g_type_decl
#line 161 "parser.y"
                                                {yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 1510 "Genie-Parser.cpp"
    break;

  case 54: // g_type_decl: COLON ID
#line 162 "parser.y"
                                                {yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 1516 "Genie-Parser.cpp"
    break;

  case 55: // g_optional_init_expr: %empty
#line 163 "parser.y"
                                                {yylhs.value.as < GenieExpr > () = GenieExpr();}
#line 1522 "Genie-Parser.cpp"
    break;

  case 56: // g_optional_init_expr: EQUAL g_expr
#line 164 "parser.y"
                                                {yylhs.value.as < GenieExpr > () = yystack_[0].value.as < GenieExpr > ();}
#line 1528 "Genie-Parser.cpp"
    break;

  case 57: // g_func_def: FUN ID g_optional_param_list g_block
#line 166 "parser.y"
                                                  {yylhs.value.as < GenieFunction* > () = new GenieFunction(yystack_[2].value.as < std::string > (),yystack_[1].value.as < std::vector<GenieFunction::FunctionParam> > (),yystack_[0].value.as < GenieBlock* > ());}
#line 1534 "Genie-Parser.cpp"
    break;

  case 58: // g_optional_param_list: %empty
#line 168 "parser.y"
                                                       {yylhs.value.as < std::vector<GenieFunction::FunctionParam> > () = std::vector<GenieFunction::FunctionParam>{};}
#line 1540 "Genie-Parser.cpp"
    break;

  case 59: // g_optional_param_list: g_param_list
#line 169 "parser.y"
                                                       {yylhs.value.as < std::vector<GenieFunction::FunctionParam> > () = yystack_[0].value.as < std::vector<GenieFunction::FunctionParam> > ();}
#line 1546 "Genie-Parser.cpp"
    break;

  case 60: // g_param_list: g_param g_rest_of_param_list
#line 171 "parser.y"
                                                       {yylhs.value.as < std::vector<GenieFunction::FunctionParam> > () = std::vector<GenieFunction::FunctionParam>{yystack_[1].value.as < GenieFunction::FunctionParam > ()}; yylhs.value.as < std::vector<GenieFunction::FunctionParam> > ().insert(yylhs.value.as < std::vector<GenieFunction::FunctionParam> > ().end(),yystack_[0].value.as < std::vector<GenieFunction::FunctionParam> > ().begin(),yystack_[0].value.as < std::vector<GenieFunction::FunctionParam> > ().end());}
#line 1552 "Genie-Parser.cpp"
    break;

  case 61: // g_rest_of_param_list: %empty
#line 173 "parser.y"
                                                       {yylhs.value.as < std::vector<GenieFunction::FunctionParam> > () = std::vector<GenieFunction::FunctionParam>{};}
#line 1558 "Genie-Parser.cpp"
    break;

  case 62: // g_rest_of_param_list: g_param_end g_param g_rest_of_param_list
#line 174 "parser.y"
                                                                {yylhs.value.as < std::vector<GenieFunction::FunctionParam> > () = std::vector<GenieFunction::FunctionParam>{yystack_[1].value.as < GenieFunction::FunctionParam > ()}; yylhs.value.as < std::vector<GenieFunction::FunctionParam> > ().insert(yylhs.value.as < std::vector<GenieFunction::FunctionParam> > ().end(),yystack_[0].value.as < std::vector<GenieFunction::FunctionParam> > ().begin(),yystack_[0].value.as < std::vector<GenieFunction::FunctionParam> > ().end());}
#line 1564 "Genie-Parser.cpp"
    break;

  case 63: // g_param: ID g_optional_type_decl g_optional_init_expr
#line 176 "parser.y"
                                                       {yylhs.value.as < GenieFunction::FunctionParam > () = GenieFunction::FunctionParam(yystack_[2].value.as < std::string > (),yystack_[1].value.as < std::string > (),yystack_[0].value.as < GenieExpr > ());}
#line 1570 "Genie-Parser.cpp"
    break;

  case 64: // g_param_end: G_EOL
#line 178 "parser.y"
                         {yylhs.value.as < char > () = ' ';}
#line 1576 "Genie-Parser.cpp"
    break;

  case 65: // g_param_end: COMMA
#line 179 "parser.y"
                         {yylhs.value.as < char > () = ' ';}
#line 1582 "Genie-Parser.cpp"
    break;

  case 66: // g_fun_call_args: %empty
#line 180 "parser.y"
                                                          {yylhs.value.as < GenieBlock* > () = nullptr;}
#line 1588 "Genie-Parser.cpp"
    break;

  case 67: // g_fun_call_args: g_any_expr g_rest_of_fun_call_args
#line 181 "parser.y"
                                                      {yylhs.value.as < GenieBlock* > () = nullptr;}
#line 1594 "Genie-Parser.cpp"
    break;

  case 68: // g_rest_of_fun_call_args: %empty
#line 182 "parser.y"
                                                      {yylhs.value.as < GenieBlock* > () = nullptr;}
#line 1600 "Genie-Parser.cpp"
    break;

  case 69: // g_rest_of_fun_call_args: g_param_end g_any_expr g_rest_of_fun_call_args
#line 183 "parser.y"
                                                                         {yylhs.value.as < GenieBlock* > () = nullptr;}
#line 1606 "Genie-Parser.cpp"
    break;

  case 70: // g_type_def: g_sum_type
#line 184 "parser.y"
                                                   {yylhs.value.as < GenieType* > () = new GenieType(yystack_[0].value.as < GenieType::SumType* > ());}
#line 1612 "Genie-Parser.cpp"
    break;

  case 71: // g_sum_type: SUM ID EQUAL g_variants
#line 185 "parser.y"
                                                   {yylhs.value.as < GenieType::SumType* > () = new GenieType::SumType(yystack_[2].value.as < std::string > (),yystack_[0].value.as < std::vector<std::string> > ());}
#line 1618 "Genie-Parser.cpp"
    break;

  case 72: // g_variants: ID g_more_variants
#line 186 "parser.y"
                                                   {yylhs.value.as < std::vector<std::string> > () = std::vector<std::string>{yystack_[1].value.as < std::string > ()}; yylhs.value.as < std::vector<std::string> > ().insert(yylhs.value.as < std::vector<std::string> > ().end(),yystack_[0].value.as < std::vector<std::string> > ().begin(),yystack_[0].value.as < std::vector<std::string> > ().end());}
#line 1624 "Genie-Parser.cpp"
    break;

  case 73: // g_more_variants: %empty
#line 187 "parser.y"
                                                   {yylhs.value.as < std::vector<std::string> > () = std::vector<std::string>{};}
#line 1630 "Genie-Parser.cpp"
    break;

  case 74: // g_more_variants: ALT ID g_more_variants G_EOL
#line 188 "parser.y"
                                                   {yylhs.value.as < std::vector<std::string> > () = std::vector<std::string>{yystack_[2].value.as < std::string > ()}; yylhs.value.as < std::vector<std::string> > ().insert(yylhs.value.as < std::vector<std::string> > ().end(),yystack_[1].value.as < std::vector<std::string> > ().begin(),yystack_[1].value.as < std::vector<std::string> > ().end());}
#line 1636 "Genie-Parser.cpp"
    break;


#line 1640 "Genie-Parser.cpp"

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









  const signed char GenieParser::yypact_ninf_ = -76;

  const signed char GenieParser::yytable_ninf_ = -1;

  const short
  GenieParser::yypact_[] =
  {
     -76,     8,   241,   -76,    19,   -76,   -76,   -76,   -29,   -21,
     259,   259,     6,   259,   -18,   -76,   -76,     1,    19,   -76,
     -76,    96,   -76,   -76,   -76,   -76,   -15,   -76,   -76,   -76,
      11,   111,   219,   -10,    10,    16,   139,   -76,     6,     2,
       6,    20,     6,   259,   259,    40,    19,    19,    19,    19,
      19,    19,   -76,    19,    19,    19,    19,    19,    19,    19,
      19,    21,   -76,   -76,    21,     6,   -76,   -13,     4,   -76,
     -76,   -76,   259,    14,   259,   -76,   -13,    24,   -76,     5,
       5,    35,    35,    35,    35,   154,   162,   182,   182,   182,
     182,   182,   182,    23,    37,   -76,    37,   -76,   -76,   -76,
     -76,   -10,    38,   -76,    -7,   -76,     6,   -76,    41,   259,
     -76,   -76,   -76,    19,    29,   -76,   -13,    34,   -76,   -76,
     259,   -76,   -76,   259,   -13,   139,   -76,   -76,    38,     6,
      55,   -76,    56,   -76,   259,   -76,   -76
  };

  const signed char
  GenieParser::yydefact_[] =
  {
       3,     0,     2,     1,     0,     3,    50,    51,     0,     0,
       0,     0,     0,     0,     0,    15,    16,    34,     0,     4,
       5,     0,    12,     6,    10,     7,     0,     8,     9,    70,
      34,     0,     0,    58,     0,     0,    13,    14,     0,     0,
       0,     0,     0,    66,     0,    31,     0,     0,     0,     0,
       0,     0,    11,     0,     0,     0,     0,     0,     0,     0,
       0,    52,    32,    40,    52,     0,    59,    61,     0,    42,
      35,    36,     0,    46,     0,    38,    68,     0,    48,    17,
      18,    19,    20,    22,    21,    29,    30,    23,    24,    25,
      26,    27,    28,     0,    55,    53,    55,    57,    65,    64,
      60,     0,    73,    71,     0,    37,     0,    39,     0,     0,
      67,    33,    54,     0,     0,    63,    61,     0,    72,    41,
       0,    43,    47,     0,    68,    56,    49,    62,    73,     0,
       0,    69,     0,    44,     0,    74,    45
  };

  const signed char
  GenieParser::yypgoto_[] =
  {
     -76,   -76,    82,   -76,   -38,   -11,    18,     7,    -9,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,    25,   -76,    -5,
     -76,   -76,   -76,   -24,    -8,   -75,   -76,   -30,   -76,   -76,
     -76,   -33
  };

  const signed char
  GenieParser::yydefgoto_[] =
  {
       0,     1,     2,    19,    20,    35,    36,    37,    23,    70,
     104,   121,    42,   107,    24,    25,    26,    94,    95,   114,
      27,    65,    66,   100,    67,   101,    77,   110,    28,    29,
     103,   118
  };

  const short
  GenieParser::yytable_[] =
  {
      38,   109,    40,    39,    98,   119,    78,    33,     3,    22,
      48,    49,    50,    51,    43,    34,    44,     5,    41,    99,
      21,    61,    31,   120,    43,    68,    64,    69,     4,    71,
      72,    73,    76,    75,   105,    74,    45,    93,   111,    22,
     102,   106,    50,    46,    47,    48,    49,    50,    51,   109,
      21,    22,   113,    15,    16,    30,    97,   123,    18,   112,
     117,   126,    21,   108,    79,    80,    81,    82,    83,    84,
     128,    85,    86,    87,    88,    89,    90,    91,    92,    22,
      55,    56,    57,    58,    59,    60,   134,    32,   135,    96,
      21,   115,   127,   116,   131,   132,     0,   122,   124,    46,
      47,    48,    49,    50,    51,     0,     0,     0,     0,   129,
       0,     0,   130,     0,    46,    47,    48,    49,    50,    51,
     133,    62,     0,   136,     0,     0,     0,     0,    52,     0,
       0,   125,     0,    53,    54,     0,    55,    56,    57,    58,
      59,    60,    46,    47,    48,    49,    50,    51,    53,    54,
       0,    55,    56,    57,    58,    59,    60,    46,    47,    48,
      49,    50,    51,     0,     0,    46,    47,    48,    49,    50,
      51,     0,     0,     0,     0,     0,    53,    54,     0,    55,
      56,    57,    58,    59,    60,    46,    47,    48,    49,    50,
      51,    -1,    54,     0,    55,    56,    57,    58,    59,    60,
      -1,     0,    55,    56,    57,    58,    59,    60,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    -1,    -1,    -1,    -1,    -1,    -1,     4,     0,
       5,    63,     0,     0,     0,     0,     0,     6,     7,     8,
       9,     0,    10,    11,    12,    13,     0,     0,    14,     0,
       4,     0,     5,    15,    16,    17,     0,     0,    18,     6,
       7,     8,     9,     0,    10,    11,    12,    13,     4,     0,
      14,     0,     0,     0,     0,    15,    16,    17,     0,     0,
      18,     0,    10,    11,    12,    13,     0,     0,    14,     0,
       0,     0,     0,    15,    16,    30,     0,     0,    18
  };

  const short
  GenieParser::yycheck_[] =
  {
      11,    76,    13,    12,    17,    12,    44,    36,     0,     2,
       5,     6,     7,     8,    13,    36,    15,    11,    36,    32,
       2,    36,     4,    30,    13,    15,    36,    11,     9,    38,
      28,    40,    43,    42,    72,    15,    18,    16,    14,    32,
      36,    27,     7,     3,     4,     5,     6,     7,     8,   124,
      32,    44,    15,    34,    35,    36,    65,    16,    39,    36,
      22,    32,    44,    74,    46,    47,    48,    49,    50,    51,
      36,    53,    54,    55,    56,    57,    58,    59,    60,    72,
      40,    41,    42,    43,    44,    45,    31,     5,    32,    64,
      72,    96,   116,   101,   124,   128,    -1,   106,   109,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,   120,
      -1,    -1,   123,    -1,     3,     4,     5,     6,     7,     8,
     129,    10,    -1,   134,    -1,    -1,    -1,    -1,    32,    -1,
      -1,   113,    -1,    37,    38,    -1,    40,    41,    42,    43,
      44,    45,     3,     4,     5,     6,     7,     8,    37,    38,
      -1,    40,    41,    42,    43,    44,    45,     3,     4,     5,
       6,     7,     8,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,
      41,    42,    43,    44,    45,     3,     4,     5,     6,     7,
       8,    37,    38,    -1,    40,    41,    42,    43,    44,    45,
      38,    -1,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,     9,    -1,
      11,    12,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      21,    -1,    23,    24,    25,    26,    -1,    -1,    29,    -1,
       9,    -1,    11,    34,    35,    36,    -1,    -1,    39,    18,
      19,    20,    21,    -1,    23,    24,    25,    26,     9,    -1,
      29,    -1,    -1,    -1,    -1,    34,    35,    36,    -1,    -1,
      39,    -1,    23,    24,    25,    26,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    34,    35,    36,    -1,    -1,    39
  };

  const signed char
  GenieParser::yystos_[] =
  {
       0,    47,    48,     0,     9,    11,    18,    19,    20,    21,
      23,    24,    25,    26,    29,    34,    35,    36,    39,    49,
      50,    52,    53,    54,    60,    61,    62,    66,    74,    75,
      36,    52,    48,    36,    36,    51,    52,    53,    51,    54,
      51,    36,    58,    13,    15,    52,     3,     4,     5,     6,
       7,     8,    32,    37,    38,    40,    41,    42,    43,    44,
      45,    36,    10,    12,    36,    67,    68,    70,    15,    11,
      55,    54,    28,    54,    15,    54,    51,    72,    50,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    16,    63,    64,    63,    54,    17,    32,
      69,    71,    36,    76,    56,    50,    27,    59,    51,    71,
      73,    14,    36,    15,    65,    65,    70,    22,    77,    12,
      30,    57,    54,    16,    51,    52,    32,    69,    36,    51,
      51,    73,    77,    54,    31,    32,    51
  };

  const signed char
  GenieParser::yyr1_[] =
  {
       0,    46,    47,    48,    48,    49,    49,    49,    49,    49,
      49,    50,    50,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    53,    53,    53,    53,    53,
      54,    55,    56,    56,    57,    58,    59,    59,    60,    61,
      62,    62,    63,    63,    64,    65,    65,    66,    67,    67,
      68,    69,    69,    70,    71,    71,    72,    72,    73,    73,
      74,    75,    76,    77,    77
  };

  const signed char
  GenieParser::yyr2_[] =
  {
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     4,     1,     3,     3,     4,     3,     4,
       3,     3,     0,     2,     3,     7,     0,     2,     3,     5,
       1,     1,     0,     1,     2,     0,     2,     4,     0,     1,
       2,     0,     3,     3,     1,     1,     0,     2,     0,     3,
       1,     4,     2,     0,     4
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
  "COMMA", "VAR", "VAL", "FUN", "SUM", "ALT", "SWITCH", "WHILE", "REP",
  "IF", "ELSE", "UNTIL", "FOR", "CASE", "STEP", "G_EOL", "UNKNOWN", "INT",
  "REAL", "ID", "OR", "AND", "NOT", "LESS_THAN", "GREATER_THAN",
  "LESS_THAN_EQ", "GREATER_THAN_EQ", "IS_EQUAL_TO", "IS_NOT_EQUAL_TO",
  "$accept", "g_source", "g_module_elements", "g_module_element",
  "g_expression", "g_any_expr", "g_expr", "g_control_expr", "g_block",
  "g_switch_body", "g_cases", "g_case", "g_for_var_decl",
  "g_optional_else", "g_assign", "g_data_def", "g_data_def_mut_spec",
  "g_optional_type_decl", "g_type_decl", "g_optional_init_expr",
  "g_func_def", "g_optional_param_list", "g_param_list",
  "g_rest_of_param_list", "g_param", "g_param_end", "g_fun_call_args",
  "g_rest_of_fun_call_args", "g_type_def", "g_sum_type", "g_variants",
  "g_more_variants", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  GenieParser::yyrline_[] =
  {
       0,    92,    92,    94,    95,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   129,   131,   132,   133,   134,   135,
     137,   139,   140,   141,   142,   144,   146,   147,   149,   152,
     158,   159,   160,   161,   162,   163,   164,   166,   168,   169,
     171,   173,   174,   176,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188
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
      45
    };
    // Last valid token kind.
    const int code_max = 300;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 20 "parser.y"
} // genie
#line 2130 "Genie-Parser.cpp"

#line 189 "parser.y"

void genie::GenieParser::error(const location_type& t,const std::string& msg) {
    std::cerr << msg <<" at line "<<t.begin.line<<'\n';
}
