//
// Created by cybex on 2019/06/10.
//

#ifndef COMPILER_IDENTIFIERDIGIT_H
#define COMPILER_IDENTIFIERDIGIT_H

#include "Identifier.h"
#include "Digit.h"

class IdentifierDigit: public Identifier, public Digit{
public:
    IdentifierDigit(const std::string &spelling, const std::string &spelling1);
};


#endif //COMPILER_IDENTIFIERDIGIT_H
