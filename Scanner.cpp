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
        tokenList.emplace_back(nextToken, findType(nextToken));
    }
}

std::string Scanner::buildNextToken() {
    auto token = std::string();
//    while (sentence[curPos] == ' ') {
//        curPos++;
//    }
    while ((curPos < sentence.length())) {
        // We skip any spaces
        if (sentence[curPos] != ' ') {
            // Find type of token. If it is an identifier, then we read the next token, else we add it to the list
//            TokenType type = findType(std::string(":c"));
            std::string curToken = std::string(1, sentence.at(curPos));
            if (findType(curToken) != TokenType::Identifier) {
                // this limits the language to only 1 character TokenType if not an Identifier
                return curToken;
            }
            token.push_back(sentence.at(curPos));
        }
        curPos++;
    }
    return token;
}

TokenType Scanner::findType(char spelling) {
    return findType(std::string(1, spelling));
}

/// a+b
TokenType Scanner::findType(const std::string& spelling) {
    switch (spelling[0]) {
        case '(':
            return TokenType::LPar;
        case ')':
            return TokenType::RPar;
        case '+':
        case '-':
        case '*':
        case '/':
            return TokenType::Operater;
        case '~':
            return TokenType::DeclConst;
        case ':': {
            if (spelling.length() == 1) {
                return TokenType::DeclVar;
            } else if (spelling.length() == 2){
                if (spelling[1] == '=') {
                    return TokenType::AssignVar;
                } else {
                    printf("(FATAL: Syntax Error: Unrecognized symbol \'%s\'\nIf you wanted to assign a variable, please use 'myVar := 23 or \"SomeValue\")\nExiting.", spelling.data());
                    exit(1);
                }
            }
            break;
        }
        // [a-zA-Z][:=-]
        default: {
            return TokenType::Identifier;
//            for (char i : spelling) {
//                if (findType(i == TokenType::Identifier)) {
//                    // if / else
//                    // let in
//
//                }
//            }
        }
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

Scanner::~Scanner() {

}




