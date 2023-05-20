#include "Genie-Switch.h"

namespace genie {
    GenieSwitch::GenieSwitch(const genie::GenieExpr& c, const vector<GenieCase>& casez) {
        cond = c;
        cases = casez;
    }

    GenieSwitch::GenieCase::GenieCase(const GenieExpr& g, GenieBlock* b) {
        guard = g;
        target = b;
    }

    GenieSwitch::GenieCase::GenieCase() {
        target = nullptr;
    }
}
