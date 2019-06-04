//
// Created by cybex on 2019/05/03.
//

#include "PrimaryExpression_Expression.h"


//PrimaryExpression_Expression::PrimaryExpression_Expression(PrimaryExpression *p1, Operate *o, PrimaryExpression *p2)
//        : P1(p1), P2(p2), O(o) {}

PrimaryExpression_Expression::PrimaryExpression_Expression(PrimaryExpression *p1, PrimaryExpression *p2, Operate *o)
        : Expression(p1, p2, o) {}
