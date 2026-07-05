#include "expr.h"

string expr_to_string(Expr expression)
{
    return expression.debug_string;
}

string number_literal_to_string(NumberLiteral expression)
{
    return "NumberLiteral(value=" + to_string(expression.value) + ")";
}

string binary_to_string(Binary expression)
{
    return "Binary(left=" + expr_to_string(expression.left) +
           ", operator=" + token_type_to_string(expression.operator_token.type) +
           ", right=" + expr_to_string(expression.right) + ")";
}