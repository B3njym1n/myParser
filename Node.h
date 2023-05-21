#pragma once
#include <string>
#include <sstream>

class Node
{
public:
	virtual ~Node() {};
};

class numericNode : public Node
{
public:
	numericNode(std::string content);
	double getValue();
private:
	double value;
};

class biopNode : public Node
{
public:
	biopNode(std::string sym);
	std::string getSymbol();
	Node* getLeftChild();
	Node* getRightChild();
	void setLeftChild(Node* node) { leftChild = node; };
	void setRightChild(Node* node) { rightChild = node; };
private:
	Node* leftChild;
	Node* rightChild;
	std::string symbol;
};