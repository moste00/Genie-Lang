#include "Genie-Module.h"

#include "Genie-Block.h"

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

    void GenieModule::ModuleElem::free() {
        switch (t) {
            case ModuleElem::Type::EXPR: {
                e.expr.free();
                break;
            }
            case ModuleElem::Type::TYPE: {
                e.type->free();
                delete e.type;
                e.type = nullptr;
                break;
            }
            case ModuleElem::Type::DATA: {
                e.data->free();
                delete e.data;
                e.data = nullptr;
                break;
            }
            case ModuleElem::Type::FUNCTION: {
                e.function->free();
                delete e.function;
                e.function = nullptr;
                break;
            }
            case ModuleElem::Type::BLOCK: {
                e.block->free();
                delete e.block;
                e.block = nullptr;
                break;
            }
        }
    }

    void GenieModule::free() {
        switch (content.t) {
            case Type::SIMPLE_MODULE: {
                for (ModuleElem elem : content.c.elems) {
                    elem.free();
                }
                break;
            }

            case Type::COMPOUND_MODULE: {
                for (GenieModule* file : content.c.files) {
                    file->free();
                    delete file;
                }
                break;
            }
        }
    }
}
