#include "Genie-FunctionDef.h"

#include <utility>

#include "Genie-Block.h"

namespace genie {
    GenieFunction::GenieFunction(std::string n, std::vector<FunctionParam>& ps,GenieBlock *b) : params(std::move(ps)) {
        name = std::move(n);
        body = b;
    }

    void GenieFunction::free() {
        for (FunctionParam param : params) {
            param.free();
        }
        body->free();
        delete body;
        body = nullptr;
    }

    GenieFunction::FunctionParam::FunctionParam(const GenieFunction::FunctionParam& copy) {
        name = copy.name;
        type = copy.type;
        init = copy.init;
    }

    GenieFunction::FunctionParam::FunctionParam() {}

    void GenieFunction::FunctionParam::free() {
        init.free();
    }

    GenieFunction::FunctionParam::FunctionParam(const string& n, const string& typ, GenieExpr ini) {
        name = n;
        type = typ;
        init = ini;
    }
}