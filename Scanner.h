//
// Created by cybex on 2019/05/03.
//

#ifndef COMPILER_SCANNER_H
#define COMPILER_SCANNER_H

#include <vector>
#include "Token.h"
#include "Expression.h"
#include "PrimaryExpression.h"
#include "Identifie_r.h"
#include "Operate.h"

class Scanner {
public:
    Scanner(std::string sentence);
    void buildTokenList();
    std::string& buildNextToken();
    static TokenType findType(char spelling);
    std::vector<Token> getTokens();
    void displayTokens();
    virtual ~Scanner();

private:
    std::vector<Token> tokenList;
    std::string sentence;
    int curPos;
};


#endif //COMPILER_SCANNER_H
