#include "Genie-ByteCodeBuffer.h"
#include <stack>
#include <unordered_map>
#include <sstream>

namespace genie {
    class GenieByteCodeEmitter {
    public:
        class RegId {
            //Info to indicate what type the register is and what its scope
            int info;
            long long id;
            friend class GenieByteCodeEmitter;
            RegId(int inf,int i) : info(inf), id(i) {};
        public:
            std::string to_str() {
                std::stringstream s;
                s << id;
                return s.str();
            }
            RegId() {};
        };
    private:
        GenieByteCodeBuffer bytecode;
        std::stack<long long> local_int_next_valid_id;
        std::stack<long long> local_real_next_valid_id;
        std::stack<long long> arg_int_next_valid_id;
        std::stack<long long> arg_real_next_valid_id;
        long long global_int_next_valid_id;
        long long global_real_next_valid_id;
        std::unordered_map<std::string,size_t> labels_to_buffer_poses;
        std::unordered_map<size_t,std::string> buffer_poses_to_labels;

        //labels that are registered but not yet set are called "floating", they don't have a concrete existence yet
        //floating labels must be associated with every bytecode entry that used them
        //because those entries must be 'back-patched' to actual addresses when the label is set
        std::unordered_map<std::string,std::vector<size_t>> floating_labels;

        static inline RegId invalid_reg() {
            return RegId(0xFF'FF'FF'FF,-1);
        }

        //-----------------------------------------------------------------------------------------------------------------
        #define MapEntry(op_name, op, instruction) (op_name == op)? instruction:
        #define Default(def) def
        #define GenieBinaryOpToInstruction(op_name) \
            MapEntry(op_name,GenieBinaryExpr::GenieBinaryOp::PLUS_OP  ,GenieByteCodeBuffer::Entry::OpCode::OpCodeType::ADD) \
            MapEntry(op_name,GenieBinaryExpr::GenieBinaryOp::MINUS_OP ,GenieByteCodeBuffer::Entry::OpCode::OpCodeType::SUB   ) \
            MapEntry(op_name,GenieBinaryExpr::GenieBinaryOp::MULT_OP  ,GenieByteCodeBuffer::Entry::OpCode::OpCodeType::MUL   ) \
            MapEntry(op_name,GenieBinaryExpr::GenieBinaryOp::DIV_OP   ,GenieByteCodeBuffer::Entry::OpCode::OpCodeType::DIV   ) \
            MapEntry(op_name,GenieBinaryExpr::GenieBinaryOp::EXP_OP   ,GenieByteCodeBuffer::Entry::OpCode::OpCodeType::EXP   ) \
            MapEntry(op_name,GenieBinaryExpr::GenieBinaryOp::MOD_OP   ,GenieByteCodeBuffer::Entry::OpCode::OpCodeType::MOD   ) \
            MapEntry(op_name,GenieBinaryExpr::GenieBinaryOp::GTE_OP   ,GenieByteCodeBuffer::Entry::OpCode::OpCodeType::CMPGTE) \
            MapEntry(op_name,GenieBinaryExpr::GenieBinaryOp::GT_OP    ,GenieByteCodeBuffer::Entry::OpCode::OpCodeType::CMPGT ) \
            MapEntry(op_name,GenieBinaryExpr::GenieBinaryOp::LTE_OP   ,GenieByteCodeBuffer::Entry::OpCode::OpCodeType::CMPLTE) \
            MapEntry(op_name,GenieBinaryExpr::GenieBinaryOp::LT_OP    ,GenieByteCodeBuffer::Entry::OpCode::OpCodeType::CMPLT ) \
            MapEntry(op_name,GenieBinaryExpr::GenieBinaryOp::EQ_OP    ,GenieByteCodeBuffer::Entry::OpCode::OpCodeType::CMPEQ ) \
            MapEntry(op_name,GenieBinaryExpr::GenieBinaryOp::NEQ_OP   ,GenieByteCodeBuffer::Entry::OpCode::OpCodeType::CMPNEQ) \
            MapEntry(op_name,GenieBinaryExpr::GenieBinaryOp::AND_OP   ,GenieByteCodeBuffer::Entry::OpCode::OpCodeType::AND   ) \
            MapEntry(op_name,GenieBinaryExpr::GenieBinaryOp::OR_OP    ,GenieByteCodeBuffer::Entry::OpCode::OpCodeType::OR    ) \
            MapEntry(op_name,GenieBinaryExpr::GenieBinaryOp::NOT_OP   ,GenieByteCodeBuffer::Entry::OpCode::OpCodeType::NOT   ) \
            Default(GenieByteCodeBuffer::Entry::OpCode::OpCodeType::RAISEHALT)
        //-----------------------------------------------------------------------------------------------------------------

    public:
        static inline bool is_invalid_reg(RegId r) {
            return r.id == -1;
        }
        GenieByteCodeEmitter();
        enum class MovType {GLOBAL,LOCAL};
        RegId emit_integer_literal_mov(GenieInt,MovType);
        RegId emit_real_literal_mov(GenieReal*,MovType);
        RegId emit_binary_instruction(RegId reg1,RegId reg2,GenieBinaryExpr::GenieBinaryOp op);
        RegId emit_reg_mov(RegId,MovType);
        void emit_reg_mov(RegId,RegId);
        void register_label(std::string);
        void emit_2way_conditional_branch(RegId, std::string, std::string);
        void set_label_to_curr_buffer_pos(std::string);
        void emit_unconditional_branch(std::string);
        void emit_1way_falsey_conditional_branch(RegId,std::string);

        std::string serialize_bytecode_to_lisp() {
            return bytecode.serialize_to_lisp(buffer_poses_to_labels);
        }

        RegId mk_arg_reg(string type);

        void enter_function();

        void leave_function();

        void register_if_not_already_registered(string label);

        void emit_no_op();
        void emit_ret(RegId &id);
        void emit_ret();

        RegId emit_function_call(std::string label, const vector<RegId> &regs, const std::string &return_type);
    };
}