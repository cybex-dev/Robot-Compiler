#include <utility>

//
// Created by cybex on 2019/06/03.
//

#include "CommandIf.h"

CommandIf::CommandIf(Expression *condition, Command *trueCommand, Command *falseCommand) : Expression(condition),
                                                                                           trueCommand(trueCommand),
                                                                                           falseCommand(falseCommand) {

}

CommandIf::~CommandIf() {
    delete trueCommand;
    delete falseCommand;

}
