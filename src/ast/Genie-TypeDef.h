#pragma once

#include <vector>
#include <string>

namespace genie {
    struct GenieType {
        struct SumType {
            std::string name;
            std::vector<std::string> tags;

            SumType(std::string&,std::vector<std::string>&);
        };

        union {
            SumType* as_sum;
        } t;

        GenieType(SumType*);

        void free();
    };
}