//
// Created by cybex on 2019/06/03.
//

#ifndef COMPILER_COMMANDASSIGN_H
#define COMPILER_COMMANDASSIGN_H


#include "Command.h"
#include "VarName.h"
#include "Expression.h"

class CommandAssign: public Command, public Expression, public VarName {
public:
    CommandAssign(VarName *varName, Expression *expression);

    std::string describe() override;

    std::string getType() override;
};


#endif //COMPILER_COMMANDASSIGN_H
