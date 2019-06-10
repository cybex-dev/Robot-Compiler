//
// Created by cybex on 2019/06/10.
//

#include "Letter.h"

Letter::Letter(const std::string &spelling) : Terminal(spelling) {}

std::string Letter::toString() {
    return Terminal::toString();
}
