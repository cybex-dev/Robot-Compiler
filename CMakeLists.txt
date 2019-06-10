cmake_minimum_required(VERSION 3.14)
project(Compiler)

# Version
# Use to set verion information
set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)

# Variables
# Set true to enable debugging
set(VERBOSITY 3)

# Language Options
# Enable data types with 1, disable with 0
set(CHAR 1)
set(STRING 1)
set(FLOAT 1)
set(DOUBLE 1)
set(INT 1)
set(LONG 1)

# Uncomment for testing
add_compile_definitions("_TESTING")

# DO NOT TOUCH!
set(CMAKE_CXX_STANDARD 14)

# Conditional Checks
if (NOT DEFINED VERBOSITY)
    set(VERBOSITY 2)
endif ()

# Program Variables
message("Project Version: " ${VERSION_MAJOR} "." ${VERSION_MINOR})
message("Verbosity Level: " ${VERBOSITY})

# Preprocesor derivitives
add_compile_definitions(_VERBOSITY=${VERBOSITY})
add_compile_definitions(_VERSION_MAJOR=${VERSION_MAJOR})
add_compile_definitions(_VERSION_MINOR=${VERSION_MINOR})

if (CHAR EQUAL 1)
    add_compile_definitions(_CHAR)
endif ()
if (STRING EQUAL 1)
    add_compile_definitions(_STRING)
endif ()
if (FLOAT EQUAL 1)
    add_compile_definitions(_FLOAT)
endif ()
if (DOUBLE EQUAL 1)
    add_compile_definitions(_DOUBLE)
endif ()
if (INT EQUAL 1)
    add_compile_definitions(_INT)
endif ()
if (LONG EQUAL 1)
    add_compile_definitions(_LONG)
endif ()

# Compilation of sources to object to binary
add_executable(Compiler main.cpp AST/Token.cpp AST/Token.h Scanner.cpp Scanner.h Parser.cpp Parser.h AST/AST.h AST/Operate.cpp AST/Operate.h AST/Expression.cpp AST/Expression.h AST/PrimaryExpression_Expression.cpp AST/PrimaryExpression_Expression.h AST/Terminal.cpp AST/Terminal.h AST/Identifier.cpp AST/Identifier.h AST/AST.cpp AST/Program.cpp AST/Program.h AST/Command.cpp AST/Command.h AST/CommandIf.cpp AST/CommandIf.h AST/CommandAssign.cpp AST/CommandAssign.h AST/CommandLet.cpp AST/CommandLet.h AST/Declaration.cpp AST/Declaration.h AST/DeclarationConst.cpp AST/DeclarationConst.h AST/DeclarationVar.cpp AST/DeclarationVar.h AST/TypeDenoter.cpp AST/TypeDenoter.h AST/VarName.cpp AST/VarName.h AST/PrimaryExpressionVar.cpp AST/PrimaryExpressionVar.h AST/PrimaryExpression.cpp AST/PrimaryExpression.h)