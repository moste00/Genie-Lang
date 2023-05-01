#include "Genie-TypeDef.h"

#include <utility>

namespace genie {
    GenieType::GenieType(genie::GenieType::SumType* sm) {
        t.as_sum = sm;
    }

    void GenieType::free() {
        delete t.as_sum;
        t.as_sum = nullptr;
    }

    GenieType::SumType::SumType(std::string& n, std::vector<std::string>& ts) {
        name = std::move(n);
        tags = std::move(ts);
    }
}