#include "Genie-For.h"

#include <utility>
namespace genie{

    GenieFor::GenieFor(const GenieExpr& s, const GenieExpr& e, const GenieExpr& st,GenieBlock* b) {
        start = s;
        end = e;
        step = st;
        body = b;
    }
}