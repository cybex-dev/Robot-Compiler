//
// Created by cybex on 2019/06/04.
//

#ifndef COMPILER_PRIMARYEXPRESSIONVAR_H
#define COMPILER_PRIMARYEXPRESSIONVAR_H

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#include <string>
#include "PrimaryExpression.h"
#include "VarName.h"

class PrimaryExpressionVar: public PrimaryExpression, public Identifier {
public:
    explicit PrimaryExpressionVar(const std::string &spelling);
    std::string getType() override;

    std::string describe() override;
};


#endif //COMPILER_PRIMARYEXPRESSIONVAR_H
