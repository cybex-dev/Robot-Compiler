//
// Created by cybex on 2019/05/03.
//

#ifndef COMPILER_TOKEN_H
#define COMPILER_TOKEN_H

#include <string>

enum TokenType{
    Identifier = 0,
    Operator = 1,
    LPar = 2,
    RPar = 3
};

class Token {

private:
    std::string value;
    TokenType  type;
public:
    Token() = default;

    bool operator==(const Token &rhs) const;

    bool operator!=(const Token &rhs) const;

    Token(const std::string &value, TokenType type);

    virtual ~Token();

    const std::string &getValue() const;

    void setValue(const std::string &value);

    TokenType getType() const;

    void setType(TokenType type);
};


#endif //COMPILER_TOKEN_H
