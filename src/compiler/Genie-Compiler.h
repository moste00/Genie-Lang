#include "../parser-invoker/Genie-AstProcessor.h"
#include "../bytecode/Genie-ByteCodeEmitter.h"
#include "utils.h"
namespace genie {
    class GenieCompiler : public AstProcessor {
        GenieByteCodeEmitter byc;
        std::stack<GenieByteCodeEmitter::RegId> used_regs;
        //they need a seperate stack for complicated reasons
        std::stack<GenieByteCodeEmitter::RegId> used_regs_for_switch_conds;
    public:
        GenieCompiler();

        std::string serialize_bytecode_to_lisp() {
            return byc.serialize_bytecode_to_lisp();
        }
    };
}