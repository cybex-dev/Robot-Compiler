//
// Created by cybex on 2019/05/03.
//

#ifndef COMPILER_IDENTIFIERPE_H
#define COMPILER_IDENTIFIERPE_H

#include "PrimaryExpression.h"
#include "Terminal.h"
#include "IdentifierPE.h"
#include "BracketsPE.h"

class IdentifierPE : public PrimaryExpression{

private:
    Terminal terminal;

public:
    IdentifierPE(Terminal terminal);

    virtual ~IdentifierPE();

};


#endif //COMPILER_IDENTIFIERPE_H
