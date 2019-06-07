//
// Created by cybex on 2019/06/04.
//

#ifndef COMPILER_VARNAME_H
#define COMPILER_VARNAME_H

#include "Identifier.h"

class VarName: public Identifier {
public:
    explicit VarName(const std::string &spelling);
    explicit VarName(VarName *varName);
};


#endif //COMPILER_VARNAME_H
