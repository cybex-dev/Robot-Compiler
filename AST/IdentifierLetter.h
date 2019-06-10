//
// Created by cybex on 2019/06/10.
//

#ifndef COMPILER_IDENTIFIERLETTER_H
#define COMPILER_IDENTIFIERLETTER_H


#include "Identifier.h"
#include "Letter.h"

class IdentifierLetter: public Identifier, public Letter {
public:
    IdentifierLetter(const std::string &letter, const std::string &nextId);
};


#endif //COMPILER_IDENTIFIERLETTER_H
