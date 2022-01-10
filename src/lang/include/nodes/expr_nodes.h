#pragma once

#include "expr_node.h"
#include <string>
#include <vector>

class LoadNode : public ExprNode
{
public:
    Value evaluate();
    LoadNode();
    LoadNode(ExprType type, Type var_type, std::string name, int global_count, bool is_constant);
    LoadNode(ExprType type, Value value, int global_count, bool is_constant);

private:
    std::string name;
    Type var_type;
    int global_count;
    Value value;
    bool is_constant;
};

class ParenNode : public ExprNode
{
public:
    bool is_left;

    ParenNode();
    ParenNode(ExprType type, bool is_left);
};

enum class OperatorType
{
    PLUS,
    MINUS,
    MULT,
    DIV,
    GT,
    LT,
    GEQ,
    LEQ,
    IS,
    AND,
    OR,
    NOT,
    XOR,
    XCL,
    NEQ,
};

class OperatorNode : public ExprNode
{
public:
    OperatorType operator_type;

    OperatorNode();
    OperatorNode(ExprType type, OperatorType operator_type);
};