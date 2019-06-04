//
// Created by cybex on 2019/06/04.
//

#ifndef COMPILER_DECLARATIONVAR_H
#define COMPILER_DECLARATIONVAR_H


#include "Declaration.h"
#include "Identifier.h"
#include "TypeDenoter.h"

class DeclarationVar: Declaration {
protected:
    Identifier identifier;
    TypeDenoter typeDenoter;

public:
    DeclarationVar(const Identifier &identifier, TypeDenoter typeDenoter);
};


#endif //COMPILER_DECLARATIONVAR_H
