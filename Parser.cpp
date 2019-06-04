#include "Parser.h"

//
// Created by cybex on 2019/05/03.
//

Parser::Parser(std::string sentence) {
    currentToken = nullptr;
    curTokenPos = -1;
    this->sentence = std::move(sentence);
}

/**
 * Builds the AST defined by Production Rules and performs syntax checks while building the tree
 */
void Parser::checkSyntax(){
    Scanner *s = new Scanner(std::move(sentence));
    tokenList = s->getTokens();
    fetchNextToken();
//    Expression p = parseExpression();
}

/**
 * Performs the contextual analysis ensuring correct variable scopes are used.
 */
void Parser::checkContext() {

}


//Expression Parser::parseExpression() {
//    PrimaryExpression_Expression *p1 = parsePrimary();
//    Operater *o = parseOperator();
//    PrimaryExpression_Expression *p2 = parsePrimary();
//    return {p1, o, p2};
//}

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
    if (curTokenPos < tokenList.size()) {
        currentToken = &tokenList.at(curTokenPos);
    } else {
        currentToken = nullptr;
    }
}

PrimaryExpression_Expression* Parser::parsePrimary() {
    PrimaryExpression_Expression *pe = nullptr;
    if (currentToken == nullptr) {
        return nullptr;
    }
    switch (currentToken->getType()) {
        case Identifier: {
//            pe = new IdentifierPE(parseIdentifier());
            break;
        }
        case LPar: {
            acceptIt();
//            pe = new BracketsPE(parseExpression());
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

//Identifier Parser::parseIdentifier() {
//    auto *i = new Identifier(currentToken->getValue());
//    accept(Identifier);
//    return *i;
//}
//
//Operater* Parser::parseOperator() {
//    auto *o = new Operater(currentToken->getValue());
//    accept(Operater);
//    return o;
//}