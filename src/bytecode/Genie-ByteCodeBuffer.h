#include <vector>
#include <unordered_map>
#include "../ast/Genie-Int.h"
#include "../ast/Genie-Real.h"
#include "../ast/Genie-Binary.h"

using std::vector;
namespace genie {
    struct GenieByteCodeBuffer {
        //unlike the vast majority of unsafe unions, this one doesn't actually need a type tag
        //Because which variant is active can always be known from its position in the buffer
        //For example, suppose the buffer is
        //                  <Entry1><Entry2><Entry3><Entry4>
        //Then
        //      1- Entry1 is necessarily an OpCode, since it starts the buffer
        //      2- Read Entry1's OpCodeType, then
        //                  a- If it's a 0-arg OpCode, then Entry2 is the next OpCode
        //                  b- If It's a 1-arg OpCode, then Entry2 is the argument and Entry3 is the next OpCode
        //and so on, it's always possible to know which variant is active in an Entry from its position in the buffer
        //One drawback of this is that we can't randomly access an Entry in the buffer, we always need to read the buffer from the very beginning
        union Entry {
                //A bytecode entry is either :
                //1- An Opcode and a couple of associated metadata
                struct OpCode {
                    enum class OpCodeType : int {
                        MOV = 0,
                        ADD, SUB, MUL, DIV, MOD, EXP,
                        CMPEQ, CMPNEQ, CMPGT, CMPLT, CMPGTE, CMPLTE,
                        AND, OR, NOT,

                        CONDBRANCH2,NONCONDBRANCH,TRUTHYCONDBRANCH1,FALSEYCONDBRANCH1,

                        CALL,RET,

                        NOP,RAISEHALT
                    } opcode_t;
                    int info;
                } opcode;

                //OR
                //2- A long long argument for a preceding opcode
                long long ll_arg;
                //OR
                //3- A generic argument for a preceding opcode (e.g. a gmp big int, for example)
                void* any_arg;

                //generic info constant masks
                static const int INFO_FIRST_SRC_ARG_LOCAL_SCOPE_REGISTER     = 0x1;
                static const int INFO_FIRST_SRC_ARG_GLOBAL_SCOPE_REGISTER    = 0x2;
                static const int INFO_FIRST_SRC_ARG_ARGUMENT_SCOPE_REGISTER  = 0x4;
                //-----------------------------------------------------------------------------------------------------
                static const int INFO_SECOND_SRC_ARG_LOCAL_SCOPE_REGISTER    = 0x8;
                static const int INFO_SECOND_SRC_ARG_GLOBAL_SCOPE_REGISTER   = 0x10;
                static const int INFO_SECOND_SRC_ARG_ARGUMENT_SCOPE_REGISTER = 0x20;
                //-----------------------------------------------------------------------------------------------------
                static const int INFO_DEST_ARG_LOCAL_SCOPE_REGISTER          = 0x40;
                static const int INFO_DEST_ARG_GLOBAL_SCOPE_REGISTER         = 0x80;
                static const int INFO_DEST_ARG_ARGUMENT_SCOPE_REGISTER       = 0x100;
                //-----------------------------------------------------------------------------------------------------
                static const int INFO_OP_TYPE_INT                            = 0x200;
                static const int INFO_OP_TYPE_REAL                           = 0x400;
                //-----------------------------------------------------------------------------------------------------
                static const int INFO_FIRST_SRC_ARG_LONG_LITERAL             = 0x800;
                static const int INFO_FIRST_SRC_ARG_REGISTER                 = 0x1000;
                static const int INFO_FIRST_SRC_ARG_ANY_LITERAL              = 0x2000;
                //-----------------------------------------------------------------------------------------------------
                static const int INFO_SECOND_SRC_ARG_LONG_LITERAL            = 0x4000;
                static const int INFO_SECOND_SRC_ARG_REGISTER                = 0x8000;
                static const int INFO_SECOND_SRC_ARG_ANY_LITERAL             = 0x10000;

                //special info masks that are only meaningful with specific instructions
                //This means that those flags can be 'aliased',
                // so while the generic flags above must always mean the same thing for all instructions
                // (or mean nothing and stay unused, in the case of instructions that don't need them such as mov which doesn't need its INFO_SECOND_SRC)
                // those flags can have an instruction-dependent meaning,
                // so several constants with different names but the same value can be defined
                static const int INFO_BRANCH2_THIRD_SRC_ARG_LONG_LITERAL     = 0x20000;
                static const int INFO_BRANCH2_THIRD_SRC_ARG_REGISTER         = 0x40000;
                static const int INFO_BRANCH2_THIRD_SRC_ARG_ANY_LITERAL      = 0x80000;
                static const int INFO_BRANCH2_THIRD_SRC_ARG_LOCAL_SCOPE_REGISTER    = 0x100000;
                static const int INFO_BRANCH2_THIRD_SRC_ARG_GLOBAL_SCOPE_REGISTER   = 0x200000;
                static const int INFO_BRANCH2_THIRD_SRC_ARG_ARGUMENT_SCOPE_REGISTER = 0x400000;

                static const int INFO_RET_WITH_SRC = 0x20000;

                static const int INFO_CALL_IS_VOID = 0x20000;
        };
        vector<Entry> buffer;

        std::string serialize_to_lisp(const std::unordered_map<size_t,std::string>&);

        static std::stringstream serialize_first_src(int info, const Entry &entry);

        static std::stringstream serialize_dest(int info, const Entry &entry);

        std::stringstream serialize_second_src(int info, const Entry &entry);

        std::stringstream
        serialize_truthy_jump_target(int info, Entry &entry, const std::unordered_map<size_t, std::string> &map);

        std::stringstream
        serialize_falsey_jump_target(int info, Entry &entry, const std::unordered_map<size_t, std::string> &map);

        std::stringstream serialize_third_src(int info, Entry &entry);

        std::stringstream serialize_jump_target(int info, Entry &entry, const std::unordered_map<size_t, std::string> &map);

        static std::string serialize_ret_src_if_present(const vector<Entry> &vector1, size_t &i);

        static std::string serialize_function_call(const vector<Entry>&, size_t&,const std::unordered_map<size_t, std::string>&);
    };
}