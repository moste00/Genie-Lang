#include "Genie-Int.h"

using std::to_string;

namespace genie {
    GenieInt::GenieInt(const string& val) {
        value.as_gmp_big_int = new mpz_class(val);
    }

    GenieInt::GenieInt(long long val) {
        if (val & 0x1000000000000000) value.as_gmp_big_int = new mpz_class(to_string(val));
        else {
            value.as_ll = val << 1;
            value.as_ll |= 1;
        }
    }

    GenieInt::GenieInt(const GenieInt& copy) {
        if (copy.is_machine_int()) {
            value.as_ll = copy.value.as_ll;
        }
        else {
            value.as_gmp_big_int = new mpz_class(*(copy.value.as_gmp_big_int));
        }
    }

    string GenieInt::to_str() {
        if (is_machine_int()) return to_string(as_machine_int());
        else {
            return value.as_gmp_big_int->get_str();
        }
    }

    void GenieInt::free() {
        if (!is_machine_int()) {
            delete value.as_gmp_big_int;
            value.as_gmp_big_int  = nullptr;
        }
    }
}