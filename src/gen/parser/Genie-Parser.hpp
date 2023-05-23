// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file Genie-Parser.hpp
 ** Define the genie::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_GENIE_PARSER_HPP_INCLUDED
# define YY_YY_GENIE_PARSER_HPP_INCLUDED
// "%code requires" blocks.
#line 25 "parser.y"

    #include "../../ast/Genie-Ast.hpp"

#line 53 "Genie-Parser.hpp"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

#line 20 "parser.y"
namespace genie {
#line 189 "Genie-Parser.hpp"




  /// A Bison parser.
  class GenieParser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
    {
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // g_assign
      char dummy1[sizeof (GenieAssign*)];

      // g_block
      // g_optional_else
      char dummy2[sizeof (GenieBlock*)];

      // g_data_def
      char dummy3[sizeof (GenieData*)];

      // g_data_def_mut_spec
      char dummy4[sizeof (GenieData::MutabilitySpecifier)];

      // g_expression
      // g_any_expr
      // g_expr
      // g_control_expr
      // g_optional_init_expr
      char dummy5[sizeof (GenieExpr)];

      // g_func_def
      char dummy6[sizeof (GenieFunction*)];

      // g_param
      char dummy7[sizeof (GenieFunction::FunctionParam)];

      // g_source
      char dummy8[sizeof (GenieModule*)];

      // g_module_element
      char dummy9[sizeof (GenieModule::ModuleElem)];

      // g_return
      char dummy10[sizeof (GenieRet*)];

      // g_case
      char dummy11[sizeof (GenieSwitch::GenieCase)];

      // g_type_def
      char dummy12[sizeof (GenieType*)];

      // g_sum_type
      char dummy13[sizeof (GenieType::SumType*)];

      // g_ignored_newlines
      // g_param_end
      char dummy14[sizeof (char)];

      // INT
      // REAL
      // ID
      // g_optional_type_decl
      // g_type_decl
      // g_optional_ret_type
      char dummy15[sizeof (std::string)];

      // g_for_var_decl
      // g_fun_call_args
      // g_rest_of_fun_call_args
      char dummy16[sizeof (std::vector<GenieExpr>)];

      // g_optional_param_list
      // g_param_list
      // g_rest_of_param_list
      char dummy17[sizeof (std::vector<GenieFunction::FunctionParam>)];

      // g_module_elements
      char dummy18[sizeof (std::vector<GenieModule::ModuleElem>)];

      // g_switch_body
      // g_cases
      char dummy19[sizeof (std::vector<GenieSwitch::GenieCase>)];

      // g_variants
      // g_more_variants
      char dummy20[sizeof (std::vector<std::string>)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;

    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    YYEOF = 0,                     // "end of file"
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    PLUS = 258,                    // PLUS
    MINUS = 259,                   // MINUS
    MULT = 260,                    // MULT
    DIV = 261,                     // DIV
    EXP = 262,                     // EXP
    MOD = 263,                     // MOD
    OPEN_PAREN = 264,              // OPEN_PAREN
    CLOSED_PAREN = 265,            // CLOSED_PAREN
    OPEN_CURLY = 266,              // OPEN_CURLY
    CLOSED_CURLY = 267,            // CLOSED_CURLY
    OPEN_SQ_BRACKET = 268,         // OPEN_SQ_BRACKET
    CLOSED_SQ_BRACKET = 269,       // CLOSED_SQ_BRACKET
    EQUAL = 270,                   // EQUAL
    COLON = 271,                   // COLON
    COMMA = 272,                   // COMMA
    VAR = 273,                     // VAR
    VAL = 274,                     // VAL
    FUN = 275,                     // FUN
    SUM = 276,                     // SUM
    ALT = 277,                     // ALT
    RETURN = 278,                  // RETURN
    RET_TYPE_MARK = 279,           // RET_TYPE_MARK
    SWITCH = 280,                  // SWITCH
    WHILE = 281,                   // WHILE
    REP = 282,                     // REP
    IF = 283,                      // IF
    ELSE = 284,                    // ELSE
    UNTIL = 285,                   // UNTIL
    FOR = 286,                     // FOR
    CASE = 287,                    // CASE
    STEP = 288,                    // STEP
    G_EOL = 289,                   // G_EOL
    UNKNOWN = 290,                 // UNKNOWN
    INT = 291,                     // INT
    REAL = 292,                    // REAL
    ID = 293,                      // ID
    OR = 294,                      // OR
    AND = 295,                     // AND
    NOT = 296,                     // NOT
    LESS_THAN = 297,               // LESS_THAN
    GREATER_THAN = 298,            // GREATER_THAN
    LESS_THAN_EQ = 299,            // LESS_THAN_EQ
    GREATER_THAN_EQ = 300,         // GREATER_THAN_EQ
    IS_EQUAL_TO = 301,             // IS_EQUAL_TO
    IS_NOT_EQUAL_TO = 302          // IS_NOT_EQUAL_TO
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 48, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_PLUS = 3,                              // PLUS
        S_MINUS = 4,                             // MINUS
        S_MULT = 5,                              // MULT
        S_DIV = 6,                               // DIV
        S_EXP = 7,                               // EXP
        S_MOD = 8,                               // MOD
        S_OPEN_PAREN = 9,                        // OPEN_PAREN
        S_CLOSED_PAREN = 10,                     // CLOSED_PAREN
        S_OPEN_CURLY = 11,                       // OPEN_CURLY
        S_CLOSED_CURLY = 12,                     // CLOSED_CURLY
        S_OPEN_SQ_BRACKET = 13,                  // OPEN_SQ_BRACKET
        S_CLOSED_SQ_BRACKET = 14,                // CLOSED_SQ_BRACKET
        S_EQUAL = 15,                            // EQUAL
        S_COLON = 16,                            // COLON
        S_COMMA = 17,                            // COMMA
        S_VAR = 18,                              // VAR
        S_VAL = 19,                              // VAL
        S_FUN = 20,                              // FUN
        S_SUM = 21,                              // SUM
        S_ALT = 22,                              // ALT
        S_RETURN = 23,                           // RETURN
        S_RET_TYPE_MARK = 24,                    // RET_TYPE_MARK
        S_SWITCH = 25,                           // SWITCH
        S_WHILE = 26,                            // WHILE
        S_REP = 27,                              // REP
        S_IF = 28,                               // IF
        S_ELSE = 29,                             // ELSE
        S_UNTIL = 30,                            // UNTIL
        S_FOR = 31,                              // FOR
        S_CASE = 32,                             // CASE
        S_STEP = 33,                             // STEP
        S_G_EOL = 34,                            // G_EOL
        S_UNKNOWN = 35,                          // UNKNOWN
        S_INT = 36,                              // INT
        S_REAL = 37,                             // REAL
        S_ID = 38,                               // ID
        S_OR = 39,                               // OR
        S_AND = 40,                              // AND
        S_NOT = 41,                              // NOT
        S_LESS_THAN = 42,                        // LESS_THAN
        S_GREATER_THAN = 43,                     // GREATER_THAN
        S_LESS_THAN_EQ = 44,                     // LESS_THAN_EQ
        S_GREATER_THAN_EQ = 45,                  // GREATER_THAN_EQ
        S_IS_EQUAL_TO = 46,                      // IS_EQUAL_TO
        S_IS_NOT_EQUAL_TO = 47,                  // IS_NOT_EQUAL_TO
        S_YYACCEPT = 48,                         // $accept
        S_g_source = 49,                         // g_source
        S_g_module_elements = 50,                // g_module_elements
        S_g_ignored_newlines = 51,               // g_ignored_newlines
        S_g_module_element = 52,                 // g_module_element
        S_g_expression = 53,                     // g_expression
        S_g_any_expr = 54,                       // g_any_expr
        S_g_expr = 55,                           // g_expr
        S_g_control_expr = 56,                   // g_control_expr
        S_g_return = 57,                         // g_return
        S_g_block = 58,                          // g_block
        S_g_switch_body = 59,                    // g_switch_body
        S_g_cases = 60,                          // g_cases
        S_g_case = 61,                           // g_case
        S_g_for_var_decl = 62,                   // g_for_var_decl
        S_g_optional_else = 63,                  // g_optional_else
        S_g_assign = 64,                         // g_assign
        S_g_data_def = 65,                       // g_data_def
        S_g_data_def_mut_spec = 66,              // g_data_def_mut_spec
        S_g_optional_type_decl = 67,             // g_optional_type_decl
        S_g_type_decl = 68,                      // g_type_decl
        S_g_optional_init_expr = 69,             // g_optional_init_expr
        S_g_func_def = 70,                       // g_func_def
        S_g_optional_param_list = 71,            // g_optional_param_list
        S_g_param_list = 72,                     // g_param_list
        S_g_rest_of_param_list = 73,             // g_rest_of_param_list
        S_g_param = 74,                          // g_param
        S_g_optional_ret_type = 75,              // g_optional_ret_type
        S_g_param_end = 76,                      // g_param_end
        S_g_fun_call_args = 77,                  // g_fun_call_args
        S_g_rest_of_fun_call_args = 78,          // g_rest_of_fun_call_args
        S_g_type_def = 79,                       // g_type_def
        S_g_sum_type = 80,                       // g_sum_type
        S_g_variants = 81,                       // g_variants
        S_g_more_variants = 82                   // g_more_variants
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_g_assign: // g_assign
        value.move< GenieAssign* > (std::move (that.value));
        break;

      case symbol_kind::S_g_block: // g_block
      case symbol_kind::S_g_optional_else: // g_optional_else
        value.move< GenieBlock* > (std::move (that.value));
        break;

      case symbol_kind::S_g_data_def: // g_data_def
        value.move< GenieData* > (std::move (that.value));
        break;

      case symbol_kind::S_g_data_def_mut_spec: // g_data_def_mut_spec
        value.move< GenieData::MutabilitySpecifier > (std::move (that.value));
        break;

      case symbol_kind::S_g_expression: // g_expression
      case symbol_kind::S_g_any_expr: // g_any_expr
      case symbol_kind::S_g_expr: // g_expr
      case symbol_kind::S_g_control_expr: // g_control_expr
      case symbol_kind::S_g_optional_init_expr: // g_optional_init_expr
        value.move< GenieExpr > (std::move (that.value));
        break;

      case symbol_kind::S_g_func_def: // g_func_def
        value.move< GenieFunction* > (std::move (that.value));
        break;

      case symbol_kind::S_g_param: // g_param
        value.move< GenieFunction::FunctionParam > (std::move (that.value));
        break;

      case symbol_kind::S_g_source: // g_source
        value.move< GenieModule* > (std::move (that.value));
        break;

      case symbol_kind::S_g_module_element: // g_module_element
        value.move< GenieModule::ModuleElem > (std::move (that.value));
        break;

      case symbol_kind::S_g_return: // g_return
        value.move< GenieRet* > (std::move (that.value));
        break;

      case symbol_kind::S_g_case: // g_case
        value.move< GenieSwitch::GenieCase > (std::move (that.value));
        break;

      case symbol_kind::S_g_type_def: // g_type_def
        value.move< GenieType* > (std::move (that.value));
        break;

      case symbol_kind::S_g_sum_type: // g_sum_type
        value.move< GenieType::SumType* > (std::move (that.value));
        break;

      case symbol_kind::S_g_ignored_newlines: // g_ignored_newlines
      case symbol_kind::S_g_param_end: // g_param_end
        value.move< char > (std::move (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_REAL: // REAL
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_g_optional_type_decl: // g_optional_type_decl
      case symbol_kind::S_g_type_decl: // g_type_decl
      case symbol_kind::S_g_optional_ret_type: // g_optional_ret_type
        value.move< std::string > (std::move (that.value));
        break;

      case symbol_kind::S_g_for_var_decl: // g_for_var_decl
      case symbol_kind::S_g_fun_call_args: // g_fun_call_args
      case symbol_kind::S_g_rest_of_fun_call_args: // g_rest_of_fun_call_args
        value.move< std::vector<GenieExpr> > (std::move (that.value));
        break;

      case symbol_kind::S_g_optional_param_list: // g_optional_param_list
      case symbol_kind::S_g_param_list: // g_param_list
      case symbol_kind::S_g_rest_of_param_list: // g_rest_of_param_list
        value.move< std::vector<GenieFunction::FunctionParam> > (std::move (that.value));
        break;

      case symbol_kind::S_g_module_elements: // g_module_elements
        value.move< std::vector<GenieModule::ModuleElem> > (std::move (that.value));
        break;

      case symbol_kind::S_g_switch_body: // g_switch_body
      case symbol_kind::S_g_cases: // g_cases
        value.move< std::vector<GenieSwitch::GenieCase> > (std::move (that.value));
        break;

      case symbol_kind::S_g_variants: // g_variants
      case symbol_kind::S_g_more_variants: // g_more_variants
        value.move< std::vector<std::string> > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, GenieAssign*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const GenieAssign*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, GenieBlock*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const GenieBlock*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, GenieData*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const GenieData*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, GenieData::MutabilitySpecifier&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const GenieData::MutabilitySpecifier& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, GenieExpr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const GenieExpr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, GenieFunction*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const GenieFunction*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, GenieFunction::FunctionParam&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const GenieFunction::FunctionParam& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, GenieModule*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const GenieModule*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, GenieModule::ModuleElem&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const GenieModule::ModuleElem& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, GenieRet*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const GenieRet*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, GenieSwitch::GenieCase&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const GenieSwitch::GenieCase& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, GenieType*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const GenieType*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, GenieType::SumType*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const GenieType::SumType*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, char&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const char& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<GenieExpr>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<GenieExpr>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<GenieFunction::FunctionParam>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<GenieFunction::FunctionParam>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<GenieModule::ModuleElem>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<GenieModule::ModuleElem>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<GenieSwitch::GenieCase>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<GenieSwitch::GenieCase>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<std::string>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<std::string>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_g_assign: // g_assign
        value.template destroy< GenieAssign* > ();
        break;

      case symbol_kind::S_g_block: // g_block
      case symbol_kind::S_g_optional_else: // g_optional_else
        value.template destroy< GenieBlock* > ();
        break;

      case symbol_kind::S_g_data_def: // g_data_def
        value.template destroy< GenieData* > ();
        break;

      case symbol_kind::S_g_data_def_mut_spec: // g_data_def_mut_spec
        value.template destroy< GenieData::MutabilitySpecifier > ();
        break;

      case symbol_kind::S_g_expression: // g_expression
      case symbol_kind::S_g_any_expr: // g_any_expr
      case symbol_kind::S_g_expr: // g_expr
      case symbol_kind::S_g_control_expr: // g_control_expr
      case symbol_kind::S_g_optional_init_expr: // g_optional_init_expr
        value.template destroy< GenieExpr > ();
        break;

      case symbol_kind::S_g_func_def: // g_func_def
        value.template destroy< GenieFunction* > ();
        break;

      case symbol_kind::S_g_param: // g_param
        value.template destroy< GenieFunction::FunctionParam > ();
        break;

      case symbol_kind::S_g_source: // g_source
        value.template destroy< GenieModule* > ();
        break;

      case symbol_kind::S_g_module_element: // g_module_element
        value.template destroy< GenieModule::ModuleElem > ();
        break;

      case symbol_kind::S_g_return: // g_return
        value.template destroy< GenieRet* > ();
        break;

      case symbol_kind::S_g_case: // g_case
        value.template destroy< GenieSwitch::GenieCase > ();
        break;

      case symbol_kind::S_g_type_def: // g_type_def
        value.template destroy< GenieType* > ();
        break;

      case symbol_kind::S_g_sum_type: // g_sum_type
        value.template destroy< GenieType::SumType* > ();
        break;

      case symbol_kind::S_g_ignored_newlines: // g_ignored_newlines
      case symbol_kind::S_g_param_end: // g_param_end
        value.template destroy< char > ();
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_REAL: // REAL
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_g_optional_type_decl: // g_optional_type_decl
      case symbol_kind::S_g_type_decl: // g_type_decl
      case symbol_kind::S_g_optional_ret_type: // g_optional_ret_type
        value.template destroy< std::string > ();
        break;

      case symbol_kind::S_g_for_var_decl: // g_for_var_decl
      case symbol_kind::S_g_fun_call_args: // g_fun_call_args
      case symbol_kind::S_g_rest_of_fun_call_args: // g_rest_of_fun_call_args
        value.template destroy< std::vector<GenieExpr> > ();
        break;

      case symbol_kind::S_g_optional_param_list: // g_optional_param_list
      case symbol_kind::S_g_param_list: // g_param_list
      case symbol_kind::S_g_rest_of_param_list: // g_rest_of_param_list
        value.template destroy< std::vector<GenieFunction::FunctionParam> > ();
        break;

      case symbol_kind::S_g_module_elements: // g_module_elements
        value.template destroy< std::vector<GenieModule::ModuleElem> > ();
        break;

      case symbol_kind::S_g_switch_body: // g_switch_body
      case symbol_kind::S_g_cases: // g_cases
        value.template destroy< std::vector<GenieSwitch::GenieCase> > ();
        break;

      case symbol_kind::S_g_variants: // g_variants
      case symbol_kind::S_g_more_variants: // g_more_variants
        value.template destroy< std::vector<std::string> > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

#if YYDEBUG || 0
      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return GenieParser::symbol_name (this->kind ());
      }
#endif // #if YYDEBUG || 0


      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type (token_kind_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type (token_kind_type (tok), l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {}
    };

    /// Build a parser object.
    GenieParser (yyscan_t scanner_yyarg, GenieModule*& mod_yyarg);
    virtual ~GenieParser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    GenieParser (const GenieParser&) = delete;
    /// Non copyable.
    GenieParser& operator= (const GenieParser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

#if YYDEBUG || 0
    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);
#endif // #if YYDEBUG || 0


    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF (location_type l)
      {
        return symbol_type (token::YYEOF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYEOF (const location_type& l)
      {
        return symbol_type (token::YYEOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS (location_type l)
      {
        return symbol_type (token::PLUS, std::move (l));
      }
#else
      static
      symbol_type
      make_PLUS (const location_type& l)
      {
        return symbol_type (token::PLUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS (location_type l)
      {
        return symbol_type (token::MINUS, std::move (l));
      }
#else
      static
      symbol_type
      make_MINUS (const location_type& l)
      {
        return symbol_type (token::MINUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MULT (location_type l)
      {
        return symbol_type (token::MULT, std::move (l));
      }
#else
      static
      symbol_type
      make_MULT (const location_type& l)
      {
        return symbol_type (token::MULT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIV (location_type l)
      {
        return symbol_type (token::DIV, std::move (l));
      }
#else
      static
      symbol_type
      make_DIV (const location_type& l)
      {
        return symbol_type (token::DIV, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXP (location_type l)
      {
        return symbol_type (token::EXP, std::move (l));
      }
#else
      static
      symbol_type
      make_EXP (const location_type& l)
      {
        return symbol_type (token::EXP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOD (location_type l)
      {
        return symbol_type (token::MOD, std::move (l));
      }
#else
      static
      symbol_type
      make_MOD (const location_type& l)
      {
        return symbol_type (token::MOD, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPEN_PAREN (location_type l)
      {
        return symbol_type (token::OPEN_PAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_OPEN_PAREN (const location_type& l)
      {
        return symbol_type (token::OPEN_PAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CLOSED_PAREN (location_type l)
      {
        return symbol_type (token::CLOSED_PAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_CLOSED_PAREN (const location_type& l)
      {
        return symbol_type (token::CLOSED_PAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPEN_CURLY (location_type l)
      {
        return symbol_type (token::OPEN_CURLY, std::move (l));
      }
#else
      static
      symbol_type
      make_OPEN_CURLY (const location_type& l)
      {
        return symbol_type (token::OPEN_CURLY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CLOSED_CURLY (location_type l)
      {
        return symbol_type (token::CLOSED_CURLY, std::move (l));
      }
#else
      static
      symbol_type
      make_CLOSED_CURLY (const location_type& l)
      {
        return symbol_type (token::CLOSED_CURLY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPEN_SQ_BRACKET (location_type l)
      {
        return symbol_type (token::OPEN_SQ_BRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_OPEN_SQ_BRACKET (const location_type& l)
      {
        return symbol_type (token::OPEN_SQ_BRACKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CLOSED_SQ_BRACKET (location_type l)
      {
        return symbol_type (token::CLOSED_SQ_BRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_CLOSED_SQ_BRACKET (const location_type& l)
      {
        return symbol_type (token::CLOSED_SQ_BRACKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQUAL (location_type l)
      {
        return symbol_type (token::EQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_EQUAL (const location_type& l)
      {
        return symbol_type (token::EQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLON (location_type l)
      {
        return symbol_type (token::COLON, std::move (l));
      }
#else
      static
      symbol_type
      make_COLON (const location_type& l)
      {
        return symbol_type (token::COLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (location_type l)
      {
        return symbol_type (token::COMMA, std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const location_type& l)
      {
        return symbol_type (token::COMMA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VAR (location_type l)
      {
        return symbol_type (token::VAR, std::move (l));
      }
#else
      static
      symbol_type
      make_VAR (const location_type& l)
      {
        return symbol_type (token::VAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VAL (location_type l)
      {
        return symbol_type (token::VAL, std::move (l));
      }
#else
      static
      symbol_type
      make_VAL (const location_type& l)
      {
        return symbol_type (token::VAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FUN (location_type l)
      {
        return symbol_type (token::FUN, std::move (l));
      }
#else
      static
      symbol_type
      make_FUN (const location_type& l)
      {
        return symbol_type (token::FUN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUM (location_type l)
      {
        return symbol_type (token::SUM, std::move (l));
      }
#else
      static
      symbol_type
      make_SUM (const location_type& l)
      {
        return symbol_type (token::SUM, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ALT (location_type l)
      {
        return symbol_type (token::ALT, std::move (l));
      }
#else
      static
      symbol_type
      make_ALT (const location_type& l)
      {
        return symbol_type (token::ALT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RETURN (location_type l)
      {
        return symbol_type (token::RETURN, std::move (l));
      }
#else
      static
      symbol_type
      make_RETURN (const location_type& l)
      {
        return symbol_type (token::RETURN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RET_TYPE_MARK (location_type l)
      {
        return symbol_type (token::RET_TYPE_MARK, std::move (l));
      }
#else
      static
      symbol_type
      make_RET_TYPE_MARK (const location_type& l)
      {
        return symbol_type (token::RET_TYPE_MARK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SWITCH (location_type l)
      {
        return symbol_type (token::SWITCH, std::move (l));
      }
#else
      static
      symbol_type
      make_SWITCH (const location_type& l)
      {
        return symbol_type (token::SWITCH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILE (location_type l)
      {
        return symbol_type (token::WHILE, std::move (l));
      }
#else
      static
      symbol_type
      make_WHILE (const location_type& l)
      {
        return symbol_type (token::WHILE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REP (location_type l)
      {
        return symbol_type (token::REP, std::move (l));
      }
#else
      static
      symbol_type
      make_REP (const location_type& l)
      {
        return symbol_type (token::REP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF (location_type l)
      {
        return symbol_type (token::IF, std::move (l));
      }
#else
      static
      symbol_type
      make_IF (const location_type& l)
      {
        return symbol_type (token::IF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE (location_type l)
      {
        return symbol_type (token::ELSE, std::move (l));
      }
#else
      static
      symbol_type
      make_ELSE (const location_type& l)
      {
        return symbol_type (token::ELSE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNTIL (location_type l)
      {
        return symbol_type (token::UNTIL, std::move (l));
      }
#else
      static
      symbol_type
      make_UNTIL (const location_type& l)
      {
        return symbol_type (token::UNTIL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FOR (location_type l)
      {
        return symbol_type (token::FOR, std::move (l));
      }
#else
      static
      symbol_type
      make_FOR (const location_type& l)
      {
        return symbol_type (token::FOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CASE (location_type l)
      {
        return symbol_type (token::CASE, std::move (l));
      }
#else
      static
      symbol_type
      make_CASE (const location_type& l)
      {
        return symbol_type (token::CASE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STEP (location_type l)
      {
        return symbol_type (token::STEP, std::move (l));
      }
#else
      static
      symbol_type
      make_STEP (const location_type& l)
      {
        return symbol_type (token::STEP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_G_EOL (location_type l)
      {
        return symbol_type (token::G_EOL, std::move (l));
      }
#else
      static
      symbol_type
      make_G_EOL (const location_type& l)
      {
        return symbol_type (token::G_EOL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNKNOWN (location_type l)
      {
        return symbol_type (token::UNKNOWN, std::move (l));
      }
#else
      static
      symbol_type
      make_UNKNOWN (const location_type& l)
      {
        return symbol_type (token::UNKNOWN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT (std::string v, location_type l)
      {
        return symbol_type (token::INT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::INT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REAL (std::string v, location_type l)
      {
        return symbol_type (token::REAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_REAL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::REAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ID (std::string v, location_type l)
      {
        return symbol_type (token::ID, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ID (const std::string& v, const location_type& l)
      {
        return symbol_type (token::ID, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR (location_type l)
      {
        return symbol_type (token::OR, std::move (l));
      }
#else
      static
      symbol_type
      make_OR (const location_type& l)
      {
        return symbol_type (token::OR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND (location_type l)
      {
        return symbol_type (token::AND, std::move (l));
      }
#else
      static
      symbol_type
      make_AND (const location_type& l)
      {
        return symbol_type (token::AND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT (location_type l)
      {
        return symbol_type (token::NOT, std::move (l));
      }
#else
      static
      symbol_type
      make_NOT (const location_type& l)
      {
        return symbol_type (token::NOT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LESS_THAN (location_type l)
      {
        return symbol_type (token::LESS_THAN, std::move (l));
      }
#else
      static
      symbol_type
      make_LESS_THAN (const location_type& l)
      {
        return symbol_type (token::LESS_THAN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GREATER_THAN (location_type l)
      {
        return symbol_type (token::GREATER_THAN, std::move (l));
      }
#else
      static
      symbol_type
      make_GREATER_THAN (const location_type& l)
      {
        return symbol_type (token::GREATER_THAN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LESS_THAN_EQ (location_type l)
      {
        return symbol_type (token::LESS_THAN_EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_LESS_THAN_EQ (const location_type& l)
      {
        return symbol_type (token::LESS_THAN_EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GREATER_THAN_EQ (location_type l)
      {
        return symbol_type (token::GREATER_THAN_EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_GREATER_THAN_EQ (const location_type& l)
      {
        return symbol_type (token::GREATER_THAN_EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IS_EQUAL_TO (location_type l)
      {
        return symbol_type (token::IS_EQUAL_TO, std::move (l));
      }
#else
      static
      symbol_type
      make_IS_EQUAL_TO (const location_type& l)
      {
        return symbol_type (token::IS_EQUAL_TO, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IS_NOT_EQUAL_TO (location_type l)
      {
        return symbol_type (token::IS_NOT_EQUAL_TO, std::move (l));
      }
#else
      static
      symbol_type
      make_IS_NOT_EQUAL_TO (const location_type& l)
      {
        return symbol_type (token::IS_NOT_EQUAL_TO, l);
      }
#endif


  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    GenieParser (const GenieParser&);
    /// Non copyable.
    GenieParser& operator= (const GenieParser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef unsigned char state_type;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

#if YYDEBUG || 0
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif // #if YYDEBUG || 0


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const signed char yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const unsigned char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const unsigned char yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 260,     ///< Last index in yytable_.
      yynnts_ = 35,  ///< Number of nonterminal symbols.
      yyfinal_ = 3 ///< Termination state number.
    };


    // User arguments.
    yyscan_t scanner;
    GenieModule*& mod;

  };


#line 20 "parser.y"
} // genie
#line 2410 "Genie-Parser.hpp"


// "%code provides" blocks.
#line 29 "parser.y"

    #define YY_DECL \
        int yylex(genie::GenieParser::semantic_type *yylval, genie::GenieParser::location_type* yylloc, yyscan_t yyscanner,genie::GenieModule*& mod)
    YY_DECL;

#line 2420 "Genie-Parser.hpp"


#endif // !YY_YY_GENIE_PARSER_HPP_INCLUDED
