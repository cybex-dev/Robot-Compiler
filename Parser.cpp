#include <utility>

//
// Created by cybex on 2019/05/03.
//

#include "Parser.h"

class Identifier Parser::parseIdentifier() {

}

Operate Parser::parseOperator() {
}

PrimaryExpression Parser::parsePrimary() {
}

Expression Parser::parseExpression() {
}

void Parser::acceptIt() {
    fetchNextToken();
}

void Parser::accept(TokenType type) {

}

void Parser::fetchNextToken() {
    curTokenPos++;
    if (curTokenPos < tokenList.size()) {
        currentToken = &tokenList.at(curTokenPos);
    } else {
        currentToken = nullptr;
    }
}