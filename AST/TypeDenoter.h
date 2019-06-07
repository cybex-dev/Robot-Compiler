//
// Created by cybex on 2019/06/04.
//

#ifndef COMPILER_TYPEDENOTER_H
#define COMPILER_TYPEDENOTER_H

#include "Identifier.h"

class TypeDenoter: Identifier {
public:
    explicit TypeDenoter(const std::string &spelling);
    TypeDenoter(TypeDenoter &typeDenoter);
};


#endif //COMPILER_TYPEDENOTER_H
