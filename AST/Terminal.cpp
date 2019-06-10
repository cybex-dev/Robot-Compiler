#include <utility>

//
// Created by cybex on 2019/05/03.
//

#include "Terminal.h"

Terminal::Terminal(std::string spelling) : spelling(std::move(spelling)) {}

std::string Terminal::toString() {
    return spelling;
}
