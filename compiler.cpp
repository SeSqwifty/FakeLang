#include "Lexer.h"
#include "instruction.h"
#include "expr.h"

class complier
{
public:
    dynamic_array<instruction> compile(Expr expr)
    {
        dynamic_array<instruction> instructions;
        emit(expr, instructions);
        return instructions;
    }

private:
    void emit(Expr expr, dynamic_array<instruction> &instructions)
    {
        if (expr.expr_type == EXPR_NUMBER_LITERAL)
        {
            pushint new_instruction(expr.number_value);
            add(instructions, new_instruction);
        }
        else if (expr.expr_type == EXPR_BINARY)
        {
            emit(*expr.left_expr, instructions);
            emit(*expr.right_expr, instructions);

            if (expr.operator_token.type == PLUS)
            {
                add(instructions, add_instruction());
            }
            else if (expr.operator_token.type == MINUS)
            {
                add(instructions, sub_instruction());
            }
            else if (expr.operator_token.type == STAR)
            {
                add(instructions, mul_instruction());
            }
            else if (expr.operator_token.type == SLASH)
            {
                add(instructions, div_instruction());
            }
            else if (expr.expr_type == EXPR_BINARY)
            {
                emit(*expr.left_expr, instructions);
                emit(*expr.right_expr, instructions);

                add(instructions, instruction_for_operator(expr.operator_token));
            }
        }
    }

    instruction instruction_for_operator(Token operator_token)
    {
        if (operator_token.type == PLUS)
        {
            return add_instruction();
        }
        else if (operator_token.type == MINUS)
        {
            return sub_instruction();
        }
        else if (operator_token.type == STAR)
        {
            return mul_instruction();
        }
        else if (operator_token.type == SLASH)
        {
            return div_instruction();
        }

        throw("Invalid operator");
    }
};