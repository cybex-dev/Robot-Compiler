//
// Created by cybex on 2019/05/03.
//

#include "Operate.h"

Operate::Operate(const std::string &spelling) : Terminal(spelling) {}

std::string Operate::toString() {
    return Terminal::toString();
}
