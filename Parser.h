//
// Created by cybex on 2019/05/03.
//

#ifndef COMPILER_PARSER_H
#define COMPILER_PARSER_H

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#include <utility>
#include <iostream>
#include <vector>
#include "Scanner.h"
#include "AST/PrimaryExpression_Expression.h"
#include "AST/Command.h"
#include "AST/Program.h"
#include "AST/Declaration.h"
#include "AST/TypeDenoter.h"
#include "AST/VarName.h"
#include "AST/Program.h"
#include "AST/Declaration.h"
#include "AST/TypeDenoter.h"
#include "AST/VarName.h"
#include "AST/DeclarationVar.h"

class Parser {
private:
    typedef struct {
        VarName *name;
        bool defined;
        bool isConst;
        TypeDenoter *type;
    } vardef_t;

    std::string sentence;
    std::vector<Token> tokenList;
    uint curTokenPos;
    Token *currentToken  = nullptr;
    Program *program = nullptr;
    std::vector<vardef_t> vtable;

    void loadNextToken();
    void nextToken(TokenType type);

public:
    explicit Parser(std::string sentence);
    int checkSyntax();
    int checkContext();
    virtual ~Parser();

    void buildAST();
    Command* parseCommand();
    Expression* parseExpression();
    Declaration* parseDeclaration();
    PrimaryExpression* parsePrimaryExpression();
    TypeDenoter* parseTypeDenoter();
    VarName* parseVarName();
    Token * getNextToken(TokenType type);
    Operate *parseOperator();

    void openScope(vardef_t *vardef);
    void closeScope(vardef_t *vardef);
};


#endif //COMPILER_PARSER_H
