//
// Created by cybex on 2019/05/03.
//

#ifndef COMPILER_TOKEN_H
#define COMPILER_TOKEN_H

#include <string>
#include <stdio.h>

enum TokenType{
    Identifier = 0, //[a-z]
    Operater = 1,   // +-/*
    LPar = 2,       // (
    RPar = 3,       // }
    DeclVar = 4,    // :
    DeclConst = 5,  // ~
    AssignVar = 6   // :=
};

class Token {

private:
    std::string value;
    TokenType tokenType;
public:
    Token() = default;

    bool operator==(const Token &rhs) const;

    bool operator!=(const Token &rhs) const;

    Token(std::string value, TokenType type);

    virtual ~Token();

    const std::string &getValue() const;

    void setValue(const std::string &value);

    TokenType getType() const;

    void setType(TokenType type);

    void showSpelling();

    bool matchesType(TokenType type);
};


#endif //COMPILER_TOKEN_H
