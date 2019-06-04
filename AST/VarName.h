//
// Created by cybex on 2019/06/04.
//

#ifndef COMPILER_VARNAME_H
#define COMPILER_VARNAME_H

#include "Identifier.h"

class VarName: Identifier {
public:
    VarName(const std::string &spelling);
};


#endif //COMPILER_VARNAME_H
