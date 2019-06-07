//
// Created by cybex on 2019/06/04.
//

#include "TypeDenoter.h"

TypeDenoter::TypeDenoter(const std::string &spelling) : Identifier(spelling) {}

TypeDenoter::TypeDenoter(TypeDenoter &typeDenoter): Identifier(typeDenoter.spelling) {

}
