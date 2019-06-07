//
// Created by cybex on 2019/06/03.
//

#ifndef COMPILER_COMMANDIF_H
#define COMPILER_COMMANDIF_H


#include "Command.h"
#include "Expression.h"

class CommandIf : public Command, public Expression {
protected:
    Command *trueCommand = nullptr,
            *falseCommand = nullptr;

public:
    CommandIf(Expression *condition, Command *trueCommand, Command *falseCommand);

    virtual ~CommandIf();
};


#endif //COMPILER_COMMANDIF_H
