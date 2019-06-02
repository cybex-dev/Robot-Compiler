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
#include "Identifie_r.h"

class Parser {
public:
    explicit Parser(std::string sentence);
    void evaluate();

private:
    std::string sentence;
    std::vector<Token> tokenList;
    Token *currentToken;
    uint  curTokenPos;

    void fetchNextToken();
    void accept(TokenType type);
    void acceptIt();
    Expression parseExpression();
    PrimaryExpression* parsePrimary();
    Operate parseOperator();
    Identifie_r parseIdentifier();
};


#endif //COMPILER_PARSER_H
