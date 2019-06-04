#include <utility>

//
// Created by cybex on 2019/06/03.
//

#include "CommandIf.h"

CommandIf::CommandIf(Expression condition, const Command &trueCommand, const Command &falseCommand) : condition(std::move(
        condition)), trueCommand(trueCommand), falseCommand(falseCommand) {}
