//
// Created by cybex on 2019/05/03.
//

#ifndef COMPILER_SCANNER_H
#define COMPILER_SCANNER_H

#include <vector>
#include "Token.h"
#include "Expression.h"
#include "PrimaryExpression.h"
#include "Identifier.h"
#include "Operate.h"

class Scanner {
public:
    Scanner() = default;

    virtual ~Scanner();

private:


};


#endif //COMPILER_SCANNER_H
