//
// Created by cybex on 2019/06/10.
//

#ifndef COMPILER_LETTER_H
#define COMPILER_LETTER_H


#include "Terminal.h"

// inputs: [a-zA-Z]
class Letter: Terminal {
public:
    Letter(const std::string &spelling);

private:
    std::string toString() override;
};


#endif //COMPILER_LETTER_H
