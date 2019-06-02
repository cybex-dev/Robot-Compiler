//
// Created by cybex on 2019/05/03.
//

#ifndef COMPILER_TERMINAL_H
#define COMPILER_TERMINAL_H

#include <string>
#include "AST.h"

class Terminal: AST {
private:
    std::string spelling;

public:
    explicit Terminal(std::string spelling);
};


#endif //COMPILER_TERMINAL_H
