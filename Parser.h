//
// Created by cybex on 2019/05/03.
//

#ifndef COMPILER_PARSER_H
#define COMPILER_PARSER_H


#include <string>
#include <vector>
#include <ostream>
#include "Token.h"
#include "Scanner.h"

class Parser {
private:
    std::vector<Token> tokenList;
    Token *currentToken;
    uint  curTokenPos;

    void fetchNextToken();
    void accept(TokenType type);
    void acceptIt();
    Expression parseExpression();
    PrimaryExpression parsePrimary();
    class Identifier parseIdentifier();
    Operate parseOperator();

public:
    Parser() = default;
};


#endif //COMPILER_PARSER_H
