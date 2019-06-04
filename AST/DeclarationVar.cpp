#include <utility>

//
// Created by cybex on 2019/06/04.
//

#include "DeclarationVar.h"

DeclarationVar::DeclarationVar(const Identifier &identifier, TypeDenoter typeDenoter) : identifier(identifier),
                                                                                               typeDenoter(std::move(
                                                                                                       typeDenoter)) {}
