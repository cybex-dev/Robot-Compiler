//
// Created by cybex on 2019/05/03.
//

#include "PrimaryExpression_Expression.h"

PrimaryExpression_Expression::PrimaryExpression_Expression(Expression *expression) : Expression(expression) {

}

PrimaryExpression_Expression::PrimaryExpression_Expression(PrimaryExpression *p1, PrimaryExpression *p2, Operate *o)
        : Expression(p1, p2, o) {

}

std::string PrimaryExpression_Expression::getType() {
    return Expression::getType();
}
