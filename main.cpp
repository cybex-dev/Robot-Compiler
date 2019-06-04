#include <iostream>
#include <regex>

#include "Parser.h"

int main() {
    Parser *p = nullptr;
    std::string code;

    std::printf("=====================\nRobot Compiler (%d.%d)\n=====================\n", _VERSION_MAJOR, _VERSION_MINOR);
    std::printf("Type (Quit or quit) to quit\n");

    std::regex regex("(([Q]|[q])uit)");

    while (!std::regex_match(code, regex)) {
        while (code.empty()) {
            std::printf("\n>>> ");
            std::getline(std::cin >> std::ws, code);
        }

        p = new Parser(code);
        p->checkSyntax();
        p->checkContext();
        code.clear();
    }

    return 0;
}