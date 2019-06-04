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
};


#endif //COMPILER_IDENTIFIER_H
