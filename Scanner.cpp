#include <utility>
#include <assert.h>

//
// Created by cybex on 2019/05/03.
//

#include "Scanner.h"
#include "Parser.h"

Scanner::Scanner() : curPos(0) {
    _sentence = "";
}

Scanner::Scanner(std::string sentence) : _sentence(std::move(sentence)), curPos(0) {

}

int Scanner::buildTokenList(std::string sentence) {
    _sentence = std::move(sentence);
    return buildTokenList();
}

int Scanner::buildTokenList() {
    while (curPos < _sentence.length()) {
        // Get next token
        std::string curToken = buildNextToken();
        // Get next token type
        TokenType tokenType = findType(curToken);

        // Check for invalid identifiers
        if (tokenType == TokenType::InvalidIdentifier
            || tokenType == TokenType::InvalidToken) {
            printf(ANSI_COLOR_GREEN "Failed!\nError Parsing Tokens. Check your Syntax" ANSI_COLOR_RESET);
            return 1;
        }

        // Here, the assumption is the tokentype is valid and sane. We add it to the tokenlist
        tokenList.emplace_back(Token(curToken, tokenType));
    }

    // All tokens processed here and are sane.
    return 0;
}

std::string Scanner::buildNextToken() {
    // Check if we are within our limits
    if (curPos >= _sentence.length()) {
        return "";
    }

    // Get initial values
    std::string token = std::string(1, _sentence[curPos++]);
    TokenType type = findType(token);
    TokenType nextType;

    // Loop over string until either a token mismatch is found or string has compeleted.
    while (curPos < _sentence.length()) {
        // Peek ahead. See if the next character type matches the current
        std::string readahead = std::string(1, _sentence[curPos]);
        nextType = findType(readahead);

        // If it does, increment current pos and add to token
        if (type == nextType) {
            curPos++;
            token += readahead;
        } else {
            // We got a new token type, this means we have reached the end of the current token definition
            break;
        }
    }

    return token;
}

TokenType Scanner::findType(char spelling) {
    return findType(std::string(1, spelling));
}

TokenType Scanner::findType(const std::string &_spelling) {
    std::string spelling = _spelling;
    switch (spelling[0]) {
        // Left bracket
        case '(':
            return TokenType::LPar;

            // Right bracket
        case ')':
            return TokenType::RPar;

            // Operators
        case '+':
        case '-':
        case '*':
        case '/':
            return TokenType::Operater;

            // Const Assignment
        case '~':
            return TokenType::DeclConst;

            // Declaration of variable or assignment. Depends on 2nd char
        case ':': {
            // Variable Declaration
            if (spelling.length() == 1) {
                return TokenType::DeclVar;
            }
            // Var assignment
            switch (spelling[1]) {
                // :=
                case '=': {
                    return TokenType::AssignVar;
                }

                default: {
                    printf(ANSI_COLOR_RED "Invalid Token \'%s\'\n" ANSI_COLOR_RESET, spelling.data());
                    return TokenType::InvalidToken;
                }
            }
        }
            // [a-zA-Z]
        default: {

            // Handle spaces, as these are important when language depends on spaces between 'THEN' and s'Command'
            if (spelling == " ")
                return TokenType::SpaceToken;

            // Regex matches:
            //  myVar, varr, var123,
            //  but not 1var, +varr
            if (!std::regex_match(spelling, std::regex("^[a-zA-Z0-9]{0,}$"))) {
                printf(ANSI_COLOR_RED "Invalid identifier(s) \'%s\'\n" ANSI_COLOR_RESET, spelling.data());
                return TokenType::InvalidIdentifier;
            }

            spelling = toUpper(spelling);
            // Scan non-terminals
            if (spelling == "IF") {
                return TokenType::IfToken;
            } else if (spelling == "THEN") {
                return TokenType::ThenToken;
            } else if (spelling == "ELSE") {
                return TokenType::ElseToken;
            } else if (spelling == "LET") {
                return TokenType::LetToken;
            } else if (spelling == "IN") {
                return TokenType::InToken;
            } else if (spelling == "VAR") {
                return TokenType::VarToken;
            } else if (spelling == "CONST") {
                return TokenType::ConstToken;
            } else {
                return TokenType::Identifier;
            }
        }
    }
}

std::vector<Token> Scanner::getTokens() {
    return tokenList;
}

void Scanner::displayTokens() {
    for (auto &i : tokenList) {
        i.showSpelling();
    }
}

std::string Scanner::toUpper(const std::string &str) {
    std::string temp;
    std::locale loc;
    for (char i : str)
        temp.push_back(std::toupper(i, loc));
    return temp;
}

Scanner::~Scanner() {

}



