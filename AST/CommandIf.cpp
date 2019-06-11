#include <utility>

//
// Created by cybex on 2019/06/03.
//

#include "CommandIf.h"

CommandIf::CommandIf(PrimaryExpression *condition, Command *trueCommand, Command *falseCommand) : primaryExpression(
        condition), trueCommand(trueCommand), falseCommand(falseCommand) {

}

std::string CommandIf::describe() {
    return Command::describe();
}

CommandIf::~CommandIf() {
    delete trueCommand;
    delete falseCommand;
    delete primaryExpression;
}

std::string CommandIf::getType() {
    return "BOOL";
}
