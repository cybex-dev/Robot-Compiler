#include <utility>

#include <utility>

//
// Created by cybex on 2019/06/03.
//

#include "CommandLet.h"

CommandLet::CommandLet(Declaration *declaration, Command *command) : declaration(declaration),
                                                                     command(command) {}

CommandLet::~CommandLet() {
    delete declaration;
    delete command;
}

