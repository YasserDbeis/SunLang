#include "../include/func_def_table.h"

void FuncDefTable::add_entry(std::string id, int global_count, std::vector<std::pair<Type, std::string>> params, Type return_type, std::list<InstNode> inst_list)
{
    assert_func_not_exists(id);

    FuncDef func_def;
    func_def.max_global_count = global_count;
    func_def.params = params;
    func_def.return_type = return_type;
    func_def.instruction_list = inst_list;

    table[id] = func_def;
}

std::list<InstNode> FuncDefTable::get_function(std::string id)
{
    assert_func_exists(id);
    return table[id].instruction_list;
}

int FuncDefTable::get_global_count(std::string id)
{
    assert_func_exists(id);
    return table[id].max_global_count;
}

std::vector<std::pair<Type, std::string>> FuncDefTable::get_params(std::string id)
{
    assert_func_exists(id);
    return table[id].params;
}

Type FuncDefTable::get_return_type(std::string id)
{
    assert_func_exists(id);
    return table[id].return_type;
}

void FuncDefTable::assert_func_exists(std::string id)
{
    if (table.count(id) == 0)
    {
        ErrorHandler::error(ErrorPhase::EXECUTION, ErrorType::RUNTIME_EXCEPTION, "Table entry '" + id + "' not found", -1, FUNC_NOT_DEF);
    }
}

void FuncDefTable::assert_func_not_exists(std::string id)
{
    if (table.count(id) != 0)
    {
        ErrorHandler::error(ErrorPhase::EXECUTION, ErrorType::RUNTIME_EXCEPTION, "Table entry '" + id + "' already defined", -1, FUNC_ALREADY_DEF);
    }
}