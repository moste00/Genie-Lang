
#include "Genie-DataDef.h"

#include <utility>

namespace genie {
    GenieData::TypeAnnotation::TypeAnnotation(std::string ref) : ref_or_def(std::move(ref)), typ(TypeType::REF) {}

    GenieData::TypeAnnotation::TypeAnnotation(GenieType* def) : ref_or_def(def), typ((def == nullptr)? TypeType::NONE : TypeType::DEF) {}

    GenieData::TypeAnnotation::TypeAnnotation(const GenieData::TypeAnnotation& typ_annot) {
        typ = typ_annot.typ;
        if (typ_annot.typ == TypeType::NONE
         || typ_annot.typ == TypeType::DEF) {
            ref_or_def.typdef = typ_annot.ref_or_def.typdef;
        }
        else if (typ_annot.typ == TypeType::REF) {
            ref_or_def.typref = typ_annot.ref_or_def.typref;
        }
    }

    GenieData::TypeAnnotation &GenieData::TypeAnnotation::operator=(const GenieData::TypeAnnotation& typ_annot) {
        typ = typ_annot.typ;
        if (typ_annot.typ == TypeType::NONE
            || typ_annot.typ == TypeType::DEF) {
            ref_or_def.typdef = typ_annot.ref_or_def.typdef;
        }
        else if (typ_annot.typ == TypeType::REF) {
            ref_or_def.typref = typ_annot.ref_or_def.typref;
        }
        return *this;
    }

    GenieData::TypeAnnotation::TypeAnnotation() {}

    GenieData::GenieData(GenieData::MutabilitySpecifier msp, std::string n, const GenieData::TypeAnnotation& ta, GenieExpr e) : type(ta) {
        mut_spec = msp;
        name = std::move(n);
        initializer = e;
    }

    GenieData::TypeAnnotation::_::_(GenieType* t) {
        typdef = t;
    }
    GenieData::TypeAnnotation::_::_(std::string r) {
        typref = std::move(r);
    }
}
