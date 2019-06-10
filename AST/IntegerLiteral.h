//
// Created by cybex on 2019/06/10.
//

#ifndef COMPILER_INTEGERLITERAL_H
#define COMPILER_INTEGERLITERAL_H


#include "Digit.h"

class IntegerLiteral: public Digit{
public:
    IntegerLiteral *next = nullptr;

    IntegerLiteral(const std::string &spelling, IntegerLiteral *next);
    explicit IntegerLiteral(const std::string &spelling);

    std::string toString() override;
};


#endif //COMPILER_INTEGERLITERAL_H
