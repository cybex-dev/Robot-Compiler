# Robot Compiler

What is with the name? I have no idea. If you have a better one, please let me know :)

## What is it?
A simple compiler that can compile an single line application using Pascal syntax.

### Examples lines to compile:

* Let Statement
```
let 
  var t: int 
in 
  t := 1+1
```
* If Statement
```
  if(true+true) then 
      let 
        var e: int 
      in 
        e:=e+1 
   else 
      let 
        var z: int 
      in 
        z:=z+2
```

## Under the hood

The compiler implements:
* Syntax Analysis: reads the input code (list of tokens), scans and parses these tokens to build the [Abstract Syntax Tree (AST)](https://en.wikipedia.org/wiki/Abstract_syntax_tree) 
* Contextual Analysis: A very simple implementation for scope checking of variables

**Program does not require spaces between tokens**

## Production Rules Implemented
*Production rules is shown in [Backus-Naur Form (BNF)](https://en.wikipedia.org/wiki/Backus%E2%80%93Naur_form)*

| Non-Terminal Symbols |  | Expressions  |
|------------------|-----|-----------------------------------------------------|
| Program 		     | ::= | 	Command                                            |
| Command 		     | ::= |	if PrimaryExpression then Command else Command     |
| 				         |     |  V-name := Expression                               |
| 				         |     |  let Declaration in Command                         |
| Expression 		   | ::= |	PrimaryExpression Operator PrimaryExpression       |
| Declaration		   | ::= | 	var Identifier: Type-Denoter                        |
|                  |     |  const Identifier ~ Expression	                      |
| PrimaryExpression| ::= |	V-name                                             |
| 			           | ::= |	( Expression )                                     |
| Type-Denoter		 | ::= |	Identifier                                          |
| V-name		       | ::= | 	Identifier                                          |  
| Identifier 		    | ::= |	 Literal                                            |
|                  |     |  Digit Literal                                      |
|                  |     |  Literal Digit                                      |
| Operator 		     | ::= |	+                                                  |
|                  |     |  -                                                  |
|                  |     |  *                                                  |
|                  |     |  /                                                  |

*Note: Identifier implemented as std::string (no distinction made between digits and chars)*

## Future Work
* Add more detailed production rules looking at literals and digits
* Add visual representation of tree built
* Add more completed production rules allowing for multi-line code blocks
* Add files to pass in and compile
* Add ability to run compiled files using Code Generation

## Contributing?
You are more than welcome to submit PR or collaborate :)
