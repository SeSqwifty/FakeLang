#pragma once

#include "Token.h"
#include <memory>

struct Expr
{
    virtual ~Expr() = default;
};

struct NumberLiteral : Expr
{
    int value;

    NumberLiteral(int value)
    {
        this->value = value;
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
    }
};