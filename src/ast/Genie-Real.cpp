#include <sstream>
#include "Genie-Real.h"

namespace genie {

    GenieReal::GenieReal(std::string& val) {
        auto len = val.size();
        if (val[len-1] == '.') val.resize(len-1);

        auto decimal_dot_pos = val.find('.');
        if (decimal_dot_pos == std::string::npos) {
            value = std::move(mpq_class(val));
        }
        else {
            std::string val_without_dot = val.substr(0,decimal_dot_pos) + val.substr(decimal_dot_pos+1);
            value = std::move(mpq_class(val_without_dot));

            std::stringstream denominator_str;
            denominator_str << "1/1";
            auto denominator_len = len - decimal_dot_pos - 1;
            for(int i = 0; i < denominator_len; i++) {
                denominator_str << "0";
            }
            mpq_class denominator(denominator_str.str());
            value *= denominator;
        }
    }
}