#include <utility>

//
// Created by cybex on 2019/05/03.
//

#include <iostream>
#include "Token.h"

Token::Token(std::string value, TokenType type) : value(std::move(value)), tokenType(type) {

}

Token::~Token() = default;

const std::string &Token::getValue() const {
    return value;
}

void Token::setValue(const std::string &value) {
    Token::value = value;
}

TokenType Token::getType() const {
    return tokenType;
}

void Token::setType(TokenType type) {
    Token::tokenType = type;
}

bool Token::operator==(const Token &rhs) const {
    return tokenType == rhs.tokenType;
}

bool Token::operator!=(const Token &rhs) const {
    return !(rhs == *this);
}

bool Token::matchesType(TokenType type) {
    return tokenType == type;
}

void Token::showSpelling() {
    std::cout << value;
}

std::string Token::tokenDesc(TokenType type) {
    switch (type) {
        case -2:
            return "InvalidIdentifier";
        case -1:
            return "InvalidToken";
        case 0:
            return "Identifier";
        case 1:
            return "Operater";
        case 2:
            return "LPar";
        case 3:
            return "RPar";
        case 4:
            return "DeclVar";
        case 5:
            return "DeclConst";
        case 6:
            return "AssignVar";
        case 10:
            return "IfToken";
        case 11:
            return "ThenToken";
        case 12:
            return "ElseToken";
        case 13:
            return "LetToken";
        case 14:
            return "InToken";
        case 15:
            return "ConstToken";
        case 16:
            return "VarToken";
        case 17:
            return "SpaceToken";
    }

    return "";
}

std::string Token::tokenDesc() {
    return tokenDesc(tokenType);
}
