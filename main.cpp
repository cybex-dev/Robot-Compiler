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

void loadExamples(std::vector<std::string> *container);

void showHelp();

void printCodeExamples(std::vector<std::string> vector);

int main(int argc, char *argv[]) {
    Parser *p = nullptr;
    std::string code;
    std::vector<std::string> codeExamples;

    // Check if we go to interactive mode.
    if (argc != 1) {

        // Load testing examples
        loadExamples(&codeExamples);

        for (int v = 1; v < argc; ++v) {
            std::string param(argv[v]);
            if (param == "-v" || param == "--verbosity") {
                v += 1;
                int verb(atoi(argv[v]));
                printf(ANSI_COLOR_GREEN "Verbosity Set: %d\n" ANSI_COLOR_RESET, verb);

                switch (verb) {
                    case 0:
                    case 1: {
#ifdef _VERBOSITY
#undef _VERBOSITY
#define _VERBOSITY 1
#endif
                        break;
                    }

                    case 2: {
#ifdef _VERBOSITY
#undef _VERBOSITY
#define _VERBOSITY 2
#endif
                        break;
                    }

                    default: {
#ifdef _VERBOSITY
#undef _VERBOSITY
#define _VERBOSITY 3
#endif
                        break;
                    }
                }
            } else if (param == "-h" || param == "--help") {
                showHelp();
                exit(0);
            } else if (param == "-l" || param == "--list-examples") {
                printCodeExamples(codeExamples);
                exit(0);
            } else if (param == "-t" || param == "--test") {
                v += 1;
                int index = atoi(argv[v]) - 1;
                if(index  > codeExamples.size() || index < 0) {
                    fprintf(stderr, ANSI_COLOR_RED "Invalid Test Code. Please select in the range [0-%lu]\n", codeExamples.size());
                } else {
                    fprintf(stderr, ANSI_COLOR_RED  ANSI_COLOR_CYAN "Testing Code String [%d]\n" ANSI_COLOR_RESET, index);
                    code = codeExamples[index];
                }
            } else {
                code += param + " ";
            }
        }
    }


    std::printf("=====================\nRobot Compiler (%d.%d)\n=====================\n", _VERSION_MAJOR,
                _VERSION_MINOR);
    std::printf("Type (Quit or quit) to quit\n");

    std::regex regex("(([Q]|[q])uit)");

    while (!std::regex_match(code, regex)) {
        while (code.empty()) {
            std::printf("\n>>> ");
            std::getline(std::cin, code);
        }

        fprintf(stdout,
                "Compiling:\n---------------------------------------------\n\t" ANSI_COLOR_MAGENTA " \'%s\'" ANSI_COLOR_RESET " \n---------------------------------------------\n",
                code.data());

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

        exit(0);
    }

    return 0;
}

void printCodeExamples(std::vector<std::string> vector) {
    fprintf(stdout, "Code Test Examples:\n");
    for (int i = 0; i < vector.size(); ++i) {
        fprintf(stdout, "[%d] \t" ANSI_COLOR_YELLOW " %s\n" ANSI_COLOR_RESET, i, vector.at(i).data());
    }
}


void loadExamples(std::vector<std::string> *container) {
    // normal - let command
    container->emplace_back("let var t: int in t := 1+1");

    // normal - if statement with let statements
    container->emplace_back("if(true+true) then let var e: int in e:=e+1 else let var z: int in z:=z+2");

    // syntax issue - missing in keyword
    container->emplace_back("let var t: int t := t + t");

    // test string <-> int incompatibility
    container->emplace_back("let var t: int in t := t + abc");

    // test int <-> int incompatibility, assignment, let command
    container->emplace_back("let var t: int in t := t + 111");

    // shows breaking of language example if statement requires Commands (i.e. assiignemnt, ifstatement or let)
    container->emplace_back("if(true+true) then x+x else z+z");

    // shows nested let commands with duplicate variables
    container->emplace_back("let var e: int in let var e: int in e:=e+e");

    // shows incompatible data types
    container->emplace_back("if(true+true) then x:=x+1 else z:=z+2");

    // shows undeclared variable
    container->emplace_back("if(true+true) then x:=z+z else z:=z+2");

    // shows incompatible data types
    container->emplace_back("let const e ~ 1+1 in e:=x+y");

    // shows editing of const
    container->emplace_back("let const e ~ 1+1 in e:=2+2");

}


void showHelp() {
    fprintf(stdout, "Robot Compiler - Help\n\n");
    fprintf(stdout, "\t-h | --help\t\t\tDisplay this help list\n");
    fprintf(stdout, "\t-t | --test [id]\t\t\tTest a specific code string. To find test code strings, use '--list-examples' flag'\n");
    fprintf(stdout, "\t-l | --list-examples\tShows a list of test code strings to run with the compiler.\n");
    fprintf(stdout, "\t-v | --verbosity [value]\t\tSet the debug verbosity\n\t\t1\tBasic messages\n\t\t2\tCompiler Process Messages\n\t\t3\tAll compiler messages including token processing.");
}