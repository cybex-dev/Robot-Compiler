//
// Created by cybex on 2019/05/03.
//

#ifndef COMPILER_PRIMARYEXPRESSION_EXPRESSION_H
#define COMPILER_PRIMARYEXPRESSION_EXPRESSION_H


#include "Operate.h"
#include "PrimaryExpression.h"
#include "Expression.h"

class PrimaryExpression_Expression : public Expression, public PrimaryExpression  {
public:
    PrimaryExpression_Expression(PrimaryExpression *p1, PrimaryExpression *p2, Operate *o);
    explicit PrimaryExpression_Expression(Expression *expression);
};


#endif //COMPILER_PRIMARYEXPRESSION_EXPRESSION_H
