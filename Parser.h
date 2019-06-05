//
// Created by cybex on 2019/05/03.
//

#ifndef COMPILER_PARSER_H
#define COMPILER_PARSER_H

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#include <utility>
#include <iostream>
#include <vector>
#include "Scanner.h"
#include "AST/PrimaryExpression_Expression.h"

class Parser {
public:
    explicit Parser(std::string sentence);
    void checkSyntax();
    void checkContext();

private:
    std::string sentence;
    std::vector<Token> tokenList;
    Token *currentToken;
    uint  curTokenPos;

    void fetchNextToken();
    void accept(TokenType type);
    void acceptIt();

//    Expression parseExpression();
    PrimaryExpression_Expression* parsePrimary();
//    Operater* parseOperator();
//    Identifier parseIdentifier();
    int buildAST(std::vector<Token> vector);
};


#endif //COMPILER_PARSER_H
