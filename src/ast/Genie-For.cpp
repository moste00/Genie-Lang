#include "Genie-For.h"

#include <utility>
namespace genie{

    GenieFor::GenieFor(const std::string& vr,const GenieExpr& s, const GenieExpr& e, const GenieExpr& st,GenieBlock* b) {
        start = s;
        end = e;
        step = st;
        body = b;
        var = vr;
    }
}