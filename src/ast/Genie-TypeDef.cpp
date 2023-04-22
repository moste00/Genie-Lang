#include "Genie-TypeDef.h"

#include <utility>

namespace genie {
    GenieType::GenieType(genie::GenieType::SumType* sm) {
        t.as_sum = sm;
    }

    GenieType::SumType::SumType(std::string n, std::vector<std::string> ts) {
        name = std::move(n);
        tags = std::move(ts);
    }
}