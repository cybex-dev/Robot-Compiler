#include <utility>
#include <regex>

//
// Created by cybex on 2019/06/04.
//

#include "PrimaryExpressionVar.h"

PrimaryExpressionVar::PrimaryExpressionVar(const std::string &spelling) : Identifier(spelling) {}

std::string PrimaryExpressionVar::getType() {
    if (std::regex_match(spelling, std::regex(("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?")))) {
#ifdef _INT
        return "INT";
#elif
        fprintf(stderr, ANSI_COLOR_RED "Unknown Type \'%s\' [Type int recognized]" ANSI_COLOR_RESET, spelling.data());
        return "";
#endif
    } else if (std::regex_match(spelling, std::regex(("^[a-zA-Z]+$")))) {
#ifdef _INT
        return "STRING";
#elif
        fprintf(stderr, ANSI_COLOR_RED "Unknown Type \'%s\' [Type std::string recognized]" ANSI_COLOR_RESET, spelling.data());
        return "";
#endif
    };

    fprintf(stderr, ANSI_COLOR_RED "Unknown Type \'%s\'" ANSI_COLOR_RESET, spelling.data());
    return "";
}

std::string PrimaryExpressionVar::describe() {
    return spelling;
}
