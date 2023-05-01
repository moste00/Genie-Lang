
#include "Genie-DataDef.h"

#include <utility>

namespace genie {
    GenieData::GenieData(GenieData::MutabilitySpecifier mspec, const string& n, const string& typ, GenieExpr init) {
        mut_spec = mspec;
        name = n;
        type = typ;
        initializer = init;
    }

    void GenieData::free() {
        initializer.free();
    }

}
