#include "splashkit.h"
#include <string>
#include <vector>
#include <memory>

/*
E = E + T
E = E - T
E = T

T = F
T = T * F
T = T / F

F = INT
F = ( E )
*/

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
