//
// Created by cybex on 2019/06/04.
//

#ifndef COMPILER_DECLARATIONVAR_H
#define COMPILER_DECLARATIONVAR_H


#include "Declaration.h"
#include "Identifier.h"
#include "TypeDenoter.h"
#include "VarName.h"

class DeclarationVar: public Declaration, public VarName, public TypeDenoter {
public:
    DeclarationVar(VarName *varName, TypeDenoter *typeDenoter);

    std::string describe() override;
};


#endif //COMPILER_DECLARATIONVAR_H
