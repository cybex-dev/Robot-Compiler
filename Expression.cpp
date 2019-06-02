//
// Created by cybex on 2019/05/03.
//

#include "Expression.h"

Expression::Expression(const PrimaryExpression &p1, const Operate &o, const PrimaryExpression &p2) : P1(p1), P2(p2), O(o) {}
