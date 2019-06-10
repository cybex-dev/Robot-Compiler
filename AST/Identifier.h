//
// Created by cybex on 2019/05/03.
//

#ifndef COMPILER_IDENTIFIER_H
#define COMPILER_IDENTIFIER_H


#include "Terminal.h"

class Identifier : public Terminal{
public:
    explicit Identifier(const std::string &spelling);

    virtual ~Identifier();

    virtual std::string describe();
};


#endif //COMPILER_IDENTIFIER_H
