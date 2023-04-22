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

#line 17 "parser.y"
namespace genie {
#line 129 "Genie-Parser.cpp"

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
  {
    switch (this->kind ())
    {
      case symbol_kind::S_g_block: // g_block
        value.copy< GenieBlock* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_data_def: // g_data_def
        value.copy< GenieData* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_data_def_mut_spec: // g_data_def_mut_spec
        value.copy< GenieData::MutabilitySpecifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_optional_type_decl: // g_optional_type_decl
      case symbol_kind::S_g_type_decl: // g_type_decl
      case symbol_kind::S_g_type_ref_or_def: // g_type_ref_or_def
        value.copy< GenieData::TypeAnnotation > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_expression: // g_expression
      case symbol_kind::S_g_expr: // g_expr
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
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_module_elements: // g_module_elements
        value.copy< std::vector<
            GenieModule::ModuleElem> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_optional_param_list: // g_optional_param_list
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
        value.move< GenieBlock* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_g_data_def: // g_data_def
        value.move< GenieData* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_g_data_def_mut_spec: // g_data_def_mut_spec
        value.move< GenieData::MutabilitySpecifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_g_optional_type_decl: // g_optional_type_decl
      case symbol_kind::S_g_type_decl: // g_type_decl
      case symbol_kind::S_g_type_ref_or_def: // g_type_ref_or_def
        value.move< GenieData::TypeAnnotation > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_g_expression: // g_expression
      case symbol_kind::S_g_expr: // g_expr
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
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_g_module_elements: // g_module_elements
        value.move< std::vector<
            GenieModule::ModuleElem> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_g_optional_param_list: // g_optional_param_list
        value.move< std::vector<GenieFunction::FunctionParam> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_g_variants: // g_variants
      case symbol_kind::S_g_more_variants: // g_more_variants
        value.move< std::vector<std::string> > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

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
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_g_block: // g_block
        value.YY_MOVE_OR_COPY< GenieBlock* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_data_def: // g_data_def
        value.YY_MOVE_OR_COPY< GenieData* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_data_def_mut_spec: // g_data_def_mut_spec
        value.YY_MOVE_OR_COPY< GenieData::MutabilitySpecifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_optional_type_decl: // g_optional_type_decl
      case symbol_kind::S_g_type_decl: // g_type_decl
      case symbol_kind::S_g_type_ref_or_def: // g_type_ref_or_def
        value.YY_MOVE_OR_COPY< GenieData::TypeAnnotation > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_expression: // g_expression
      case symbol_kind::S_g_expr: // g_expr
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
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_module_elements: // g_module_elements
        value.YY_MOVE_OR_COPY< std::vector<
            GenieModule::ModuleElem> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_optional_param_list: // g_optional_param_list
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
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_g_block: // g_block
        value.move< GenieBlock* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_data_def: // g_data_def
        value.move< GenieData* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_data_def_mut_spec: // g_data_def_mut_spec
        value.move< GenieData::MutabilitySpecifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_optional_type_decl: // g_optional_type_decl
      case symbol_kind::S_g_type_decl: // g_type_decl
      case symbol_kind::S_g_type_ref_or_def: // g_type_ref_or_def
        value.move< GenieData::TypeAnnotation > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_expression: // g_expression
      case symbol_kind::S_g_expr: // g_expr
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
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_module_elements: // g_module_elements
        value.move< std::vector<
            GenieModule::ModuleElem> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_g_optional_param_list: // g_optional_param_list
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
        value.copy< GenieBlock* > (that.value);
        break;

      case symbol_kind::S_g_data_def: // g_data_def
        value.copy< GenieData* > (that.value);
        break;

      case symbol_kind::S_g_data_def_mut_spec: // g_data_def_mut_spec
        value.copy< GenieData::MutabilitySpecifier > (that.value);
        break;

      case symbol_kind::S_g_optional_type_decl: // g_optional_type_decl
      case symbol_kind::S_g_type_decl: // g_type_decl
      case symbol_kind::S_g_type_ref_or_def: // g_type_ref_or_def
        value.copy< GenieData::TypeAnnotation > (that.value);
        break;

      case symbol_kind::S_g_expression: // g_expression
      case symbol_kind::S_g_expr: // g_expr
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
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_g_module_elements: // g_module_elements
        value.copy< std::vector<
            GenieModule::ModuleElem> > (that.value);
        break;

      case symbol_kind::S_g_optional_param_list: // g_optional_param_list
        value.copy< std::vector<GenieFunction::FunctionParam> > (that.value);
        break;

      case symbol_kind::S_g_variants: // g_variants
      case symbol_kind::S_g_more_variants: // g_more_variants
        value.copy< std::vector<std::string> > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  GenieParser::stack_symbol_type&
  GenieParser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_g_block: // g_block
        value.move< GenieBlock* > (that.value);
        break;

      case symbol_kind::S_g_data_def: // g_data_def
        value.move< GenieData* > (that.value);
        break;

      case symbol_kind::S_g_data_def_mut_spec: // g_data_def_mut_spec
        value.move< GenieData::MutabilitySpecifier > (that.value);
        break;

      case symbol_kind::S_g_optional_type_decl: // g_optional_type_decl
      case symbol_kind::S_g_type_decl: // g_type_decl
      case symbol_kind::S_g_type_ref_or_def: // g_type_ref_or_def
        value.move< GenieData::TypeAnnotation > (that.value);
        break;

      case symbol_kind::S_g_expression: // g_expression
      case symbol_kind::S_g_expr: // g_expr
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
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_g_module_elements: // g_module_elements
        value.move< std::vector<
            GenieModule::ModuleElem> > (that.value);
        break;

      case symbol_kind::S_g_optional_param_list: // g_optional_param_list
        value.move< std::vector<GenieFunction::FunctionParam> > (that.value);
        break;

      case symbol_kind::S_g_variants: // g_variants
      case symbol_kind::S_g_more_variants: // g_more_variants
        value.move< std::vector<std::string> > (that.value);
        break;

      default:
        break;
    }

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
            << ' ' << yysym.name () << " (";
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
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, scanner, mod));
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
        yylhs.value.emplace< GenieBlock* > ();
        break;

      case symbol_kind::S_g_data_def: // g_data_def
        yylhs.value.emplace< GenieData* > ();
        break;

      case symbol_kind::S_g_data_def_mut_spec: // g_data_def_mut_spec
        yylhs.value.emplace< GenieData::MutabilitySpecifier > ();
        break;

      case symbol_kind::S_g_optional_type_decl: // g_optional_type_decl
      case symbol_kind::S_g_type_decl: // g_type_decl
      case symbol_kind::S_g_type_ref_or_def: // g_type_ref_or_def
        yylhs.value.emplace< GenieData::TypeAnnotation > ();
        break;

      case symbol_kind::S_g_expression: // g_expression
      case symbol_kind::S_g_expr: // g_expr
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
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_g_module_elements: // g_module_elements
        yylhs.value.emplace< std::vector<
            GenieModule::ModuleElem> > ();
        break;

      case symbol_kind::S_g_optional_param_list: // g_optional_param_list
        yylhs.value.emplace< std::vector<GenieFunction::FunctionParam> > ();
        break;

      case symbol_kind::S_g_variants: // g_variants
      case symbol_kind::S_g_more_variants: // g_more_variants
        yylhs.value.emplace< std::vector<std::string> > ();
        break;

      default:
        break;
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
#line 82 "parser.y"
                                                        {yylhs.value.as < GenieModule* > () = new GenieModule(yystack_[0].value.as < std::vector<
            GenieModule::ModuleElem> > ()); mod = yylhs.value.as < GenieModule* > ();}
#line 1110 "Genie-Parser.cpp"
    break;

  case 3: // g_module_elements: %empty
#line 84 "parser.y"
                                                        {yylhs.value.as < std::vector<
            GenieModule::ModuleElem> > () = std::vector<GenieModule::ModuleElem>{};}
#line 1117 "Genie-Parser.cpp"
    break;

  case 4: // g_module_elements: g_module_elements g_module_element
#line 85 "parser.y"
                                                        {yylhs.value.as < std::vector<
            GenieModule::ModuleElem> > () = yystack_[1].value.as < std::vector<
            GenieModule::ModuleElem> > (); yylhs.value.as < std::vector<
            GenieModule::ModuleElem> > ().push_back(yystack_[0].value.as < GenieModule::ModuleElem > ());}
#line 1126 "Genie-Parser.cpp"
    break;

  case 5: // g_module_element: g_expression
#line 87 "parser.y"
                                {yylhs.value.as < GenieModule::ModuleElem > () = GenieModule::ModuleElem(yystack_[0].value.as < GenieExpr > ());}
#line 1132 "Genie-Parser.cpp"
    break;

  case 6: // g_module_element: g_block
#line 88 "parser.y"
                                {yylhs.value.as < GenieModule::ModuleElem > () = GenieModule::ModuleElem(yystack_[0].value.as < GenieBlock* > ());}
#line 1138 "Genie-Parser.cpp"
    break;

  case 7: // g_module_element: g_data_def
#line 89 "parser.y"
                                {yylhs.value.as < GenieModule::ModuleElem > () = GenieModule::ModuleElem(yystack_[0].value.as < GenieData* > ());}
#line 1144 "Genie-Parser.cpp"
    break;

  case 8: // g_module_element: g_func_def
#line 90 "parser.y"
                                {yylhs.value.as < GenieModule::ModuleElem > () = GenieModule::ModuleElem(yystack_[0].value.as < GenieFunction* > ());}
#line 1150 "Genie-Parser.cpp"
    break;

  case 9: // g_module_element: g_type_def
#line 91 "parser.y"
                                {yylhs.value.as < GenieModule::ModuleElem > () = GenieModule::ModuleElem(yystack_[0].value.as < GenieType* > ());}
#line 1156 "Genie-Parser.cpp"
    break;

  case 10: // g_expression: g_expr G_EOL
#line 93 "parser.y"
                              {yylhs.value.as < GenieExpr > () = yystack_[1].value.as < GenieExpr > ();}
#line 1162 "Genie-Parser.cpp"
    break;

  case 11: // g_expr: INT
#line 95 "parser.y"
                              {yylhs.value.as < GenieExpr > () = GenieExpr(GenieInt(yystack_[0].value.as < std::string > ()));}
#line 1168 "Genie-Parser.cpp"
    break;

  case 12: // g_expr: REAL
#line 96 "parser.y"
                              {throw "UNIMPLEMENTED"; }
#line 1174 "Genie-Parser.cpp"
    break;

  case 13: // g_expr: g_expr PLUS g_expr
#line 97 "parser.y"
                              {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieBinaryExpr(yystack_[2].value.as < GenieExpr > (),yystack_[0].value.as < GenieExpr > (),GenieBinaryExpr::GenieBinaryOp::PLUS_OP));}
#line 1180 "Genie-Parser.cpp"
    break;

  case 14: // g_expr: g_expr MINUS g_expr
#line 98 "parser.y"
                              {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieBinaryExpr(yystack_[2].value.as < GenieExpr > (),yystack_[0].value.as < GenieExpr > (),GenieBinaryExpr::GenieBinaryOp::MINUS_OP)); }
#line 1186 "Genie-Parser.cpp"
    break;

  case 15: // g_expr: g_expr MULT g_expr
#line 99 "parser.y"
                              {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieBinaryExpr(yystack_[2].value.as < GenieExpr > (),yystack_[0].value.as < GenieExpr > (),GenieBinaryExpr::GenieBinaryOp::MULT_OP)); }
#line 1192 "Genie-Parser.cpp"
    break;

  case 16: // g_expr: g_expr DIV g_expr
#line 100 "parser.y"
                              {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieBinaryExpr(yystack_[2].value.as < GenieExpr > (),yystack_[0].value.as < GenieExpr > (),GenieBinaryExpr::GenieBinaryOp::DIV_OP));}
#line 1198 "Genie-Parser.cpp"
    break;

  case 17: // g_expr: g_expr MOD g_expr
#line 101 "parser.y"
                              {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieBinaryExpr(yystack_[2].value.as < GenieExpr > (),yystack_[0].value.as < GenieExpr > (),GenieBinaryExpr::GenieBinaryOp::MOD_OP));}
#line 1204 "Genie-Parser.cpp"
    break;

  case 18: // g_expr: g_expr EXP g_expr
#line 102 "parser.y"
                              {yylhs.value.as < GenieExpr > () = GenieExpr(new GenieBinaryExpr(yystack_[2].value.as < GenieExpr > (),yystack_[0].value.as < GenieExpr > (),GenieBinaryExpr::GenieBinaryOp::EXP_OP));}
#line 1210 "Genie-Parser.cpp"
    break;

  case 19: // g_expr: OPEN_PAREN g_expr CLOSED_PAREN
#line 103 "parser.y"
                                        {yylhs.value.as < GenieExpr > () = yystack_[1].value.as < GenieExpr > ();}
#line 1216 "Genie-Parser.cpp"
    break;

  case 20: // g_block: OPEN_CURLY g_module_elements CLOSED_CURLY
#line 105 "parser.y"
                                                    {yylhs.value.as < GenieBlock* > () = new GenieBlock(yystack_[1].value.as < std::vector<
            GenieModule::ModuleElem> > ());}
#line 1223 "Genie-Parser.cpp"
    break;

  case 21: // g_data_def: g_data_def_mut_spec ID g_optional_type_decl g_optional_init_expr G_EOL
#line 111 "parser.y"
                                                {yylhs.value.as < GenieData* > () = new GenieData(yystack_[4].value.as < GenieData::MutabilitySpecifier > (),yystack_[3].value.as < std::string > (),yystack_[2].value.as < GenieData::TypeAnnotation > (),yystack_[1].value.as < GenieExpr > ());}
#line 1229 "Genie-Parser.cpp"
    break;

  case 22: // g_data_def_mut_spec: VAR
#line 113 "parser.y"
                                                {yylhs.value.as < GenieData::MutabilitySpecifier > () = GenieData::MutabilitySpecifier::VAR;}
#line 1235 "Genie-Parser.cpp"
    break;

  case 23: // g_data_def_mut_spec: VAL
#line 114 "parser.y"
                                                {yylhs.value.as < GenieData::MutabilitySpecifier > () = GenieData::MutabilitySpecifier::VAL;}
#line 1241 "Genie-Parser.cpp"
    break;

  case 24: // g_optional_type_decl: %empty
#line 115 "parser.y"
                                                {yylhs.value.as < GenieData::TypeAnnotation > () = GenieData::TypeAnnotation(nullptr);}
#line 1247 "Genie-Parser.cpp"
    break;

  case 25: // g_optional_type_decl: g_type_decl
#line 116 "parser.y"
                                                {yylhs.value.as < GenieData::TypeAnnotation > () = yystack_[0].value.as < GenieData::TypeAnnotation > ();}
#line 1253 "Genie-Parser.cpp"
    break;

  case 26: // g_type_decl: COLON g_type_ref_or_def
#line 117 "parser.y"
                                                {yylhs.value.as < GenieData::TypeAnnotation > () = yystack_[0].value.as < GenieData::TypeAnnotation > ();}
#line 1259 "Genie-Parser.cpp"
    break;

  case 27: // g_type_ref_or_def: ID
#line 118 "parser.y"
                                                {yylhs.value.as < GenieData::TypeAnnotation > () = GenieData::TypeAnnotation(yystack_[0].value.as < std::string > ());}
#line 1265 "Genie-Parser.cpp"
    break;

  case 28: // g_type_ref_or_def: g_type_def
#line 119 "parser.y"
                                                {yylhs.value.as < GenieData::TypeAnnotation > () = GenieData::TypeAnnotation(yystack_[0].value.as < GenieType* > ());}
#line 1271 "Genie-Parser.cpp"
    break;

  case 29: // g_optional_init_expr: %empty
#line 120 "parser.y"
                                                {yylhs.value.as < GenieExpr > () = GenieExpr();}
#line 1277 "Genie-Parser.cpp"
    break;

  case 30: // g_optional_init_expr: EQUAL g_expression
#line 121 "parser.y"
                                                {yylhs.value.as < GenieExpr > () = yystack_[0].value.as < GenieExpr > ();}
#line 1283 "Genie-Parser.cpp"
    break;

  case 31: // g_func_def: FUN ID g_optional_param_list g_block
#line 123 "parser.y"
                                                  {yylhs.value.as < GenieFunction* > () = new GenieFunction(yystack_[2].value.as < std::string > (),yystack_[1].value.as < std::vector<GenieFunction::FunctionParam> > (),yystack_[0].value.as < GenieBlock* > ());}
#line 1289 "Genie-Parser.cpp"
    break;

  case 32: // g_optional_param_list: %empty
#line 125 "parser.y"
                                                       {yylhs.value.as < std::vector<GenieFunction::FunctionParam> > () = std::vector<GenieFunction::FunctionParam>{};}
#line 1295 "Genie-Parser.cpp"
    break;

  case 33: // g_optional_param_list: g_optional_param_list g_param
#line 126 "parser.y"
                                                       {yylhs.value.as < std::vector<GenieFunction::FunctionParam> > () = yystack_[1].value.as < std::vector<GenieFunction::FunctionParam> > (); yylhs.value.as < std::vector<GenieFunction::FunctionParam> > ().push_back(yystack_[0].value.as < GenieFunction::FunctionParam > ());}
#line 1301 "Genie-Parser.cpp"
    break;

  case 34: // g_param: ID g_optional_type_decl g_optional_init_expr g_param_end
#line 128 "parser.y"
                                                                   {yylhs.value.as < GenieFunction::FunctionParam > () = GenieFunction::FunctionParam(yystack_[3].value.as < std::string > (),yystack_[2].value.as < GenieData::TypeAnnotation > (),yystack_[1].value.as < GenieExpr > ());}
#line 1307 "Genie-Parser.cpp"
    break;

  case 35: // g_param_end: G_EOL
#line 130 "parser.y"
                         {yylhs.value.as < char > () = ' ';}
#line 1313 "Genie-Parser.cpp"
    break;

  case 36: // g_param_end: COMMA
#line 131 "parser.y"
                         {yylhs.value.as < char > () = ' ';}
#line 1319 "Genie-Parser.cpp"
    break;

  case 37: // g_type_def: g_sum_type
#line 133 "parser.y"
                                             {yylhs.value.as < GenieType* > () = new GenieType(yystack_[0].value.as < GenieType::SumType* > ());}
#line 1325 "Genie-Parser.cpp"
    break;

  case 38: // g_sum_type: SUM ID EQUAL g_variants
#line 134 "parser.y"
                                             {yylhs.value.as < GenieType::SumType* > () = new GenieType::SumType(yystack_[2].value.as < std::string > (),yystack_[0].value.as < std::vector<std::string> > ());}
#line 1331 "Genie-Parser.cpp"
    break;

  case 39: // g_variants: ID g_more_variants
#line 135 "parser.y"
                                             {yylhs.value.as < std::vector<std::string> > () = std::vector<std::string>{yystack_[1].value.as < std::string > ()}; yylhs.value.as < std::vector<std::string> > ().insert(yylhs.value.as < std::vector<std::string> > ().end(),yystack_[0].value.as < std::vector<std::string> > ().begin(),yystack_[0].value.as < std::vector<std::string> > ().end());}
#line 1337 "Genie-Parser.cpp"
    break;

  case 40: // g_more_variants: %empty
#line 136 "parser.y"
                                             {yylhs.value.as < std::vector<std::string> > () = std::vector<std::string>{};}
#line 1343 "Genie-Parser.cpp"
    break;

  case 41: // g_more_variants: ALT ID g_more_variants
#line 137 "parser.y"
                                             {yylhs.value.as < std::vector<std::string> > () = std::vector<std::string>{yystack_[1].value.as < std::string > ()}; yylhs.value.as < std::vector<std::string> > ().insert(yylhs.value.as < std::vector<std::string> > ().end(),yystack_[0].value.as < std::vector<std::string> > ().begin(),yystack_[0].value.as < std::vector<std::string> > ().end());}
#line 1349 "Genie-Parser.cpp"
    break;


#line 1353 "Genie-Parser.cpp"

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
        error (YY_MOVE (msg));
      }


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

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


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
    error (yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  GenieParser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char GenieParser::yypact_ninf_ = -10;

  const signed char GenieParser::yytable_ninf_ = -1;

  const signed char
  GenieParser::yypact_[] =
  {
     -10,     7,    29,   -10,     8,   -10,   -10,   -10,    -9,    -7,
     -10,   -10,   -10,   -10,    -2,   -10,   -10,    -5,   -10,   -10,
     -10,     5,    18,   -10,    31,     8,     8,     8,     8,     8,
       8,   -10,    36,   -10,   -10,     3,    26,    49,    49,    51,
      51,    51,    51,    14,    46,   -10,    36,   -10,   -10,    40,
     -10,   -10,   -10,   -10,     8,    41,    46,    38,   -10,   -10,
     -10,    28,    40,   -10,   -10,   -10,   -10
  };

  const signed char
  GenieParser::yydefact_[] =
  {
       3,     0,     2,     1,     0,     3,    22,    23,     0,     0,
      11,    12,     4,     5,     0,     6,     7,     0,     8,     9,
      37,     0,     0,    32,     0,     0,     0,     0,     0,     0,
       0,    10,    24,    19,    20,     0,     0,    13,    14,    15,
      16,    18,    17,     0,    29,    25,    24,    31,    33,    40,
      38,    27,    26,    28,     0,     0,    29,     0,    39,    30,
      21,     0,    40,    36,    35,    34,    41
  };

  const signed char
  GenieParser::yypgoto_[] =
  {
     -10,   -10,    56,   -10,    10,    -4,    30,   -10,   -10,    20,
     -10,   -10,    11,   -10,   -10,   -10,   -10,    25,   -10,   -10,
       9
  };

  const signed char
  GenieParser::yydefgoto_[] =
  {
       0,     1,     2,    12,    13,    14,    15,    16,    17,    44,
      45,    52,    55,    18,    35,    48,    65,    19,    20,    50,
      58
  };

  const signed char
  GenieParser::yytable_[] =
  {
      21,    25,    26,    27,    28,    29,    30,     3,    25,    26,
      27,    28,    29,    30,     5,    33,    23,     4,    24,    31,
      32,    37,    38,    39,    40,    41,    42,     4,    46,     5,
      34,    10,    11,     9,     6,     7,     8,     9,     4,    51,
       5,    10,    11,    63,    36,     6,     7,     8,     9,    64,
      43,    49,    10,    11,    27,    28,    29,    30,    29,    54,
      57,    22,    60,    62,    59,    47,    56,    61,    53,     0,
       0,    66
  };

  const signed char
  GenieParser::yycheck_[] =
  {
       4,     3,     4,     5,     6,     7,     8,     0,     3,     4,
       5,     6,     7,     8,    11,    10,    25,     9,    25,    21,
      25,    25,    26,    27,    28,    29,    30,     9,    25,    11,
      12,    23,    24,    19,    16,    17,    18,    19,     9,    25,
      11,    23,    24,    15,    13,    16,    17,    18,    19,    21,
      14,    25,    23,    24,     5,     6,     7,     8,     7,    13,
      20,     5,    21,    25,    54,    35,    46,    56,    43,    -1,
      -1,    62
  };

  const signed char
  GenieParser::yystos_[] =
  {
       0,    27,    28,     0,     9,    11,    16,    17,    18,    19,
      23,    24,    29,    30,    31,    32,    33,    34,    39,    43,
      44,    31,    28,    25,    25,     3,     4,     5,     6,     7,
       8,    21,    25,    10,    12,    40,    13,    31,    31,    31,
      31,    31,    31,    14,    35,    36,    25,    32,    41,    25,
      45,    25,    37,    43,    13,    38,    35,    20,    46,    30,
      21,    38,    25,    15,    21,    42,    46
  };

  const signed char
  GenieParser::yyr1_[] =
  {
       0,    26,    27,    28,    28,    29,    29,    29,    29,    29,
      30,    31,    31,    31,    31,    31,    31,    31,    31,    31,
      32,    33,    34,    34,    35,    35,    36,    37,    37,    38,
      38,    39,    40,    40,    41,    42,    42,    43,    44,    45,
      46,    46
  };

  const signed char
  GenieParser::yyr2_[] =
  {
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       2,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     5,     1,     1,     0,     1,     2,     1,     1,     0,
       2,     4,     0,     2,     4,     1,     1,     1,     4,     2,
       0,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const GenieParser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "PLUS", "MINUS",
  "MULT", "DIV", "EXP", "MOD", "OPEN_PAREN", "CLOSED_PAREN", "OPEN_CURLY",
  "CLOSED_CURLY", "EQUAL", "COLON", "COMMA", "VAR", "VAL", "FUN", "SUM",
  "ALT", "G_EOL", "UNKNOWN", "INT", "REAL", "ID", "$accept", "g_source",
  "g_module_elements", "g_module_element", "g_expression", "g_expr",
  "g_block", "g_data_def", "g_data_def_mut_spec", "g_optional_type_decl",
  "g_type_decl", "g_type_ref_or_def", "g_optional_init_expr", "g_func_def",
  "g_optional_param_list", "g_param", "g_param_end", "g_type_def",
  "g_sum_type", "g_variants", "g_more_variants", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  GenieParser::yyrline_[] =
  {
       0,    82,    82,    84,    85,    87,    88,    89,    90,    91,
      93,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     105,   107,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   123,   125,   126,   128,   130,   131,   133,   134,   135,
     136,   137
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
      25
    };
    // Last valid token kind.
    const int code_max = 280;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 17 "parser.y"
} // genie
#line 1754 "Genie-Parser.cpp"

#line 138 "parser.y"

void genie::GenieParser::error(const std::string& msg) {
    int line = yyget_lineno(scanner);
    std::cerr << msg <<" at line "<<line<<'\n';
}
