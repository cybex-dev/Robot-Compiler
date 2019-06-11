//
// Created by cybex on 2019/05/03.
//

#ifndef COMPILER_OPERATER_H
#define COMPILER_OPERATER_H


#include "Terminal.h"

class Operate: public Terminal {
public:
    explicit Operate(const std::string &spelling);

    std::string describe() override;
};


#endif //COMPILER_OPERATER_H
