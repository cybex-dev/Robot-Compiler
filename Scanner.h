//
// Created by cybex on 2019/05/03.
//

#ifndef COMPILER_SCANNER_H
#define COMPILER_SCANNER_H

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

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
    std::string toUpper(const std::string& str);
    TokenType findType(const std::string& spelling);
    TokenType findType(char spelling);
    std::vector<Token> getTokens();
    void displayTokens();
    virtual ~Scanner();

private:
    std::vector<Token> tokenList;
    std::string _sentence;
    int curPos;
};


#endif //COMPILER_SCANNER_H
