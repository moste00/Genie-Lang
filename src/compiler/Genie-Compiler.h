#include "../parser-invoker/Genie-AstProcessor.h"
#include "../bytecode/Genie-ByteCodeEmitter.h"
#include "utils.h"
#include "../symbol-table/Genie-SymbolTable.h"

namespace genie {
    class GenieCompiler : public AstProcessor {
        struct VarReg : public GenieScope::AdditionalInfo {
            GenieByteCodeEmitter::RegId reg;

            VarReg(GenieByteCodeEmitter::RegId r) : reg(r) {}

            std::string serialize() override {
                std::stringstream s;
                s << "Register Id = " << reg.to_str();
                return s.str();
            }
        };
        GenieByteCodeEmitter byc;
        std::stack<GenieByteCodeEmitter::RegId> used_regs;
        //they need a seperate stack for complicated reasons
        std::stack<GenieByteCodeEmitter::RegId> used_regs_for_switch_conds;
    public:
        GenieCompiler(GenieSymbolTable*);

        std::string serialize_bytecode_to_lisp() {
            return byc.serialize_bytecode_to_lisp();
        }
    };
}