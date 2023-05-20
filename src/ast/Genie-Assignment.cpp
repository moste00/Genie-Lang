#include "Genie-Assignment.h"

namespace genie {
    GenieAssign::GenieAssign(std::string name, GenieExpr value) : lhs(std::move(name)) {
        rhs = value;
    }
}
