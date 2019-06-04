#include <utility>

#include <utility>

//
// Created by cybex on 2019/06/03.
//

#include "CommendLet.h"

CommendLet::CommendLet(Declaration declaration, const Command &command) : declaration(std::move(declaration)),
                                                                                 command(command) {}
