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


biopNode::biopNode(std::string sym):symbol(sym)
{
}



std::string biopNode::getSymbol()
{
	return symbol;
}

Node* biopNode::getLeftChild()
{
	return leftChild;
}

Node* biopNode::getRightChild()
{
	return rightChild;
}
