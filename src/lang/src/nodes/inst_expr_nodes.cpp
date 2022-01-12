#include "../../include/nodes/inst_expr_nodes.h"
#include "../../include/state_mgmt.h"
#include "../../include/func_def_table.h"
#include "../../include/executioner.h"

/* ----------------------------------------------
FuncCallNode Implementation
---------------------------------------------- */

FuncCallNode::FuncCallNode()
{
}

FuncCallNode::FuncCallNode(std::string func_id, std::vector<Expression> args)
{
    this->func_id = func_id;
    this->args = args;
}

FuncCallNode::FuncCallNode(ExprType type, std::string func_id, std::vector<Expression> args)
{
    this->func_id = func_id;
    this->type = type;
    this->func_id = func_id;
    this->args = args;
}

/* Override */
void FuncCallNode::execute()
{
    StateMgmt::create_new_stack_frame(func_id);

    for (auto argument_expr : args)
    {
        argument_expr.evaluate();
        StateMgmt::arg_queue.push(argument_expr.value);
    }

    std::vector<InstNode *> func_instructions = FuncDefTable::get_function(func_id);

    Executioner::execute_instructions(func_instructions);

    value = StateMgmt::load_return_val_stack_trace();

    StateMgmt::delete_curr_stack_frame();
}

void FuncCallNode::evaluate()
{
    execute();
}

void FuncCallNode::inst_print(int num_tabs)
{
    for (int i = 0; i < num_tabs; i++)
    {
        std::cout << "\t";
    }

    std::cout << "[Func Call] Offset: " << this->get_offset() << ", Func Name: " << func_id << std::endl;
    if (args.empty() == true)
    {
        for (int i = 0; i < num_tabs; i++)
        {
            std::cout << "\t";
        }

        std::cout << "\tFunc Arguments: none" << std::endl;
    }
    else
    {
        int i = 0;
        for (auto arg : args)
        {
            arg.print_expr(num_tabs + 1);
            i++;
        }
    }
}

void FuncCallNode::expr_print(int num_tabs)
{
    inst_print(num_tabs);
}