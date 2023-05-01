#pragma once

#include <vector>
#include "Genie-Module.h"
namespace genie {
    struct GenieBlock {
        std::vector<GenieModule::ModuleElem> elems;

        GenieBlock(std::vector<GenieModule::ModuleElem>&);

        void free();
    };
}