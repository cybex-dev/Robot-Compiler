//
// Created by cybex on 2019/05/03.
//

#ifndef COMPILER_EXPRESSION_H
#define COMPILER_EXPRESSION_H

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#include "AST.h"
#include "PrimaryExpression.h"
#include "Operate.h"

class Expression : public AST {
    PrimaryExpression *P1, *P2;
    Operate *O;
public:
    Expression(PrimaryExpression *p1, PrimaryExpression *p2, Operate *o);
    explicit Expression(Expression *expression);
    virtual ~Expression();
    std::string describe() override;

    virtual std::string getType();
};


#endif //COMPILER_EXPRESSION_H
