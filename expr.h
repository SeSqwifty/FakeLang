#pragma once

#include "Token.h"
#include <string>
#include <memory>

enum ExprType
{
    EXPR_UNKNOWN,
    EXPR_NUMBER_LITERAL,
    EXPR_BINARY
};

struct Expr
{
    virtual ~Expr() = default;
    string debug_string{""};
    ExprType expr_type{EXPR_UNKNOWN};
    int number_value{0};
    // understand this deeper
    std::shared_ptr<Expr> left_expr;
    std::shared_ptr<Expr> right_expr;
    Token operator_token;
};

struct NumberLiteral : Expr
{
    int value;

    NumberLiteral(int value)
    {
        this->value = value;
        this->number_value = value;
        this->expr_type = EXPR_NUMBER_LITERAL;
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

        this->expr_type = EXPR_BINARY;
        
        this->left_expr = std::make_shared<Expr>(left);
        this->right_expr = std::make_shared<Expr>(right);
        this->operator_token = operator_token;
        
        this->debug_string =
            "Binary(left=" + left.debug_string +
            ", operator=" + token_type_to_string(operator_token.type) +
            ", right=" + right.debug_string + ")";
    }
};

string expr_to_string(Expr expression);
string number_literal_to_string(NumberLiteral expression);
string binary_to_string(Binary expression);