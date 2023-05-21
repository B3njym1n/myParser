#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Token.h"
#include "Node.h"

class Parser
{
};

Node& parse(std::vector<Token>::iterator begin, std::vector<Token>::iterator end, double precedence);

std::pair<double, double> getTokenPredence(TokenType tokenType);

Node nud(Token& token);