#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Token.h"
#include "Node.h"
#include "Lexer.h"

class Parser
{
};

std::pair<double, double> getTokenPredence(TokenType tokenType);

Node* parse(Lexer& lex, double precedure);