#pragma once

#include "splashkit.h"
#include "splashkit-arrays.h"
#include <string>
#include <cctype>

#include "token.h"

struct Lexer
{
    string source;
    int current_position{0};
    dynamic_array<Token> tokens;

    char advance();
    dynamic_array<Token> scan_tokens(string input);
    bool IsAtEnd();
    char peek();
    void scan_number();
    void ScanNextToken();
};