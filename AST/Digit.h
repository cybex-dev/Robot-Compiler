//
// Created by cybex on 2019/06/10.
//

#ifndef COMPILER_DIGIT_H
#define COMPILER_DIGIT_H


#include "Terminal.h"

// inputs: [0-9]
class Digit: Terminal {
public:
    Digit(const std::string &spelling);
    std::string toString() override;
};


#endif //COMPILER_DIGIT_H
