#include "Lexer.h"
#include <cassert>

Lexer::Lexer(std::string input): input{input}
{
	tokens = lex();
#ifdef _DEBUG
	for (auto token : tokens)
	{
		std::cout << " " << token.value;
	}
	std::cout << '\n';
#endif // _DEBUG
}

Token Lexer::consume()
{
	assert(tokens.size() > 0);
	Token token = tokens[0];
	tokens.erase(tokens.begin());
	return token;
}

const Token& Lexer::peek()
{
	assert(tokens.size() > 0);
	return *tokens.cbegin();
}

bool Lexer::hasNext()
{
	return tokens.size() > 0;
}

std::vector<Token> Lexer::lex()
{
	std::vector<Token> tokens;
	size_t pos = 0;
	while (pos < input.length())
	{
		size_t tokenStartPos = pos;
		char nextChar = input[pos];
		if (nextChar == ' ')
		{
			pos++;
		}
		else if (nextChar == '(' || nextChar == ')')
		{
			pos++;
			tokens.push_back(Token(TokenType::PARENTHESIS, std::string{nextChar}, pos));
		}
		// positive and negtive sign is solved by parser not lexer
		else if (nextChar == '+' || nextChar == '-')
		{
			pos++;
			tokens.push_back(Token(TokenType::ADDORSUB, std::string{ nextChar }, pos));
		}
		else if (nextChar == '*' || nextChar == '/')
		{
			pos++;
			tokens.push_back(Token(TokenType::MUTLIORDIV, std::string { nextChar }, pos));
		}
		else if (isdigit(nextChar) || nextChar == '.')
		{
			std::string number;
			bool hasDot = false;
			while (pos < input.length() &&( input[pos] == '.' && !hasDot || isdigit(input[pos])))
			{
				if (input[pos] == '.')
				{
					hasDot = true;
				}
				number.push_back(input[pos]);
				pos++;
			}
			tokens.push_back(Token(TokenType::NUMBER, number, pos));
		}
		else if (isalpha(nextChar))
		{
			std::string keyword;
			while (pos < input.length() && isalnum(input[pos]))
			{
				keyword.push_back(nextChar);
				pos++;
			}
			tokens.push_back(Token(TokenType::KEYWORD, keyword, pos));
		}
	}
	return tokens;
}
