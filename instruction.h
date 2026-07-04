#pragma once

#include "splashkit.h"
#include <string>

class instruction
{
public:
    string debug_string{""};
};

class pushint : public instruction
{
public:
    int value;

    pushint(int value)
    {
        this->value = value;
        this->debug_string = "PushInt(value=" + to_string(value) + ")";
    }
};

class add_instruction : public instruction
{
public:
    add_instruction()
    {
        this->debug_string = "Add";
    }
};

class sub_instruction : public instruction
{
public:
    sub_instruction()
    {
        this->debug_string = "Sub";
    }
};

class mul_instruction : public instruction
{
public:
    mul_instruction()
    {
        this->debug_string = "Mul";
    }
};

class div_instruction : public instruction
{
public:
    div_instruction()
    {
        this->debug_string = "Div";
    }
};

string instruction_to_string(instruction instruction);