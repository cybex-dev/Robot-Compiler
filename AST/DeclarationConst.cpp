#include <utility>

//
// Created by cybex on 2019/06/04.
//

#include "DeclarationConst.h"

DeclarationConst::DeclarationConst(const Identifier &identifier, Expression expression) : identifier(identifier),
                                                                                                 expression(std::move(
                                                                                                         expression)) {}
