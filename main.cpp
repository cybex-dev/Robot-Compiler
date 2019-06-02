#include <iostream>
#include <regex>

#include "Parser.h"

int main() {
    Parser *p = 0;
    std::string code;

    std::printf("=====================\nRobot Compiler (%d.%d)\n=====================\n", VERSION_MAJOR, VERSION_MINOR);
    std::printf("Type (Quit or quit) to quit\n");

    std::regex regex("(([Q]|[q])uit)");

    while (!std::regex_match(code, regex)) {
        while (code.empty()) {
            std::printf("\n>>> ");
            std::cin >> code;
        }

        p = new Parser(code);
        p->evaluate();
    }

    return 0;
}