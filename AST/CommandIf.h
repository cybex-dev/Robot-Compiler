//
// Created by cybex on 2019/06/03.
//

#ifndef COMPILER_COMMANDIF_H
#define COMPILER_COMMANDIF_H


#include "Command.h"
#include "Expression.h"

class CommandIf : Command{
protected:
    Expression condition;
    Command trueCommand, falseCommand;

public:
    CommandIf(Expression condition, const Command &trueCommand, const Command &falseCommand);
};


#endif //COMPILER_COMMANDIF_H
