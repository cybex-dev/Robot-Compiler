#include <utility>

//
// Created by cybex on 2019/06/04.
//

#include "DeclarationVar.h"

DeclarationVar::DeclarationVar(VarName *varName, TypeDenoter *typeDenoter) : VarName(varName), TypeDenoter(*typeDenoter) {}

std::string DeclarationVar::describe() {
    return VarName::describe();
}
