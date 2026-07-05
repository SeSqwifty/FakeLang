#include "Lexer.h"

char Lexer::advance()
{
    char return_character = source[current_position];
    current_position++;
    return return_character;
}

// top level function for taking the name of all the tokens
dynamic_array<Token> Lexer::scan_tokens(string input)
{
    source = input;
    current_position = 0;

    while (!IsAtEnd())
    {
        ScanNextToken();
    }

    Token end_token;
    end_token.type = END_OF_FILE;
    end_token.value = "";

    add(tokens, end_token);

    return tokens;
}

bool Lexer::IsAtEnd()
{
    return current_position >= source.length();
}

char Lexer::peek()
{
    if (IsAtEnd())
    {
        return 0;
    }

    return source[current_position];
}

void Lexer::scan_number()
{
    int starting_position_of_number = current_position - 1;

    while (!IsAtEnd() and isdigit(peek()))
    {
        advance();
    }

    Token number_token;
    number_token.type = NUMBER;
    number_token.value = source.substr(
        starting_position_of_number,
        current_position - starting_position_of_number);

    add(tokens, number_token);
}

void Lexer::ScanNextToken()
{
    char current_char = advance();
    Token new_token;

    if (current_char == '(')
    {
        new_token.type = OPEN_BRACKET;
        add(tokens, new_token);
    }
    else if (current_char == ')')
    {
        new_token.type = CLOSE_BRACKET;
        add(tokens, new_token);
    }
    else if (current_char == '+')
    {
        new_token.type = PLUS;
        add(tokens, new_token);
    }
    else if (current_char == '-')
    {
        new_token.type = MINUS;
        add(tokens, new_token);
    }
    else if (current_char == '*')
    {
        new_token.type = STAR;
        add(tokens, new_token);
    }
    else if (current_char == '/')
    {
        new_token.type = SLASH;
        add(tokens, new_token);
    }
    else if (isdigit(current_char))
    {
        scan_number();
    }
    else if (current_char == ' ' or current_char == '\n' or current_char == '\t' or current_char == '\r')
    {
        // ignore
    }
    else
    {
        throw("unexpected token");
    }
}