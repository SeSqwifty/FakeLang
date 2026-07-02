#pragma once

#include "Token.h"
#include <string>

struct Expr
{
    string debug_string{""};
    virtual ~Expr() = default;
};

struct NumberLiteral : Expr
{
    int value;

    NumberLiteral(int value)
    {
        this->value = value;
        this->debug_string = "NumberLiteral(value=" + to_string(value) + ")";
    }
};

struct Binary : Expr
{
    Expr left;
    Token operator_token;
    Expr right;

    Binary(Expr left, Token operator_token, Expr right)
    {
        this->left = left;
        this->operator_token = operator_token;
        this->right = right;

        this->debug_string =
            "Binary(left=" + left.debug_string +
            ", operator=" + token_type_to_string(operator_token.type) +
            ", right=" + right.debug_string + ")";
    }
};

string expr_to_string(Expr expression);
string number_literal_to_string(NumberLiteral expression);
string binary_to_string(Binary expression);