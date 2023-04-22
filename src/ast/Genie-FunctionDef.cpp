#include "Genie-FunctionDef.h"

#include <utility>

namespace genie {
    GenieFunction::GenieFunction(std::string n, std::vector<FunctionParam>& ps,GenieBlock *b) : params(ps) {
        name = std::move(n);
        body = b;
    }

    GenieFunction::FunctionParam::FunctionParam(const GenieFunction::FunctionParam& copy) : annot(copy.annot) {
        name = copy.name;
        init = copy.init;
    }

    GenieFunction::FunctionParam::FunctionParam(std::string n, GenieData::TypeAnnotation annot, GenieExpr e) : annot(annot) {
        name = std::move(n);
        init = e;
    }

    GenieFunction::FunctionParam::FunctionParam() {}
}