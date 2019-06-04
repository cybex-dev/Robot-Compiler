//
// Created by cybex on 2019/05/03.
//

#ifndef COMPILER_EXPRESSION_H
#define COMPILER_EXPRESSION_H


#include "AST.h"
#include "PrimaryExpression.h"
#include "Operate.h"

class Expression : AST {
    PrimaryExpression *P1, *P2;
    Operate *O;
public:
    Expression(PrimaryExpression *p1, PrimaryExpression *p2, Operate *o);
};


#endif //COMPILER_EXPRESSION_H
