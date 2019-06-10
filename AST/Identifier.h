//
// Created by cybex on 2019/05/03.
//

#ifndef COMPILER_IDENTIFIER_H
#define COMPILER_IDENTIFIER_H


#include "Terminal.h"

class Identifier : public Terminal{
public:
    virtual ~Identifier() = 0;

    std::string toString() override = 0;
};


#endif //COMPILER_IDENTIFIER_H
