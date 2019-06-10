//
// Created by cybex on 2019/05/03.
//

#include "Identifier.h"

Identifier::Identifier(const std::string &spelling) : Terminal(spelling) {}

Identifier::~Identifier() = default;

std::string Identifier::describe() {
    return Terminal::describe();
}
