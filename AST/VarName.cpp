#include <utility>

//
// Created by cybex on 2019/06/04.
//

#include "VarName.h"

VarName::VarName(const std::string &spelling) : Identifier(spelling) {}

VarName::VarName(VarName *varName): Identifier(varName->spelling) {

}

std::string VarName::describe() {
    return Identifier::describe();
}
