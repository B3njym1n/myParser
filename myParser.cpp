#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include "Lexer.h"
#include "Parser.h"

int main()
{
    Lexer lexer("2.3*3.1+1.5");

    Node* root= parse(lexer, 0.0);

    Node* tmp = root;
    std::stack<Node*> stack;
    stack.push(tmp);
    while (!stack.empty())
    {
        Node* node = stack.top();
        stack.pop();
        std::cout << node->display() << std::endl;
        if (node->getRightChild() != nullptr)
        {
            stack.push(node->getRightChild());
        }
        if (node->getLeftChild() != nullptr)
        {
            stack.push(node->getLeftChild());
        }
    }

    return 0;
}