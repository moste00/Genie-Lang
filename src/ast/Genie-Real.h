#pragma once

#include "../../lib/gmp-6.2.1/gmpxx.h"
#include <string>

namespace genie {
    struct GenieReal {
        mpq_class value;
    };
}