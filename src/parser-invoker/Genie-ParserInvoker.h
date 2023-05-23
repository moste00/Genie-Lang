#pragma once

#include "../ast/Genie-Program.h"
#include "Genie-AstProcessor.h"
namespace genie {
    //The ParserInvoker encapsulates the details of calling a specific concrete parser and returning an AST representing the parse
    //The ParserInvoker also owns the resulting AST object and is responsible for freeing it when it goes out of scope
    //No other modules of the Genie toolchain should know anything about parsing or where the AST comes from,
    // the only thing they ever need to know is that they can call a parser invoker to get an AST,
    // and that this parser invoker needs to stay in scope as long as the AST is in use
    //-----------------------------------------------------------------------------------------------------------------------------
    //The ParserInvoker additionally handles collecting simple modules (files) into the complex module they declare (if any)
    //-----------------------------------------------------------------------------------------------------------------------------
    //Finally, the ParserInvoker exposes an AST walking mechanism, given an AstProcessor to ast_for_each
    class ParserInvoker {
    protected:
        GenieProgram prog;
    public:
        virtual void add_file(const std::string&) = 0;
        virtual void add_string(const std::string&) = 0;

        virtual void ast_for_each(AstProcessor& p);

        virtual ~ParserInvoker() {
            prog.free();
        }
    protected:
        virtual void mod_ast_for_each(GenieModule*,AstProcessor&);

        virtual void expr_ast_for_each(GenieExpr, AstProcessor&);

        virtual void type_ast_for_each(GenieType*, AstProcessor& processor);

        virtual void data_ast_for_each(GenieData*, AstProcessor& processor);

        virtual void block_ast_for_each(GenieBlock*, AstProcessor& processor);

        virtual void function_ast_for_each(GenieFunction*, AstProcessor& processor);

        virtual void dispatch_mod_elem(GenieModule::ModuleElem& elem,AstProcessor& p);

        virtual void assignment_ast_for_each(GenieAssign *assign, AstProcessor& processor);

        void ret_ast_for_each(GenieRet *ret, AstProcessor &processor);
    };



}