#include <iostream>
#include <string>
#include "Lexer.h"
#include "Parser.h"

void display(Node* root, size_t n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << " ";
    }
    std::cout << root->display() << '\n';
    if (root->getLeftChild() != nullptr)
    {
        display(root->getLeftChild(), n*2);
    }
    if (root->getRightChild() != nullptr)
    {
        display(root->getRightChild(), n*2);
    }
}

int main()
{
    Lexer lexer("2.3*3.1+1.5");

    Node* root= parse(lexer, 0.0);

    display(root, 3);

    return 0;
}