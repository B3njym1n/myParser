#pragma once
#include<string>
#include<iostream>
#include "TokenType.hpp"

class Token
{
public:
	Token(TokenType type, std::string value, size_t pos);
	TokenType type;
	std::string value;
	size_t startPos;
};

std::ostream& operator<<(std::ostream& os, const Token& token);

constexpr const char* TokenTypeToString(TokenType type);