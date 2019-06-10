//
// Created by cybex on 2019/06/10.
//

#include "Digit.h"

Digit::Digit(const std::string &spelling) : Terminal(spelling) {}

std::string Digit::toString() {
    return Terminal::toString();
}
