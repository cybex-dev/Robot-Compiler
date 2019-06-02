#include <utility>

//
// Created by cybex on 2019/05/03.
//

#include "IdentifierPE.h"

IdentifierPE::IdentifierPE(Terminal terminal) : terminal(std::move(terminal)) {}

IdentifierPE::~IdentifierPE() {

}
