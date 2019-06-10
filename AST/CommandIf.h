//
// Created by cybex on 2019/06/03.
//

#ifndef COMPILER_COMMANDIF_H
#define COMPILER_COMMANDIF_H


#include "Command.h"
#include "Expression.h"

class CommandIf : public Command, public PrimaryExpression {
protected:
    PrimaryExpression* primaryExpression = nullptr;
    Command *trueCommand = nullptr,
            *falseCommand = nullptr;

public:
    CommandIf(PrimaryExpression *condition, Command *trueCommand, Command *falseCommand);

    virtual ~CommandIf();

    std::string describe() override;
};


#endif //COMPILER_COMMANDIF_H
