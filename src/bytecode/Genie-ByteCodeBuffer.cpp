#include <sstream>
#include <unordered_map>
#include "Genie-ByteCodeBuffer.h"
namespace genie {
    constexpr static const char* const opcode_as_str[] = {
            "(mov", "(+", "(-", "(*","(/","(%","(**",
            "(==", "(!==", "(>","(<","(>=","(<=",
            "(&&","(||","(~",
            "(if","goto","(if","(if not",
            "(","(RAISE-FATAL"
    };
    std::string GenieByteCodeBuffer::serialize_to_lisp(const std::unordered_map<size_t,std::string>& buffer_poses_to_labels) {
        std::stringstream lisp_str;

        for (size_t i = 0; i < buffer.size(); i++) {
            auto it = buffer_poses_to_labels.find(i);
            if (it != buffer_poses_to_labels.end()) {
                string label = it->second;
                lisp_str << ":"<<label<<":\n";
            }

            const Entry& e = buffer[i];
            const char* op_as_str = opcode_as_str[static_cast<int>(e.opcode.opcode_t)];

            switch (e.opcode.opcode_t) {
                case Entry::OpCode::OpCodeType::MOV:
                case Entry::OpCode::OpCodeType::NOT:
                    lisp_str << op_as_str <<" "<< serialize_first_src(e.opcode.info,buffer[i+1]).str();
                    lisp_str << " :-> " << serialize_dest(e.opcode.info,buffer[i+2]).str();
                    lisp_str << " )\n";
                    i += 2;
                    break;
                case Entry::OpCode::OpCodeType::ADD:
                case Entry::OpCode::OpCodeType::SUB:
                case Entry::OpCode::OpCodeType::MUL:
                case Entry::OpCode::OpCodeType::EXP:
                case Entry::OpCode::OpCodeType::DIV:
                case Entry::OpCode::OpCodeType::MOD:
                case Entry::OpCode::OpCodeType::CMPGT:
                case Entry::OpCode::OpCodeType::CMPLT:
                case Entry::OpCode::OpCodeType::CMPGTE:
                case Entry::OpCode::OpCodeType::CMPLTE:
                case Entry::OpCode::OpCodeType::CMPEQ:
                case Entry::OpCode::OpCodeType::CMPNEQ:
                case Entry::OpCode::OpCodeType::AND:
                case Entry::OpCode::OpCodeType::OR:
                    lisp_str << op_as_str <<" "<< serialize_first_src(e.opcode.info,buffer[i+1]).str();
                    lisp_str << " "  << serialize_second_src(e.opcode.info,buffer[i+2]).str();
                    lisp_str << " :-> " << serialize_dest(e.opcode.info,buffer[i+3]).str();
                    lisp_str << " )\n";
                    i += 3;
                    break;
                case Entry::OpCode::OpCodeType::CONDBRANCH2:
                    lisp_str << op_as_str <<" "<< serialize_first_src(e.opcode.info,buffer[i+1]).str();
                    lisp_str << " then goto "  << serialize_truthy_jump_target(e.opcode.info,buffer[i+2],buffer_poses_to_labels).str();
                    lisp_str << " else goto "  << serialize_falsey_jump_target(e.opcode.info,buffer[i+3],buffer_poses_to_labels).str();
                    lisp_str << " )\n";
                    i += 3;
                    break;
                case Entry::OpCode::OpCodeType::NONCONDBRANCH:
                    lisp_str << op_as_str << " "<<serialize_jump_target(e.opcode.info,buffer[i+1],buffer_poses_to_labels).str();
                    lisp_str << "\n";
                    i += 1;
                    break;
                case Entry::OpCode::OpCodeType::TRUTHYCONDBRANCH1:
                case Entry::OpCode::OpCodeType::FALSEYCONDBRANCH1:
                    lisp_str << op_as_str <<" "<< serialize_first_src(e.opcode.info,buffer[i+1]).str();
                    lisp_str << " then goto "  << serialize_truthy_jump_target(e.opcode.info,buffer[i+2],buffer_poses_to_labels).str();
                    lisp_str << " )\n";
                    i += 2;
                    break;
                case Entry::OpCode::OpCodeType::NOP:
                case Entry::OpCode::OpCodeType::RAISEHALT:
                    lisp_str << op_as_str << ")\n";
                    break;
            }
        }
        auto it = buffer_poses_to_labels.find(buffer.size());
        if (it != buffer_poses_to_labels.end()) {
            string label = it->second;
            lisp_str << ":"<<label<<":\n";
        }

        return lisp_str.str();
    }

    std::stringstream GenieByteCodeBuffer::serialize_first_src(int info, const GenieByteCodeBuffer::Entry& entry) {
        std::stringstream result;
        if (info & Entry::INFO_FIRST_SRC_ARG_REGISTER) {
            char reg_scope = (info & Entry::INFO_FIRST_SRC_ARG_LOCAL_SCOPE_REGISTER )? '$':
                             (info & Entry::INFO_FIRST_SRC_ARG_GLOBAL_SCOPE_REGISTER)? '%': '@'; //@ is for argument register
            char reg_type =  (info & Entry::INFO_OP_TYPE_INT)? 'i':
                             (info & Entry::INFO_OP_TYPE_REAL)?'r':'?';

            result << reg_type << reg_scope << entry.ll_arg;
        }
        else if (info & Entry::INFO_FIRST_SRC_ARG_LONG_LITERAL) {
            result << entry.ll_arg;
        }
        else if (info & Entry::INFO_FIRST_SRC_ARG_ANY_LITERAL) {
            if (info & Entry::INFO_OP_TYPE_INT) {
                result << ((mpz_class*)entry.any_arg)->get_str();
            }
            else if (info & Entry::INFO_OP_TYPE_REAL) {
                result << ((GenieReal*)entry.any_arg)->value.get_str();
            }
        }
        return result;
    }

    std::stringstream GenieByteCodeBuffer::serialize_dest(int info, const GenieByteCodeBuffer::Entry& entry) {
        std::stringstream result;
        char reg_scope = (info & Entry::INFO_DEST_ARG_LOCAL_SCOPE_REGISTER )? '$':
                         (info & Entry::INFO_DEST_ARG_GLOBAL_SCOPE_REGISTER)? '%': '@'; //@ is for argument register
        char reg_type =  (info & Entry::INFO_OP_TYPE_INT)? 'i':
                         (info & Entry::INFO_OP_TYPE_REAL)?'r':'?';

        result << reg_type << reg_scope << entry.ll_arg;
        return result;
    }

    std::stringstream GenieByteCodeBuffer::serialize_second_src(int info, const GenieByteCodeBuffer::Entry &entry) {
        std::stringstream result;
        if (info & Entry::INFO_SECOND_SRC_ARG_REGISTER) {
            char reg_scope = (info & Entry::INFO_SECOND_SRC_ARG_LOCAL_SCOPE_REGISTER )? '$':
                             (info & Entry::INFO_SECOND_SRC_ARG_GLOBAL_SCOPE_REGISTER)? '%': '@'; //@ is for argument register
            char reg_type =  (info & Entry::INFO_OP_TYPE_INT)? 'i':
                             (info & Entry::INFO_OP_TYPE_REAL)?'r':'?';

            result << reg_type << reg_scope << entry.ll_arg;
        }
        else if (info & Entry::INFO_SECOND_SRC_ARG_LONG_LITERAL) {
            result << entry.ll_arg;
        }
        else if (info & Entry::INFO_SECOND_SRC_ARG_ANY_LITERAL) {
            if (info & Entry::INFO_OP_TYPE_INT) {
                result << ((mpz_class*)entry.any_arg)->get_str();
            }
            else if (info & Entry::INFO_OP_TYPE_REAL) {
                result << ((GenieReal*)entry.any_arg)->value.get_str();
            }
        }
        return result;
    }

    std::stringstream GenieByteCodeBuffer::serialize_truthy_jump_target(int info,
                                                                        GenieByteCodeBuffer::Entry& entry,
                                                                        const std::unordered_map<size_t, std::string>& buffer_poses_to_labels) {
        if (info & GenieByteCodeBuffer::Entry::INFO_SECOND_SRC_ARG_LONG_LITERAL) {
            return std::stringstream(
                    buffer_poses_to_labels.find(((size_t) entry.ll_arg))->second
            );
        }
        else {
            return serialize_second_src(info,entry);
        }
    }

    std::stringstream GenieByteCodeBuffer::serialize_falsey_jump_target(int info, GenieByteCodeBuffer::Entry &entry,
                                                                        const std::unordered_map<size_t, std::string>& buffer_poses_to_labels) {
        if (info & GenieByteCodeBuffer::Entry::INFO_BRANCH2_THIRD_SRC_ARG_LONG_LITERAL) {
            return std::stringstream(
                    buffer_poses_to_labels.find(((size_t) entry.ll_arg))->second
            );
        }
        else {
            return serialize_third_src(info,entry);
        }
    }

    std::stringstream GenieByteCodeBuffer::serialize_third_src(int info, GenieByteCodeBuffer::Entry& entry) {
        return std::stringstream();
    }

    std::stringstream GenieByteCodeBuffer::serialize_jump_target(int info, GenieByteCodeBuffer::Entry &entry,
                                                    const std::unordered_map<size_t, std::string>& buffer_poses_to_labels) {
        if (info & GenieByteCodeBuffer::Entry::INFO_FIRST_SRC_ARG_LONG_LITERAL) {
            return std::stringstream(
                    buffer_poses_to_labels.find(((size_t) entry.ll_arg))->second
            );
        }
        else {
            return serialize_first_src(info,entry);
        }
    }
}