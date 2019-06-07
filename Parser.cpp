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
    success = buildAST();
    if (success == 1) {
        // Error message handle in buildAST
        return success;
    }
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
    return 0;
}


//Expression Parser::parseExpression() {
//    PrimaryExpression_Expression *p1 = parsePrimary();
//    OperaterToken *o = parseOperator();
//    PrimaryExpression_Expression *p2 = parsePrimary();
//    return {p1, o, p2};
//}

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

int Parser::buildAST() {
    loadNextToken();
    // Here we define how any statement can start off in the language.
    // After this, the token type and the corresponding class takes care of the rest.
    while (curTokenPos < tokenList.size()) {
        switch (currentToken->getType()) {
            case IfToken: {
                parseCommand();
                break;
            }
            case LetToken: {
                // Run parseVarName
                parseCommand();
                break;
            }
            case VarToken: {
                // Run parseVarName
                parseDeclaration();
                break;
            }
            case ConstToken: {
                // Run parseVarName
                parseDeclaration();
                break;
            }
            case SpaceToken: {
                // Skip to next token - we allow spaces
                loadNextToken();
                break;
            }

            default: {
                fprintf(stdout, ANSI_COLOR_RED "Invalid %s \'%s\' \n" ANSI_COLOR_RESET,
                        Token::tokenDesc(currentToken->getType()).data(), currentToken->getValue().data());
                return 1;
            }

        }
    }
}

Program *Parser::parseProgram() {
    Command *c = parseCommand();
    return new Program(c);
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
            // We already have LetToken, proceed to next.
            Declaration *declaration = parseDeclaration();
            nextToken(TokenType::InToken);
            Command *command = parseCommand();

            // Prep next token
            loadNextToken();

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
            // We already have the IfToken, proceed to next
            Expression *condition = parseExpression();
            nextToken(TokenType::ThenToken);
            Command *trueCommand = parseCommand();
            nextToken(TokenType::ElseToken);
            Command *falseCommand = parseCommand();

            // Prep next token
            loadNextToken();

            // Build If Command
            return new CommandIf(condition, trueCommand, falseCommand);
        }
        case IdentifierToken: {
            /*
             * We are expecting 3 tokens.
             * 1. VarName
             * 2. AssignVarToken
             * 3. Expression
             */
            VarName *varName = parseVarName();
            nextToken(TokenType::AssignVarToken);
            Expression *expression = parseExpression();

            // Prep next token
            loadNextToken();

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

    // Prep next token
    loadNextToken();

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
            // We already have the VarToken, proceed to next
            VarName *id = parseVarName();
            nextToken(TokenType::DeclVarToken);
            TypeDenoter *type = parseTypeDenoter();

            // Prep next token
            loadNextToken();

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
            nextToken(TokenType::ConstToken);
            VarName *id = parseVarName();
            nextToken(TokenType::DeclConstToken);
            Expression *expression = parseExpression();

            // Prep next token
            loadNextToken();

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
            // Current token already read, proceed to expression
            Expression *e = parseExpression();
            nextToken(TokenType::RParToken);

            // Prep next token
            loadNextToken();

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
    return new TypeDenoter(currentToken->getValue());
}

VarName *Parser::parseVarName() {
    return new VarName(currentToken->getValue());
}

Operate *Parser::parseOperator() {
    return new Operate(currentToken->getValue());
}

Parser::~Parser() {
    delete currentToken;
}