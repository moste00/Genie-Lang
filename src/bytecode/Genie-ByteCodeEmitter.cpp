#include "Genie-ByteCodeEmitter.h"
#include <iostream>
namespace genie {
    GenieByteCodeEmitter::GenieByteCodeEmitter() {
        global_int_next_valid_id = 0;
        global_real_next_valid_id= 0;
        local_int_next_valid_id.push(0);
        local_real_next_valid_id.push(0);
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

    GenieByteCodeEmitter::RegId GenieByteCodeEmitter::emit_reg_mov(GenieByteCodeEmitter::RegId reg,MovType t) {
        GenieByteCodeBuffer::Entry mov;
        mov.opcode.info = 0;
        mov.opcode.opcode_t = GenieByteCodeBuffer::Entry::OpCode::OpCodeType::MOV;

        mov.opcode.info |= GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_REGISTER;
        mov.opcode.info |=
                (reg.info & GenieByteCodeBuffer::Entry::INFO_DEST_ARG_LOCAL_SCOPE_REGISTER )? GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_LOCAL_SCOPE_REGISTER:
                (reg.info & GenieByteCodeBuffer::Entry::INFO_DEST_ARG_GLOBAL_SCOPE_REGISTER)? GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_GLOBAL_SCOPE_REGISTER:
                                                                                              GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_ARGUMENT_SCOPE_REGISTER;

        GenieByteCodeBuffer::Entry src,dst;
        RegId dst_reg;

        src.ll_arg = reg.id;

        if (t == MovType::LOCAL) {
            mov.opcode.info |= GenieByteCodeBuffer::Entry::INFO_DEST_ARG_LOCAL_SCOPE_REGISTER;
            if (reg.info & GenieByteCodeBuffer::Entry::INFO_OP_TYPE_REAL) {
                dst_reg.id = local_real_next_valid_id.top();
                local_real_next_valid_id.top()++;
            }
            else {
                dst_reg.id = local_int_next_valid_id.top();
                local_int_next_valid_id.top()++;
            }
        }
        else {
            mov.opcode.info |= GenieByteCodeBuffer::Entry::INFO_DEST_ARG_GLOBAL_SCOPE_REGISTER;;
            if (reg.info & GenieByteCodeBuffer::Entry::INFO_OP_TYPE_REAL) {
                dst_reg.id = global_real_next_valid_id;
                global_real_next_valid_id++;
            }
            else {
                dst_reg.id = global_int_next_valid_id;
                global_int_next_valid_id++;
            }
        }
        dst.ll_arg = dst_reg.id;

        mov.opcode.info |= reg.info & GenieByteCodeBuffer::Entry::INFO_OP_TYPE_REAL;
        mov.opcode.info |= reg.info & GenieByteCodeBuffer::Entry::INFO_OP_TYPE_INT;

        dst_reg.info = mov.opcode.info;

        bytecode.buffer.push_back(mov);
        bytecode.buffer.push_back(src);
        bytecode.buffer.push_back(dst);
        return dst_reg;
    }

    void GenieByteCodeEmitter::emit_reg_mov(GenieByteCodeEmitter::RegId r1, GenieByteCodeEmitter::RegId r2) {
        GenieByteCodeBuffer::Entry mov;
        GenieByteCodeBuffer::Entry src_reg,dst_reg;

        src_reg.ll_arg = r1.id;
        dst_reg.ll_arg = r2.id;

        mov.opcode.info = 0;
        mov.opcode.opcode_t = GenieByteCodeBuffer::Entry::OpCode::OpCodeType::MOV;
        mov.opcode.info |= GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_REGISTER;
        mov.opcode.info |= (r1.info & GenieByteCodeBuffer::Entry::INFO_DEST_ARG_LOCAL_SCOPE_REGISTER )? GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_LOCAL_SCOPE_REGISTER:
                           (r1.info & GenieByteCodeBuffer::Entry::INFO_DEST_ARG_GLOBAL_SCOPE_REGISTER)? GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_GLOBAL_SCOPE_REGISTER:
                                                                                                        GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_ARGUMENT_SCOPE_REGISTER;

        mov.opcode.info |= r2.info  & GenieByteCodeBuffer::Entry::INFO_DEST_ARG_LOCAL_SCOPE_REGISTER;
        mov.opcode.info |= r2.info  & GenieByteCodeBuffer::Entry::INFO_DEST_ARG_GLOBAL_SCOPE_REGISTER;
        mov.opcode.info |= r2.info  & GenieByteCodeBuffer::Entry::INFO_DEST_ARG_ARGUMENT_SCOPE_REGISTER;

        mov.opcode.info |= r1.info & GenieByteCodeBuffer::Entry::INFO_OP_TYPE_REAL;
        mov.opcode.info |= r1.info & GenieByteCodeBuffer::Entry::INFO_OP_TYPE_INT;

        bytecode.buffer.push_back(mov);
        bytecode.buffer.push_back(src_reg);
        bytecode.buffer.push_back(dst_reg);
    }

    GenieByteCodeEmitter::RegId GenieByteCodeEmitter::mk_arg_reg(string type) {
        RegId reg;
        reg.info = 0;

        reg.info |= GenieByteCodeBuffer::Entry::INFO_DEST_ARG_ARGUMENT_SCOPE_REGISTER;
        if (type == "int") {
            reg.id = arg_int_next_valid_id.top();
            arg_int_next_valid_id.top()++;

            reg.info |= GenieByteCodeBuffer::Entry::INFO_OP_TYPE_INT;

        }
        else if (type == "real"){
            reg.id = arg_real_next_valid_id.top();
            arg_real_next_valid_id.top()++;

            reg.info |= GenieByteCodeBuffer::Entry::INFO_OP_TYPE_REAL;
        }
        return reg;
    }

    void GenieByteCodeEmitter::enter_function() {
        local_real_next_valid_id.push(0);
        local_int_next_valid_id.push(0);
        arg_int_next_valid_id.push(0);
        arg_real_next_valid_id.push(0);
    }

    void GenieByteCodeEmitter::leave_function() {
        local_real_next_valid_id.pop();
        local_int_next_valid_id.pop();

        arg_int_next_valid_id.push(0);
        arg_real_next_valid_id.push(0);
    }

    void GenieByteCodeEmitter::register_if_not_already_registered(string label) {
        auto it = floating_labels.find(label);
        if (it == floating_labels.end()) {
            floating_labels[label] = {};
        }
    }

    void GenieByteCodeEmitter::emit_no_op() {
        GenieByteCodeBuffer::Entry nop;
        nop.opcode.opcode_t = GenieByteCodeBuffer::Entry::OpCode::OpCodeType::NOP;
        bytecode.buffer.push_back(nop);
    }

    void GenieByteCodeEmitter::emit_ret(GenieByteCodeEmitter::RegId& id) {
        GenieByteCodeBuffer::Entry ret;
        ret.opcode.opcode_t = GenieByteCodeBuffer::Entry::OpCode::OpCodeType::RET;
        ret.opcode.info = 0;

        ret.opcode.info |= GenieByteCodeBuffer::Entry::INFO_RET_WITH_SRC;
        ret.opcode.info |= GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_REGISTER;

        ret.opcode.info |= (id.info & GenieByteCodeBuffer::Entry::INFO_DEST_ARG_LOCAL_SCOPE_REGISTER )? GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_LOCAL_SCOPE_REGISTER:
                           (id.info & GenieByteCodeBuffer::Entry::INFO_DEST_ARG_GLOBAL_SCOPE_REGISTER)? GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_GLOBAL_SCOPE_REGISTER:
                                                                                                        GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_ARGUMENT_SCOPE_REGISTER;
        ret.opcode.info |= id.info & GenieByteCodeBuffer::Entry::INFO_OP_TYPE_REAL;
        ret.opcode.info |= id.info & GenieByteCodeBuffer::Entry::INFO_OP_TYPE_INT;

        GenieByteCodeBuffer::Entry r;
        r.ll_arg = id.id;

        bytecode.buffer.push_back(ret);
        bytecode.buffer.push_back(r);
    }

    void GenieByteCodeEmitter::emit_ret() {
        GenieByteCodeBuffer::Entry ret;
        ret.opcode.opcode_t = GenieByteCodeBuffer::Entry::OpCode::OpCodeType::RET;
        ret.opcode.info = 0;
        bytecode.buffer.push_back(ret);
    }

    GenieByteCodeEmitter::RegId GenieByteCodeEmitter::emit_function_call(std::string label, const vector<RegId>& regs, const std::string& return_type) {
        bool void_call = return_type == "void";

        GenieByteCodeBuffer::Entry call;
        call.opcode.opcode_t = GenieByteCodeBuffer::Entry::OpCode::OpCodeType::CALL;
        call.opcode.info = 0;
        if (void_call) {
            call.opcode.info |= GenieByteCodeBuffer::Entry::INFO_CALL_IS_VOID;
        }
        else {
            if (return_type == "int") call.opcode.info |= GenieByteCodeBuffer::Entry::INFO_OP_TYPE_INT  ;
            if (return_type == "real") call.opcode.info |= GenieByteCodeBuffer::Entry::INFO_OP_TYPE_REAL;
        }
        bytecode.buffer.push_back(call);

        GenieByteCodeBuffer::Entry call_target;
        call_target.ll_arg = -1;
        auto it = floating_labels.find(label);
        if (it != floating_labels.end()) {
            it->second.push_back(bytecode.buffer.size());
        }
        else {
            auto it = labels_to_buffer_poses.find(label);
            if (it != labels_to_buffer_poses.end()) {
                call_target.ll_arg = it->second;
            }
        }
        bytecode.buffer.push_back(call_target);

        GenieByteCodeBuffer::Entry argc;
        argc.ll_arg = regs.size();
        bytecode.buffer.push_back(argc);

        for (const auto& r : regs) {
            GenieByteCodeBuffer::Entry reg_info,reg_id;

            reg_info.ll_arg = 0;
            reg_info.ll_arg |= GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_REGISTER;
            reg_info.ll_arg |= (r.info & GenieByteCodeBuffer::Entry::INFO_DEST_ARG_LOCAL_SCOPE_REGISTER )? GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_LOCAL_SCOPE_REGISTER:
                               (r.info & GenieByteCodeBuffer::Entry::INFO_DEST_ARG_GLOBAL_SCOPE_REGISTER)? GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_GLOBAL_SCOPE_REGISTER:
                                                                                                           GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_ARGUMENT_SCOPE_REGISTER;
            reg_info.ll_arg |= r.info & GenieByteCodeBuffer::Entry::INFO_OP_TYPE_REAL;
            reg_info.ll_arg |= r.info & GenieByteCodeBuffer::Entry::INFO_OP_TYPE_INT;

            reg_id.ll_arg = r.id;

            bytecode.buffer.push_back(reg_info);
            bytecode.buffer.push_back(reg_id);
        }

        if (void_call) return invalid_reg();
        else {
            GenieByteCodeBuffer::Entry call_res;
            if (return_type == "int") {
                call_res.ll_arg = local_int_next_valid_id.top();
                local_int_next_valid_id.top()++;
            }
            else if (return_type == "real") {
                call_res.ll_arg = local_real_next_valid_id.top();
                local_real_next_valid_id.top()++;
            }
            bytecode.buffer.push_back(call_res);

            GenieByteCodeEmitter::RegId r;
            r.id = call_res.ll_arg;
            r.info = 0;
            r.info |= call.opcode.info & GenieByteCodeBuffer::Entry::INFO_OP_TYPE_INT;
            r.info |= call.opcode.info & GenieByteCodeBuffer::Entry::INFO_OP_TYPE_REAL;
            r.info |= GenieByteCodeBuffer::Entry::INFO_DEST_ARG_LOCAL_SCOPE_REGISTER;
            return r;
        }
    }
}