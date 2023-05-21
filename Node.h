#pragma once
#include <string>
#include <sstream>
#include <string>

class Node
{
public:
	virtual std::string display();
	virtual ~Node() {};
	virtual Node* getLeftChild() { return leftChild; };
	virtual Node* getRightChild() { return rightChild; };
	virtual void setLeftChild(Node* node) { leftChild = node; };
	virtual void setRightChild(Node* node) { rightChild = node; };
private:
	Node* leftChild;
	Node* rightChild;
};

class numericNode : public Node
{
public:
	numericNode(std::string content);
	double getValue();
	virtual std::string display();
private:
	double value;
};

class biopNode : public Node
{
public:
	biopNode(std::string sym);
	std::string getSymbol();
	virtual std::string display();
private:
	std::string symbol;
};