#pragma once

#include "../Genie-ParserInvoker.h"

namespace genie {
    class BisonInvoker : ParserInvoker {
    public:
        void add_file(const string &string1) override;

        void add_string(const string &string1) override;
    };
}