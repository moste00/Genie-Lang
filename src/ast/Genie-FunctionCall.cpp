#include "Genie-FunctionCall.h"

#include <utility>

genie::GenieFunCall::GenieFunCall(string  n, const std::vector<GenieExpr>& as) : fun_name(std::move(n)),args(as) {
}
