#include "Parser.h"
#include "AST/DeclarationConst.h"
#include "AST/PrimaryExpressionVar.h"
#include "AST/CommandIf.h"
#include "AST/CommandAssign.h"
#include "AST/CommandLet.h"

//
// Created by cybex on 2019/05/03.
//

Parser::Parser(std::string sentence) {
    currentToken = nullptr;
    curTokenPos = -1;
    this->sentence = std::move(sentence);
}

/**
 * Builds the AST defined by Production Rules and performs syntax checks while building the tree
 */
int Parser::checkSyntax() {
    Scanner *s = new Scanner(std::move(sentence));
    if (_VERBOSITY < 2) {
        fprintf(stdout, "Building Token List...\n");
    } else if (_VERBOSITY <= 2) {
        fprintf(stdout, "Building Token List...");
    }
    int success = s->buildTokenList();
    if (success == 1) {
        // Error message handle in buildTokenList
        return success;
    }
    if (_VERBOSITY < 2) {
        fprintf(stdout, ANSI_COLOR_GREEN "Success\n" ANSI_COLOR_RESET);
    } else if (_VERBOSITY >= 3) {
        fprintf(stdout, ANSI_COLOR_GREEN "Token List Built\n" ANSI_COLOR_RESET);
    }
    tokenList = s->getTokenList();

    // Build AST
    if (_VERBOSITY < 3) {
        fprintf(stdout, "Building AST...\n");
    } else if (_VERBOSITY >= 3) {
        fprintf(stdout, "Building AST...");
    }

    buildAST();
    if (_VERBOSITY < 2) {
        fprintf(stdout, ANSI_COLOR_GREEN "Success\n" ANSI_COLOR_RESET);
    } else if (_VERBOSITY >= 3) {
        fprintf(stdout, ANSI_COLOR_GREEN "AST Built\n" ANSI_COLOR_RESET);
    }

    // Cleanup
    delete s;

    return success;
}

/**
 * Performs the contextual analysis ensuring correct variable scopes are used.
 */
int Parser::checkContext() {
    // use vtables with variable definitions. Each level have a variable referend with value true if initialized. Use variables at different levels.
    // Save depth where variable is declared. Check if current depth is less that variable -> variable out of scope.
    // Check variable name declared 2 times, show error.
    // Assign incompatibile types, show appropriate error.
    // check same variables names between datatypes

}

void Parser::nextToken(TokenType type) {
    if (currentToken->matchesType(type)) {
        loadNextToken();
    } else {
        fprintf(stdout, ANSI_COLOR_RED "Compilation Error: %s \'%s\' \n" ANSI_COLOR_RESET,
                Token::tokenDesc(currentToken->getType()).data(), currentToken->getValue().data());
        exit(1);
    }
}

Token *Parser::getNextToken(TokenType type) {
    nextToken(type);
    return currentToken;
}

void Parser::loadNextToken() {
    curTokenPos++;
    currentToken = (curTokenPos < tokenList.size())
                   ? &tokenList.at(curTokenPos)
                   : nullptr;
}

void Parser::buildAST() {
    // Prep next token
    loadNextToken();
    program = new Program(parseCommand());
}

Command *Parser::parseCommand() {

    switch (currentToken->getType()) {
        case LetToken: {
            /*
             * We are expecting 4 tokens
             * 1. LetToken
             * 2. Declaration
             * 3. InToken
             * 4. Command
             */
            loadNextToken();
            Declaration *declaration = parseDeclaration();
            nextToken(TokenType::InToken);
            Command *command = parseCommand();

            // Build Let Command
            return new CommandLet(declaration, command);
        }
        case IfToken: {
            /*
             * We are expecting 6 tokens minimum
             * 1. IfToken
             * 2. Expression
             * 3. ThenToken
             * 4. Command
             * 5. ElseToken
             * 6 Command
             */
            loadNextToken();
            Expression *condition = parseExpression();
            nextToken(TokenType::ThenToken);
            Command *trueCommand = parseCommand();
            nextToken(TokenType::ElseToken);
            Command *falseCommand = parseCommand();

            // Build If Command
            return new CommandIf(condition, trueCommand, falseCommand);
        }
        case IdentifierToken: {
            /*
             * We are expecting 3 tokens.
             * 1. VarName
             * 2. AssignVarToken
             * 3. Expression
             * 3. Expression
             */
            VarName *varName = parseVarName();
            nextToken(TokenType::AssignVarToken);
            Expression *expression = parseExpression();

            // Build variable assignment
            return new CommandAssign(varName, expression);
        }
        default: {
            fprintf(stdout, ANSI_COLOR_RED "Invalid %s \'%s\' \n" ANSI_COLOR_RESET,
                    Token::tokenDesc(currentToken->getType()).data(), currentToken->getValue().data());
            exit(1);
        }
    }
}

Expression *Parser::parseExpression() {
    PrimaryExpression *p1 = parsePrimaryExpression();
    Operate *o1 = parseOperator();
    PrimaryExpression *p2 = parsePrimaryExpression();

    // Build Expression
    return new Expression(p1, p2, o1);
}

Declaration *Parser::parseDeclaration() {
    switch (currentToken->getType()) {
        case VarToken: {
            /*
             * We expect 4 tokens.
             * 1. VarName
             * 2. IdentifierToken
             * 3. DeclVarToken
             * 4. IdentifierToken -> Type Denoter
             */
            loadNextToken();
            VarName *id = parseVarName();
            nextToken(TokenType::DeclVarToken);
            TypeDenoter *type = parseTypeDenoter();

            // Create vtable reference
            vardef_t vardef = {
                    .name = id,
                    .defined = false,
                    .isConst = false,
                    .type = type
            };

            // Add to vtable
            vtable.emplace_back(vardef);

            // build Variable Declaration
            return new DeclarationVar(id, type);
        }
        case ConstToken: {
/*
             * We expect 4 tokens.
             * 1. ConstName
             * 2. IdentifierToken
             * 3. DeclConstToken
             * 4. Expression
             */
            loadNextToken();
            nextToken(TokenType::ConstToken);
            VarName *id = parseVarName();
            nextToken(TokenType::DeclConstToken);
            Expression *expression = parseExpression();

            // Create vtable reference
            vardef_t vardef = {
                    .name = id,
                    .defined = false,
                    .isConst = false,
                    .type = type
            };

            // Add to vtable
            vtable.emplace_back(vardef);

            // build Constant Declaration
            return new DeclarationConst(id, expression);
        }
        default: {
            fprintf(stdout, ANSI_COLOR_RED "Invalid %s \'%s\' \n" ANSI_COLOR_RESET,
                    Token::tokenDesc(currentToken->getType()).data(), currentToken->getValue().data());
            exit(1);
        }
    }
}

PrimaryExpression *Parser::parsePrimaryExpression() {
    switch (currentToken->getType()) {
        case IdentifierToken: {
            std::string temp = currentToken->getValue();

            // Prep next token
            loadNextToken();

            // build Variable Expression
            return new PrimaryExpressionVar(temp);
        }

        case LParToken: {
            /*
             * We are expecting 3 'tokens'.
             * 1. LPar
             * 2. Expression
             * 3. Right Token
             */
            loadNextToken();
            Expression *e = parseExpression();
            nextToken(TokenType::RParToken);

            // build Primary Expression container
            return new PrimaryExpression_Expression(e);
        }
        default: {
            fprintf(stdout, ANSI_COLOR_RED "Invalid %s \'%s\' \n" ANSI_COLOR_RESET,
                    Token::tokenDesc(currentToken->getType()).data(), currentToken->getValue().data());
            exit(1);
        }

    }
}

TypeDenoter *Parser::parseTypeDenoter() {
    std::string type = currentToken->getValue();

    bool verified = false;

#ifdef _INT
    if (type == "int") {
        verified = true;
    }
#endif
#ifdef _DOUBLE
    if (type == "double") {
        verified = true;
    }
#endif
#ifdef _FLOAT
    if (type == "float") {
        verified = true;
    }
#endif
#ifdef _LONG
    if (type == "long") {
        verified = true;
    }
#endif
#ifdef _STRING
    if (type == "String") {
        verified = true;
    }
#endif
#ifdef _CHAR
    if (type == "char") {
        verified = true;
    }
#endif

    if (verified) {
        // Prep next token
        loadNextToken();

        return new TypeDenoter(type);
    }

    fprintf(stderr, "FATAL: Unknown data type \'%s\' is not defined!", type.data());
    exit(1);
}

VarName *Parser::parseVarName() {
    // Store temp value
    std::string temp = currentToken->getValue();

    // Prep next token
    loadNextToken();

    return new VarName(temp);
}

Operate *Parser::parseOperator() {
    // Store temp value
    std::string temp = currentToken->getValue();

    // Prep next token
    loadNextToken();

    return new Operate(temp);
}

Parser::~Parser() {
    delete currentToken;
    delete program;
}

void Parser::closeScope(Parser::vardef_t *vardef) {

}

void Parser::openScope(Parser::vardef_t *vardef) {

}
