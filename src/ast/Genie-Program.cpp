#include "Genie-Program.h"

using std::vector;
namespace genie {
    GenieProgram::GenieProgram(vector<GenieModule*>& ms) : modules(std::move(ms)) {}
    GenieProgram::GenieProgram() : modules(vector<GenieModule*>{}) {}

    void GenieProgram::free() {
        for (GenieModule* mod: modules) {
            mod->free();
            delete mod;
        }
    }
}