#include "splashkit.h"
#include "splashkit-arrays.h"
#include <string>

#include "token.h"
#include "Lexer.h"
#include "expr.h"
#include "parser.h"
#include "complier.h"

int main()
{
    write("what do you want to know the tokens of ");
    string source = read_line();

    Lexer lexer;
    dynamic_array<Token> tokens = lexer.scan_tokens(source);

    write_line(tokens_to_string(tokens));
    write_line("\n");
    parser parser(tokens);
    Expr expression = parser.parse();
    write_line(expr_to_string(expression));

    complier compiler;
    dynamic_array<instruction> instructions = compiler.compile(expression);

    for (int i = 0; i < length(instructions); i++)
    {
        write_line(instruction_to_string(instructions[i]));
    }

    return 0;
}
