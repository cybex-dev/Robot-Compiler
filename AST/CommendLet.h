//
// Created by cybex on 2019/06/03.
//

#ifndef COMPILER_COMMENDLET_H
#define COMPILER_COMMENDLET_H

#include "Command.h"
#include "Declaration.h"

class CommendLet: Command {
protected:
    Declaration declaration;
    Command command;
public:
    CommendLet(Declaration declaration, const Command &command);
};


#endif //COMPILER_COMMENDLET_H
