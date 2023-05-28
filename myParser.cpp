#include <iostream>
#include <string>
#include "Lexer.h"
#include "Parser.h"

void display(Node* root, size_t m, size_t n)
{
    for (int i = 0; i < m; ++i)
    {
        std::cout << " ";
    }
    std::cout << "\u2514";
    for (int i = 0; i < n; ++i)
    {
        std::cout << "\u2500";
    }
    std::cout << root->display() << '\n';
    if (root->getLeftChild() != nullptr)
    {
        display(root->getLeftChild(), m + n + 1, n);
    }
    if (root->getRightChild() != nullptr)
    {
        display(root->getRightChild(), m + n + 1, n);
    }
}

int main()
{
    Lexer lexer("2.3*(3.1+1.5)");

    Node* root= parse(lexer, 0.0);
#ifdef _DEBUG
    display(root, 0, 3);
#endif // DEBUG

    return 0;
}