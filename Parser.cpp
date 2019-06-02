#include <utility>

#include <utility>

#include <utility>
#include <iostream>

//
// Created by cybex on 2019/05/03.
//

#include "Parser.h"
#include "IdentifierPE.h"

Parser::Parser(std::string sentence) {
    currentToken = nullptr;
    curTokenPos = -1;
    this->sentence = std::move(sentence);
}

void Parser::evaluate(){
    Scanner *s = new Scanner(std::move(sentence));
    tokenList = s->getTokens();
    fetchNextToken();
    Expression p = parseExpression();
}

Expression Parser::parseExpression() {
    PrimaryExpression *p1 = parsePrimary();
    Operate o = parseOperator();
    PrimaryExpression *p2 = parsePrimary();
    return Expression(*p1, o, *p2);
}

void Parser::acceptIt() {
    fetchNextToken();
}

void Parser::accept(TokenType type) {
    if (currentToken->matchesType(type)) {
        fetchNextToken();
    } else {
        std::cout << "Syntax error in Parser::accept(TokenType)";
    }
}

void Parser::fetchNextToken() {
    curTokenPos++;
    currentToken = (curTokenPos < tokenList.size())
            ? &tokenList.at(curTokenPos)
            : currentToken = nullptr;
}

PrimaryExpression* Parser::parsePrimary() {
    PrimaryExpression *pe = nullptr;
    if (currentToken == nullptr) {
        return nullptr;
    }
    switch (currentToken->getType()) {
        case Identifier: {
            pe = new IdentifierPE(parseIdentifier());
            break;
        }
        case LPar: {
            acceptIt();
            pe = new BracketsPE(parseExpression());
            accept(RPar);
            break;
        }
        default: {
            std::cout << "Syntax error in Parser::parsePrimary";
            break;
        }
    }
    return pe;
}

Identifie_r Parser::parseIdentifier() {
    auto *i = new Identifie_r(currentToken->getValue());
    accept(Identifier);
    return *i;
}

Operate Parser::parseOperator() {
    auto *o = new Operate(currentToken->getValue());
    accept(Operator);
    return *o;
}
