#include <utility>

//
// Created by cybex on 2019/06/04.
//

#include "DeclarationConst.h"

DeclarationConst::DeclarationConst(VarName *varName, Expression *expression) : VarName(varName),
                                                                               Expression(expression) {}
