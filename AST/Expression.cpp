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

std::string Expression::describe() {
    return P1->describe() + " " + O->describe() + " " + P2->describe();
}

std::string Expression::getType() {
    return "";
}
//    // Get expression types
//    std::string p1 = P1->getType();
//    std::string p2 = P2->getType();
//
//    // Check if any types are null, this should be first in checking order
//    if(p1.length() == 0) {
//        fprintf(stderr, ANSI_COLOR_RED "FATAL: Unknown type for variable: \'%s\'\n" ANSI_COLOR_RESET, P1->describe().data());
//        return "";
//    }
//    if( p2.length() == 0){
//        fprintf(stderr, ANSI_COLOR_RED "FATAL: Unknown type for variable: \'%s\'\n" ANSI_COLOR_RESET, P2->describe().data());
//        return "";
//    }
//
//    // Check incompatible types
//    if(p1 != p2) {
//        fprintf(stderr, ANSI_COLOR_RED "FATAL: Incompatible types: \nP1: %s [Type \'%s\']\nP2: %s [Type \'%s\']\n" ANSI_COLOR_RESET, P1->describe().data(), p1.data(), P2->describe().data(), p2.data());
//        return "";
//    }
//
//    // If i
//    fprintf(stderr, ANSI_COLOR_RED "FATAL: Incompatible types: \nP1: %s\nP2: %s\n" ANSI_COLOR_RESET,)
//    return "";
//}
