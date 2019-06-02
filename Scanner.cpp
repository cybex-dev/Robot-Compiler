#include <utility>

//
// Created by cybex on 2019/05/03.
//

#include "Scanner.h"

Scanner::Scanner(std::string sentence) : sentence(std::move(sentence)), curPos(0) {
    buildTokenList();
}

void Scanner::buildTokenList() {
    while (curPos < sentence.length()) {
        std::string nextToken = buildNextToken();
        char c = nextToken[0];
        tokenList.emplace_back(nextToken, findType(c));
    }
}

std::string &Scanner::buildNextToken() {
    auto *token = new std::string;
    while (sentence[curPos] == ' ') {
        curPos++;
    }
    while ((curPos < sentence.length()) && (sentence[curPos] != ' ')) {
        token = &token->append(&sentence[curPos]);
    }
    return *token;
}

TokenType Scanner::findType(char spelling) {
    switch (spelling) {
        case '(':
            return TokenType::LPar;
        case ')':
            return TokenType::RPar;
        case '+':
        case '-':
        case '*':
        case '/':
            return TokenType::Operator;
        default:
            return TokenType::Identifier;
    }
}

std::vector<Token> Scanner::getTokens() {
    return tokenList;
}

void Scanner::displayTokens() {
    for (auto & i : tokenList) {
        i.showSpelling();
    }
}




