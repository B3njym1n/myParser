#include <iostream>
#include <string>
#include <vector>
#include "Lexer.h"
#include "Parser.h"

int main()
{
    Lexer lexer("2.3+3.1*1.5");

    while (lexer.hasNext())
    {
        Token tk = lexer.consume();
        std::cout << tk.value << '\n';
    }
    
    return 0;
}