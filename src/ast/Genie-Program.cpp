#include "Genie-Program.h"

using std::vector;
namespace genie {
    GenieProgram::GenieProgram(vector<GenieModule*>& ms) : modules(ms) {}
    GenieProgram::GenieProgram() : modules(vector<GenieModule*>{}) {}
}