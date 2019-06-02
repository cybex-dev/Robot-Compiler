#include <utility>

//
// Created by cybex on 2019/05/03.
//

#include "BracketsPE.h"

BracketsPE::BracketsPE(Expression expression) : expression(std::move(expression)) {}

BracketsPE::~BracketsPE() {

}
