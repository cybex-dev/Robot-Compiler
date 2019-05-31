//
// Created by cybex on 2019/05/03.
//

#include "Token.h"

Token::Token(const std::string &value, TokenType type) : value(value), type(type) {

}

Token::~Token() {

}

const std::string &Token::getValue() const {
    return value;
}

void Token::setValue(const std::string &value) {
    Token::value = value;
}

TokenType Token::getType() const {
    return type;
}

void Token::setType(TokenType type) {
    Token::type = type;
}

bool Token::operator==(const Token &rhs) const {
    return type == rhs.type;
}

bool Token::operator!=(const Token &rhs) const {
    return !(rhs == *this);
}
