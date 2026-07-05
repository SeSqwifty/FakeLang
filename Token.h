#pragma once

#include "splashkit.h"
#include "splashkit-arrays.h"
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

inline string token_type_to_string(TokenType type)
{
    if (type == NUMBER)
    {
        return "NUMBER";
    }
    else if (type == PLUS)
    {
        return "PLUS";
    }
    else if (type == MINUS)
    {
        return "MINUS";
    }
    else if (type == STAR)
    {
        return "STAR";
    }
    else if (type == SLASH)
    {
        return "SLASH";
    }
    else if (type == OPEN_BRACKET)
    {
        return "OPEN_BRACKET";
    }
    else if (type == CLOSE_BRACKET)
    {
        return "CLOSE_BRACKET";
    }
    else if (type == END_OF_FILE)
    {
        return "END_OF_FILE";
    }

    return "UNKNOWN";
}

inline string token_to_string(Token token)
{
    return "Token(type=" + token_type_to_string(token.type) + ", literal=" + token.value + ")";
}

inline string tokens_to_string(dynamic_array<Token> tokens)
{
    string result = "[";

    for (int i = 0; i < length(tokens); i++)
    {
        result += token_to_string(tokens[i]);

        if (i < length(tokens) - 1)
        {
            result += ", ";
        }
    }

    result += "]";
    return result;
}