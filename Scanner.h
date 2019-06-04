//
// Created by cybex on 2019/05/03.
//

#ifndef COMPILER_SCANNER_H
#define COMPILER_SCANNER_H

#include <utility>
#include <iostream>
#include "AST/Token.h"
#include <vector>

class Scanner {
public:
    explicit Scanner(std::string sentence);
    void buildTokenList();
    std::string buildNextToken();
    TokenType findType(const std::string& spelling);
    TokenType findType(char spelling);
    std::vector<Token> getTokens();
    void displayTokens();
    virtual ~Scanner();

private:
    std::vector<Token> tokenList;
    std::string sentence;
    int curPos;
};


#endif //COMPILER_SCANNER_H
