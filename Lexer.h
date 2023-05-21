#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Token.h"

class Token;

class Lexer
{
private:
	std::string input;
	std::vector<Token> tokens;
	std::vector<Token> lex();
public:
	Lexer(std::string input);
	Token consume();
	const Token& peek();
	bool hasNext();
};

