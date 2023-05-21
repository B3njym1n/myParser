#include "Node.h"

numericNode::numericNode(std::string content)
{
	std::stringstream ss(content);
	ss >> value;
}

double numericNode::getValue()
{
	return value;
}

std::string numericNode::display()
{
	
	return std::to_string(value);
}


biopNode::biopNode(std::string sym):symbol(sym)
{
}



std::string biopNode::getSymbol()
{
	return symbol;
}

std::string biopNode::display()
{
	return symbol;
}

std::string Node::display()
{
	return std::string();
}
