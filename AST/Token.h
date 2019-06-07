//
// Created by cybex on 2019/05/03.
//

#ifndef COMPILER_TOKEN_H
#define COMPILER_TOKEN_H

#include <string>
#include <stdio.h>

enum TokenType {
    InvalidIdentifier = -2, // Invalid Char String [a-zA-Z0-9]
    InvalidToken = -1, // Invalid Single Char (most likely a misplaced +/-* :=, etc)
    IdentifierToken = 0,  //[a-z]
    OperaterToken = 1,  // +-/*
    LParToken = 2,  // (
    RParToken = 3,  // }
    DeclVarToken = 4,  // :
    DeclConstToken = 5,  // ~
    AssignVarToken = 6,  // :=
    IfToken = 10, // IF
    ThenToken = 11, // THEN
    ElseToken = 12, // ELSE
    LetToken = 13, // LET
    InToken = 14, // IN
    ConstToken = 15, // CONST
    VarToken = 16, // VAR
    SpaceToken = 17  // ' '
};

class Token {

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

    std::string tokenDesc();

    static std::string tokenDesc(TokenType type);

private:
    std::string value;
    TokenType tokenType = TokenType::InvalidToken;
};


#endif //COMPILER_TOKEN_H
