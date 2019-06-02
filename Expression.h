//
// Created by cybex on 2019/05/03.
//

#ifndef COMPILER_EXPRESSION_H
#define COMPILER_EXPRESSION_H

#include "PrimaryExpression.h"
#include "Operate.h"
#include "AST.h"

class Expression: AST{
public:
        PrimaryExpression P1, P2;
        Operate O;

    Expression(const PrimaryExpression &p1, const Operate &o, const PrimaryExpression &p2);
};


#endif //COMPILER_EXPRESSION_H
