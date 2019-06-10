//
// Created by cybex on 2019/06/10.
//

#include "IntegerLiteral.h"
IntegerLiteral::IntegerLiteral(const std::string &spelling, IntegerLiteral *next) : Digit(spelling), next(next) {}

IntegerLiteral::IntegerLiteral(const std::string &spelling) : Digit(spelling) {

}

std::string IntegerLiteral::toString() {
    return Digit::toString() + next->toString();
}
