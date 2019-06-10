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
    std::string describe() override;
};


#endif //COMPILER_TYPEDENOTER_H
