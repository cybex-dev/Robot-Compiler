//
// Created by cybex on 2019/06/04.
//

#ifndef COMPILER_PRIMARYEXPRESSIONVAR_H
#define COMPILER_PRIMARYEXPRESSIONVAR_H

#include <string>
#include "PrimaryExpression.h"
#include "VarName.h"

class PrimaryExpressionVar: PrimaryExpression, VarName {
public:
    PrimaryExpressionVar(const std::string &spelling);
};


#endif //COMPILER_PRIMARYEXPRESSIONVAR_H
