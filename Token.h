#pragma once

#include "splashkit.h"
#include <string>

enum TokenType
{
    NUMBER,
    PLUS,
    MINUS,
    STAR,
    SLASH,
    OPEN_BRACKET,
    CLOSE_BRACKET,
    END_OF_FILE

};

struct Token
{
    string value{""};
    TokenType type;
};