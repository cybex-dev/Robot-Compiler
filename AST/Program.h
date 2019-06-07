//
// Created by cybex on 2019/06/03.
//

#ifndef COMPILER_PROGRAM_H
#define COMPILER_PROGRAM_H


#include "Command.h"

class Program: Command {
protected:
    Command *command = nullptr;

public:
    explicit Program(Command *command);

    virtual ~Program();
};


#endif //COMPILER_PROGRAM_H
