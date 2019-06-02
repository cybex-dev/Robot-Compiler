//
// Created by cybex on 2019/05/03.
//

#ifndef COMPILER_BRACKETSPE_H
#define COMPILER_BRACKETSPE_H


#include "Expression.h"

class BracketsPE : public PrimaryExpression {
private:
    Expression expression;
public:
    explicit BracketsPE(Expression expression);
    virtual ~BracketsPE();
};


#endif //COMPILER_BRACKETSPE_H
