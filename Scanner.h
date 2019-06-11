//
// Created by cybex on 2019/05/03.
//

#ifndef COMPILER_SCANNER_H
#define COMPILER_SCANNER_H

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"

#include <utility>
#include <iostream>
#include "AST/Token.h"
#include <stdio.h>
#include <regex>
#include <vector>

class Scanner {
public:
    Scanner();
    explicit Scanner(std::string sentence);
    int buildTokenList();
    int buildTokenList(std::string sentence);
    std::string buildNextToken();
    static std::string toUpper(const std::string& str);
    TokenType findType(const std::string& spelling);
    std::vector<Token> getTokenList();
    virtual ~Scanner();

private:
    std::vector<Token> tokenList;
    std::string _sentence;
    int curPos;
};


#endif //COMPILER_SCANNER_H
