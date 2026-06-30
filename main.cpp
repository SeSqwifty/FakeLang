#include "splashkit.h"
#include "splashkit-arrays.h"
#include <string>

#include "token.h"
#include "Lexer.h"

int main()
{
    string source = "6 + 4";

    Lexer lexer;
    dynamic_array<Token> tokens = lexer.scan_tokens(source);

    write_line(tokens_to_string(tokens));

    return 0;
}