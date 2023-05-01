#pragma once

#include "vector"
#include "Genie-Module.h"

namespace genie {
    struct GenieProgram {
        std::vector<GenieModule*> modules;
        GenieProgram(std::vector<GenieModule*>& es);
        GenieProgram();

        void free();
    };
}