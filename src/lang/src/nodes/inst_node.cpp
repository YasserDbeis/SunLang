#include "../../include/nodes/inst_node.h"

void InstNode::set_offset(int new_offset)
{
    offset = new_offset;
}

int InstNode::get_offset()
{
    return offset;
}

void InstNode::execute()
{
    /* Does nothing unless overridden by child class */
}

void InstNode::inst_print(int num_tabs)
{
    std::cout << "Default called\n";
}

int InstNode::get_target()
{
    return offset;
}