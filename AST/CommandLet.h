//
// Created by cybex on 2019/06/03.
//

#ifndef COMPILER_COMMANDLET_H
#define COMPILER_COMMANDLET_H

#include "Command.h"
#include "Declaration.h"

class CommandLet: public Declaration, public Command {
protected:
    Declaration *declaration = nullptr;
    Command *command = nullptr;
public:
    CommandLet(Declaration *declaration, Command *command);

    virtual ~CommandLet();

    std::string describe() override;
};


#endif //COMPILER_COMMANDLET_H
