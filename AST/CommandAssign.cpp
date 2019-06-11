#include <utility>

#include <utility>

#include <utility>

//
// Created by cybex on 2019/06/03.
//

#include "CommandAssign.h"

CommandAssign::CommandAssign(VarName *varName, Expression *expression): Expression(expression), VarName(varName) {

}

std::string CommandAssign::describe() {
    return Command::describe() + " " + Expression::describe() + " " + VarName::describe();
}

std::string CommandAssign::getType() {
    return Expression::getType();
}
