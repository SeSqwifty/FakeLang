FakeLang

FakeLang is a small mathematical language built in C++.

It uses an expression grammar to read and understand mathematical operations such as:

1 + 2
4 * 5
(10 - 2) / 4

The lexer converts the input into tokens such as numbers, operators and brackets. The parser then uses operator precedence to build an expression structure, so multiplication and division are handled before addition and subtraction.

The compiler converts the parsed expression into simple stack-style instructions, including:

PushInt
Add
Sub
Mul
Div

The program currently prints the generated tokens, the parsed expression and the compiled instructions.

FakeLang supports integers, brackets and the four basic mathematical operators: +, -, * and /.

This project demonstrates the basic stages of creating a programming language: lexing, parsing and compiling.

to compile with G++ you use 

"skm g++ -std=c++17 -Wall -Wextra -O2 -pipe main.cpp Lexer.cpp expr.cpp compiler.cpp instruction.cpp -o fakelang.exe"

then use "./fakelang.exe" to run the program to see how it works
