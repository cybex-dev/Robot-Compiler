cmake_minimum_required(VERSION 3.14)
project(Compiler)

set(_VERSION_MAJOR 1)
set(_VERSION_MINOR 0)

set(CMAKE_CXX_STANDARD 14)
add_compile_definitions(VERSION_MAJOR=${_VERSION_MAJOR})
add_compile_definitions(VERSION_MINOR=${_VERSION_MINOR})


add_executable(Compiler main.cpp Token.cpp Token.h Scanner.cpp Scanner.h Parser.cpp Parser.h AST.h Expression.cpp Expression.h PrimaryExpression.cpp PrimaryExpression.h IdentifierPE.cpp IdentifierPE.h BracketsPE.cpp BracketsPE.h Terminal.cpp Terminal.h Identifie_r.cpp Identifie_r.h Operate.cpp Operate.h AST.cpp)