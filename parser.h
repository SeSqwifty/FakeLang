#pragma once

#include "lexer.h"
#include "expr.h"
#include <initializer_list>

class parser
{
    dynamic_array<Token> tokens;
    int currentposition{0};

public:
    Expr parse()
    {
        Expr expression = ParseExpression();
        consume(END_OF_FILE, "Expected EOF");
        return expression;
    }

    parser(dynamic_array<Token> input_tokens) : tokens(input_tokens) {}

private:
    Expr ParseExpression()
    {
        Expr workingExpression = ParseTerm();
        while (match({PLUS, MINUS}))
        {
            Token operator_token = previous();
            Expr parsedTerm = ParseTerm();
            // left unfolding
            workingExpression = Binary(workingExpression, operator_token, parsedTerm);
        }
        return workingExpression;
    }

    Expr ParseTerm()
    {
        Expr WorkingExpression = ParseFactor();
        while (match({STAR, SLASH}))
        {
            Token operator_token = previous();
            Expr parsedFactor = ParseFactor();
            // left unfolding
            WorkingExpression = Binary(WorkingExpression, operator_token, parsedFactor);
        }
        return WorkingExpression;
    }
    Expr ParseFactor()
    {
        // first case is if its an integer
        if (match({NUMBER}))
        {
            return NumberLiteral(to_integer(previous().value));
        }
        // case 2 is an expression
        if (match({OPEN_BRACKET}))
        {
            Expr ParsedExpression = ParseExpression();
            Token expression = consume(CLOSE_BRACKET, "FAILED TO PARSE A FACTOR EXPECTED AN EXPRESSION AN BRACKET");
            return ParsedExpression; // he had expression here not parsedexpression double check later
        }
        throw("unable to parse a factor expected a number or token bracket");
    }

    Token peek()
    {
        return tokens[currentposition];
    }

    bool IsAtEnd()
    {
        return peek().type == END_OF_FILE;
    }

    Token previous()
    {
        return tokens[currentposition - 1];
    }

    Token advance()
    {
        if (!IsAtEnd())
        {
            currentposition += 1;
        }

        return previous();
    }

    bool check(TokenType type)
    {
        if (IsAtEnd())
        {
            return type == END_OF_FILE;
        }

        return peek().type == type;
    }

    Token consume(TokenType type, string message)
    {
        if (check(type))
        {
            return advance();
        }
        throw(message);
    }

    bool match(std::initializer_list<TokenType> types)
    {
        for (TokenType type : types)
        {
            if (check(type))
            {
                advance();
                return true;
            }
        }

        return false;
    }
};
