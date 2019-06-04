//
// Created by cybex on 2019/06/04.
//

#ifndef COMPILER_DECLARATIONCONST_H
#define COMPILER_DECLARATIONCONST_H

#include "Declaration.h"
#include "Identifier.h"
#include "Expression.h"

class DeclarationConst: Declaration {
protected:
    Identifier identifier;
    Expression expression;

public:
    DeclarationConst(const Identifier &identifier, Expression expression);
};


#endif //COMPILER_DECLARATIONCONST_H
