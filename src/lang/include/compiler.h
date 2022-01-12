#pragma once

#include "nodes/inst_node.h"
#include "parser.h"
#include <list>
#include <string>

class Compiler
{
public:
    Compiler();
    Compiler(std::string input);

    std::vector<InstNode *> get_global_instructions();

private:
    int global_count;
    std::list<InstNode> global_nodes;
    Parser parser;
};