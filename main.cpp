#include <iostream>
#include <regex>

#include "Parser.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main() {
    Parser *p = nullptr;
    std::string code;

    std::printf("=====================\nRobot Compiler (%d.%d)\n=====================\n", _VERSION_MAJOR,
                _VERSION_MINOR);
    std::printf("Type (Quit or quit) to quit\n");

    std::regex regex("(([Q]|[q])uit)");

    while (!std::regex_match(code, regex)) {
        while (code.empty()) {
            std::printf("\n>>> ");
#ifndef _TESTING
            std::getline(std::cin, code);
#else
            // normal - let command
            code = "let var t: int in t := t + t";

            // normal - if statement with let statements
//            code = "if(true+true) then let var e: int in e:=e+1 else let var z: int in z:=z+2";

            // syntax issue - missing in keyword
//            code = "let var t: int t := t + t";

            // test string <-> int incompatibility
//            code = "let var t: int in t := t + abc";

            // test int <-> int incompatibility, assignment, let command
//            code = "let var t: int in t := t + 111";

            // shows breaking of language example if statement requires Commands (i.e. assiignemnt, ifstatement or let)
//            code = "if(true+true) then x+x else z+z";

            // shows nested let commands with duplicate variables
//            code = "let var e: int in let var e: int in e:=e+e";

            // shows incompatible data types
//            code = "if(true+true) then x:=x+1 else z:=z+2";

            // shows undeclared variable
//            code = "if(true+true) then x:=z+z else z:=z+2";

            // shows incompatible data types
//            code = "let const e ~ 1+1 in e:=x+y";

            // shows editing of const
            code = "let const e ~ 1+1 in e:=2+2";
#endif
        }

        fprintf(stdout, "Compiling:\n---------------------------------------------\n\t" ANSI_COLOR_MAGENTA " \'%s\'" ANSI_COLOR_RESET " \n---------------------------------------------\n", code.data());

        if (_VERBOSITY >= 1)
            fprintf(stdout, ANSI_COLOR_BLUE "Compiling, please wait...\n" ANSI_COLOR_RESET);
        p = new Parser(code);
        int i = p->compile();
//        int ii = p->checkContext();
        code.clear();
        if (i == 0) {
            if (_VERBOSITY >= 1)
                fprintf(stderr, ANSI_COLOR_GREEN "\nSuccess!\n" ANSI_COLOR_RESET);
        } else {
            if (_VERBOSITY >= 1)
                fprintf(stderr, ANSI_COLOR_RED "\nFailed!\n" ANSI_COLOR_RESET);
        }
        code.clear();
#ifdef _TESTING
        exit(0);
#endif
    }

    return 0;
}