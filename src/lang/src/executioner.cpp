#include "../include/executioner.h"

inline const std::string MAIN = "main";

Executioner::Executioner() : compiler("")
{
}

Executioner::Executioner(std::string input) : compiler(input)
{
    // std::cout << "INPUT: " << input << std::endl;
}

void Executioner::execute_program()
{
    FuncDefTable::function_exists(MAIN);

    execute_instructions(compiler.get_global_instructions());

    // std::string output = OutputHandler::get_code_output();

    // OutputHandler::reset_code_output();
    // StateMgmt::reset_state();
    // this->set_prog_exit_state(false);
    // FuncDefTable::reset_func_table();
}

void Executioner::execute_instructions(std::vector<InstNode *> instructions)
{
    if (instructions.empty() == true)
    {
        return;
    }

    int i = 0;

    int num_instructions = instructions.size();

    while (i < num_instructions)
    {
        InstNode *curr_inst = instructions[i];

        curr_inst->execute();

        if (curr_inst->inst_type == InstType::RETURN)
        {
            break;
        }

        i += curr_inst->get_offset();
    }
}

void Executioner::print(std::string info)
{
    std::cout << info << std::endl;
}