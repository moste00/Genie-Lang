#include "Genie-Module.h"

namespace genie {
    GenieModule::GenieModule(std::vector<ModuleElem>& elms) : content(elms) {}
    GenieModule::GenieModule(std::vector<GenieModule*>& mods) : content(mods) {}

    GenieModule::ModuleContent::ModuleContent(std::vector<ModuleElem>& elms) : c(elms), t(Type::SIMPLE_MODULE) {}
    GenieModule::ModuleContent::ModuleContent(std::vector<GenieModule*>& mods)  : c(mods), t(Type::COMPOUND_MODULE) {}

    GenieModule::ModuleContent::_::_(std::vector<ModuleElem>& elms) : elems(elms) {}
    GenieModule::ModuleContent::_::_(std::vector<GenieModule*>& fs) : files(fs) {}

    GenieModule::ModuleElem::ModuleElem(GenieExpr ex) {
        t = Type::EXPR;
        e.expr = ex;
    }
    GenieModule::ModuleElem::ModuleElem(GenieType* typ) {
        t = Type::TYPE;
        e.type = typ;
    }
    GenieModule::ModuleElem::ModuleElem(GenieData* d) {
        t = Type::DATA;
        e.data = d;
    }
    GenieModule::ModuleElem::ModuleElem(GenieBlock* b) {
        t = Type::BLOCK;
        e.block = b;
    }
    GenieModule::ModuleElem::ModuleElem(GenieFunction* f) {
        t = Type::FUNCTION;
        e.function = f;
    }
    GenieModule::ModuleElem::ModuleElem(const ModuleElem& copy) {
        t = copy.t;
        e = copy.e;
    }

    GenieModule::ModuleElem::ModuleElem() {}
}
