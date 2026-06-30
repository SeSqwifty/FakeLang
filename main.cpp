#include "splashkit.h"
#include "splashkit-arrays.h"
#include <string>

#include "token.h"
#include "Lexer.h"

int main()
{
    write("what do you want to know the tokens of ");
    string source = read_line();

    Lexer lexer;
    dynamic_array<Token> tokens = lexer.scan_tokens(source);

    write_line(tokens_to_string(tokens));

    return 0;
}