//
// Created by cybex on 2019/06/04.
//

#ifndef COMPILER_DECLARATIONCONST_H
#define COMPILER_DECLARATIONCONST_H

#include "Declaration.h"
#include "Identifier.h"
#include "Expression.h"
#include "VarName.h"

class DeclarationConst: public Declaration, public VarName, public Expression {

public:
    DeclarationConst(VarName *varName, Expression *expression);

    std::string describe() override;
};


#endif //COMPILER_DECLARATIONCONST_H
