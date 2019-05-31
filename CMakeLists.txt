cmake_minimum_required(VERSION 3.14)
project(Compiler)

set(CMAKE_CXX_STANDARD 14)

add_executable(Compiler main.cpp Token.cpp Token.h Scanner.cpp Scanner.h Parser.cpp Parser.h AST.h Expression.cpp Expression.h PrimaryExpression.cpp PrimaryExpression.h IndetifierPE.cpp IndetifierPE.h BracketsPE.cpp BracketsPE.h Terminal.cpp Terminal.h Identifier.cpp Identifier.h Operate.cpp Operate.h AST.cpp Program.cpp)