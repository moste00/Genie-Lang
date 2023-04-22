#pragma once

#include "../../lib/gmp-6.2.1/gmpxx.h"
#include <string>

using std::string;

namespace genie {
    struct GenieInt {
        union {
            long long as_ll;
            mpz_class* as_gmp_big_int;
        } value;

        GenieInt(const string&);
        GenieInt(long long);
        GenieInt(const GenieInt&);

        string to_str();

        void free();
    private:
        //The smalltalk trick : An 8-byte region of memory is a pointer if the LSB bit is 0
        //(because all new and malloc calls returns 8-byte-boundary-aligned pointers, the last 3 bits are always 0)
        //So that means we can safely "pun" the same region by setting the LSB to 1 and then storing whatever
        //we like in the remaining 31 bits
        bool is_machine_int() const {
            return (value.as_ll & 1) == 1;
        }
        long long as_machine_int() const {
            return (value.as_ll >> 1);
        };
    };
}