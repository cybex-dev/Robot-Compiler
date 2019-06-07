#include <utility>

//
// Created by cybex on 2019/06/03.
//

#include "Program.h"

Program::Program(Command *command): command(command) {

}

Program::~Program() {
    delete command;
}
