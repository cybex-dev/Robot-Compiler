//
// Created by cybex on 2019/05/03.
//

#ifndef COMPILER_IDENTIFIE_R_H
#define COMPILER_IDENTIFIE_R_H


#include "Terminal.h"

class Identifie_r : public Terminal{
public:
    explicit Identifie_r(const std::string &spelling);

    virtual ~Identifie_r();
};


#endif //COMPILER_IDENTIFIE_R_H
