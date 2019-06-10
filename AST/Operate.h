//
// Created by cybex on 2019/05/03.
//

#ifndef COMPILER_OPERATER_H
#define COMPILER_OPERATER_H


#include "Terminal.h"

class Operate: Terminal {
public:
    explicit Operate(const std::string &spelling);
    std::string toString() override;
};


#endif //COMPILER_OPERATER_H
