//
// Created by cybex on 2019/05/03.
//

#include "Expression.h"


Expression::Expression(PrimaryExpression *p1, PrimaryExpression *p2, Operate *o) : P1(p1), P2(p2), O(o) {}

Expression::Expression(Expression *expression) {
    P1 = expression->P1;
    P2 = expression->P2;
    O = expression->O;
}

Expression::~Expression() {
    delete P1;
    delete P2;
    delete O;
}

std::string Expression::toString() {
    return P1->toString() + O->toString() + P2->toString();
}
