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
