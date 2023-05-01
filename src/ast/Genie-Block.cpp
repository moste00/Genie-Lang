#include "Genie-Block.h"

namespace genie {
    GenieBlock::GenieBlock(std::vector<GenieModule::ModuleElem>& elms) : elems(std::move(elms)) {}

    void GenieBlock::free() {
        for (GenieModule::ModuleElem elem : elems) {
            elem.free();
        }
    }
}
