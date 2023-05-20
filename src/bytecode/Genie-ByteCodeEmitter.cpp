#include "Genie-ByteCodeEmitter.h"

namespace genie {
    GenieByteCodeEmitter::GenieByteCodeEmitter() {
        global_int_next_valid_id = 0;
        global_real_next_valid_id= 0;
    }
    GenieByteCodeEmitter::RegId
    GenieByteCodeEmitter::emit_integer_literal_mov(GenieInt value, GenieByteCodeEmitter::MovType mov_t) {
        RegId reg;
        reg.info = 0;

        reg.info |= GenieByteCodeBuffer::Entry::INFO_OP_TYPE_INT;
        if (mov_t == MovType::LOCAL) {
            reg.info |= GenieByteCodeBuffer::Entry::INFO_DEST_ARG_LOCAL_SCOPE_REGISTER;
            reg.id = local_int_next_valid_id.top();
            local_int_next_valid_id.top()++;
        }
        else {
            reg.info |=  GenieByteCodeBuffer::Entry::INFO_DEST_ARG_GLOBAL_SCOPE_REGISTER;;
            reg.id = global_int_next_valid_id;
            global_int_next_valid_id++;
        }

        GenieByteCodeBuffer::Entry mov;
        mov.opcode.opcode_t = GenieByteCodeBuffer::Entry::OpCode::OpCodeType::MOV;
        mov.opcode.info  = 0;
        mov.opcode.info |= reg.info;
        GenieByteCodeBuffer::Entry int_literal;
        if (value.is_machine_int()) {
            int_literal.ll_arg = value.as_machine_int();
            mov.opcode.info |= GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_LONG_LITERAL;
        }
        else {
            int_literal.any_arg = value.value.as_gmp_big_int;
            mov.opcode.info |= GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_ANY_LITERAL;
        }
        GenieByteCodeBuffer::Entry dest_reg;
        dest_reg.ll_arg = reg.id;

        bytecode.buffer.push_back(mov);
        bytecode.buffer.push_back(int_literal);
        bytecode.buffer.push_back(dest_reg);
        return reg;
    }

    GenieByteCodeEmitter::RegId
    GenieByteCodeEmitter::emit_real_literal_mov(GenieReal* value, GenieByteCodeEmitter::MovType mov_t) {
        RegId reg;
        reg.info = 0;

        reg.info |= GenieByteCodeBuffer::Entry::INFO_OP_TYPE_REAL;
        if (mov_t == MovType::LOCAL) {
            reg.info |= GenieByteCodeBuffer::Entry::INFO_DEST_ARG_LOCAL_SCOPE_REGISTER;
            reg.id = local_real_next_valid_id.top();
            local_real_next_valid_id.top()++;
        }
        else {
            reg.info |= GenieByteCodeBuffer::Entry::INFO_DEST_ARG_GLOBAL_SCOPE_REGISTER;;
            reg.id = global_real_next_valid_id;
            global_real_next_valid_id++;
        }

        GenieByteCodeBuffer::Entry mov;
        mov.opcode.opcode_t = GenieByteCodeBuffer::Entry::OpCode::OpCodeType::MOV;
        mov.opcode.info  = 0;
        mov.opcode.info |= reg.info;

        GenieByteCodeBuffer::Entry real_literal;
        real_literal.any_arg = value;
        mov.opcode.info |= GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_ANY_LITERAL;

        GenieByteCodeBuffer::Entry dest_reg;
        dest_reg.ll_arg = reg.id;

        bytecode.buffer.push_back(mov);
        bytecode.buffer.push_back(real_literal);
        bytecode.buffer.push_back(dest_reg);
        return reg;
    }

    GenieByteCodeEmitter::RegId
    GenieByteCodeEmitter::emit_binary_instruction(GenieByteCodeEmitter::RegId reg1,
                                                  GenieByteCodeEmitter::RegId reg2,
                                                  GenieBinaryExpr::GenieBinaryOp op) {
        GenieByteCodeBuffer::Entry binary_instruction;
        GenieByteCodeBuffer::Entry r1,r2;
        binary_instruction.opcode.opcode_t = GenieBinaryOpToInstruction(op);

        binary_instruction.opcode.info = 0;
        binary_instruction.opcode.info |= GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_REGISTER;
        binary_instruction.opcode.info |= GenieByteCodeBuffer::Entry::INFO_SECOND_SRC_ARG_REGISTER;

        binary_instruction.opcode.info |=
                (reg1.info & GenieByteCodeBuffer::Entry::INFO_DEST_ARG_LOCAL_SCOPE_REGISTER)?  GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_LOCAL_SCOPE_REGISTER:
                (reg1.info & GenieByteCodeBuffer::Entry::INFO_DEST_ARG_GLOBAL_SCOPE_REGISTER)? GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_GLOBAL_SCOPE_REGISTER:
                                                                                               GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_ARGUMENT_SCOPE_REGISTER;
        binary_instruction.opcode.info |=
                (reg2.info & GenieByteCodeBuffer::Entry::INFO_DEST_ARG_LOCAL_SCOPE_REGISTER)?  GenieByteCodeBuffer::Entry::INFO_SECOND_SRC_ARG_LOCAL_SCOPE_REGISTER:
                (reg2.info & GenieByteCodeBuffer::Entry::INFO_DEST_ARG_GLOBAL_SCOPE_REGISTER)? GenieByteCodeBuffer::Entry::INFO_SECOND_SRC_ARG_GLOBAL_SCOPE_REGISTER:
                                                                                               GenieByteCodeBuffer::Entry::INFO_SECOND_SRC_ARG_ARGUMENT_SCOPE_REGISTER;
        r1.ll_arg = reg1.id;
        r2.ll_arg = reg2.id;

        bool same_type = false;
        int type;
        if (reg1.info & GenieByteCodeBuffer::Entry::INFO_OP_TYPE_INT) {
            if (reg2.info & GenieByteCodeBuffer::Entry::INFO_OP_TYPE_INT) {
                type = GenieByteCodeBuffer::Entry::INFO_OP_TYPE_INT;
                same_type = true;
            }
        }
        if (reg1.info & GenieByteCodeBuffer::Entry::INFO_OP_TYPE_REAL) {
            if (reg2.info & GenieByteCodeBuffer::Entry::INFO_OP_TYPE_REAL) {
                type = GenieByteCodeBuffer::Entry::INFO_OP_TYPE_REAL;
                same_type = true;
            }
        }
        if (!same_type) {
            return invalid_reg();
        }
        binary_instruction.opcode.info |= type;
        binary_instruction.opcode.info |= GenieByteCodeBuffer::Entry::INFO_DEST_ARG_LOCAL_SCOPE_REGISTER;

        bytecode.buffer.push_back(binary_instruction);
        bytecode.buffer.push_back(r1);
        bytecode.buffer.push_back(r2);

        RegId result;
        result.info = binary_instruction.opcode.info;
        if (type == GenieByteCodeBuffer::Entry::INFO_OP_TYPE_INT) {
            result.id = local_int_next_valid_id.top();
            local_int_next_valid_id.top()++;
        }
        else {
            result.id = local_real_next_valid_id.top();
            local_real_next_valid_id.top()++;
        }

        GenieByteCodeBuffer::Entry dest_reg;
        dest_reg.ll_arg = result.id;
        bytecode.buffer.push_back(dest_reg);
        return result;
    }

    void GenieByteCodeEmitter::emit_2way_conditional_branch(GenieByteCodeEmitter::RegId id,
                                                            std::string truthy_jump_target,
                                                            std::string falsey_jump_target) {
        GenieByteCodeBuffer::Entry cond_branch;
        cond_branch.opcode.opcode_t = GenieByteCodeBuffer::Entry::OpCode::OpCodeType::CONDBRANCH2;
        cond_branch.opcode.info = 0;

        cond_branch.opcode.info |= GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_REGISTER;
        cond_branch.opcode.info |=
                    (id.info & GenieByteCodeBuffer::Entry::INFO_DEST_ARG_LOCAL_SCOPE_REGISTER )? GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_LOCAL_SCOPE_REGISTER:
                    (id.info & GenieByteCodeBuffer::Entry::INFO_DEST_ARG_GLOBAL_SCOPE_REGISTER)? GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_GLOBAL_SCOPE_REGISTER:
                                                                                                 GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_ARGUMENT_SCOPE_REGISTER;
        cond_branch.opcode.info |= id.info & GenieByteCodeBuffer::Entry::INFO_OP_TYPE_INT;
        cond_branch.opcode.info |= id.info & GenieByteCodeBuffer::Entry::INFO_OP_TYPE_REAL;

        cond_branch.opcode.info |= GenieByteCodeBuffer::Entry::INFO_SECOND_SRC_ARG_LONG_LITERAL;
        cond_branch.opcode.info |= GenieByteCodeBuffer::Entry::INFO_BRANCH2_THIRD_SRC_ARG_LONG_LITERAL;

        GenieByteCodeBuffer::Entry truthy_jump_index;
        GenieByteCodeBuffer::Entry falsey_jump_index;
        truthy_jump_index.ll_arg = -1;
        falsey_jump_index.ll_arg = -1;

        GenieByteCodeBuffer::Entry reg;
        reg.ll_arg = id.id;

        bytecode.buffer.push_back(cond_branch);
        bytecode.buffer.push_back(reg);
        bytecode.buffer.push_back(truthy_jump_index);
        bytecode.buffer.push_back(falsey_jump_index);

        floating_labels[truthy_jump_target].push_back(bytecode.buffer.size() - 2);
        floating_labels[falsey_jump_target].push_back(bytecode.buffer.size() - 1);
    }

    void GenieByteCodeEmitter::emit_unconditional_branch(std::string jump_target) {
        GenieByteCodeBuffer::Entry jump;
        jump.opcode.opcode_t = GenieByteCodeBuffer::Entry::OpCode::OpCodeType::NONCONDBRANCH;
        jump.opcode.info = 0;
        jump.opcode.info |= GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_LONG_LITERAL;

        GenieByteCodeBuffer::Entry target;

        auto it = labels_to_buffer_poses.find(jump_target);
        if (it != labels_to_buffer_poses.end()) {
            target.ll_arg = it->second;
        }
        else {
            auto it = floating_labels.find(jump_target);
            if (it != floating_labels.end()) {
                target.ll_arg = -1;
                it->second.push_back(bytecode.buffer.size()+1);
            }
            else return;
        }
        bytecode.buffer.push_back(jump);
        bytecode.buffer.push_back(target);
    }

    void GenieByteCodeEmitter::register_label(std::string label) {
        floating_labels[label] = {};
    }
    void GenieByteCodeEmitter::set_label_to_curr_buffer_pos(std::string label) {
        auto it = floating_labels.find(label);
        if ( it == floating_labels.end()) {
            return;
        }
        size_t label_buffer_pos = bytecode.buffer.size();
        labels_to_buffer_poses[label] = label_buffer_pos;
        buffer_poses_to_labels[label_buffer_pos] = label;

        const vector<size_t>& back_patched_entries = it->second;
        for (auto pos : back_patched_entries) {
            bytecode.buffer[pos].ll_arg = label_buffer_pos;
        }
        floating_labels.erase(label);
    }

    void GenieByteCodeEmitter::emit_1way_falsey_conditional_branch(RegId id,std::string label) {
        GenieByteCodeBuffer::Entry branch;
        branch.opcode.opcode_t = GenieByteCodeBuffer::Entry::OpCode::OpCodeType::FALSEYCONDBRANCH1;
        branch.opcode.info = 0;
        branch.opcode.info |= GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_REGISTER;
        branch.opcode.info |=
                        (id.info & GenieByteCodeBuffer::Entry::INFO_DEST_ARG_LOCAL_SCOPE_REGISTER )? GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_LOCAL_SCOPE_REGISTER:
                        (id.info & GenieByteCodeBuffer::Entry::INFO_DEST_ARG_GLOBAL_SCOPE_REGISTER)? GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_GLOBAL_SCOPE_REGISTER:
                                                                                                     GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_ARGUMENT_SCOPE_REGISTER;
        branch.opcode.info |= id.info & GenieByteCodeBuffer::Entry::INFO_OP_TYPE_INT;
        branch.opcode.info |= id.info & GenieByteCodeBuffer::Entry::INFO_OP_TYPE_REAL;
        branch.opcode.info |= GenieByteCodeBuffer::Entry::INFO_SECOND_SRC_ARG_LONG_LITERAL;

        GenieByteCodeBuffer::Entry reg;
        reg.ll_arg = id.id;

        GenieByteCodeBuffer::Entry target;
        auto it = labels_to_buffer_poses.find(label);
        if (it != labels_to_buffer_poses.end()) {
            target.ll_arg = it->second;
        }
        else {
            auto it = floating_labels.find(label);
            if (it != floating_labels.end()) {
                target.ll_arg = -1;
                it->second.push_back(bytecode.buffer.size()+2);
            }
            else return;
        }
        bytecode.buffer.push_back(branch);
        bytecode.buffer.push_back(reg);
        bytecode.buffer.push_back(target);
    }
}