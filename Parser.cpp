#include "Parser.h"

Node& parse(std::vector<Token>::iterator begin, std::vector<Token>::iterator end, double precedence)
{
    Token token = *begin;
    Node leftNode = nud(token);
    for (auto iter = begin + 1; iter < end; iter++)
    {
        Token next = *iter;
        if (precedence < getTokenPredence(next.type).first)
        {
            biopNode Op(next.value);
            Op.setLeftChild(&leftNode);
            Node rightNode = parse(iter + 1, end, getTokenPredence(next.type).second);
            Op.setRightChild(&rightNode);
            leftNode = Op;
        }
        else
        {
            return leftNode;
        }
    }
}

std::pair<double,double> getTokenPredence(TokenType tokenType)
{
    switch (tokenType)
    {
    case TokenType::NUMBER:
        return { 0.0, 0.0 };
        break;
    case TokenType::SUFFIXINCRORDECR:
        return { 15,15 };
        break;
    case TokenType::UNARYPLUSORMINUS:
        return { 14,14 };
        break;
    case TokenType::PREFIXINCRORDECR:
        return { 14,14 };
        break;
    case TokenType::ADDORSUB:
        return { 12,12.5 };
        break;
    case TokenType::MUTLIORDIV:
        return { 13,13.5 };
        break;
    case TokenType::BITWISESHIFT:
        break;
    case TokenType::BITWISEAND:
        break;
    case TokenType::BITWISEXOR:
        break;
    case TokenType::BITWISEOR:
        break;
    case TokenType::LOGICALAND:
        break;
    case TokenType::LOGICALOR:
        break;
    case TokenType::EQUALITYOP:
        break;
    case TokenType::RELATIONALOP:
        break;
    case TokenType::KEYWORD:
        break;
    default:
        return { 0.0, 0.0 };
        break;
    }
    return { 0.0, 0.0 };
}

Node nud(Token& token)
{
    if (token.type == TokenType::NUMBER)
    {
        return numericNode(token.value);
    }
    else if (token.type == TokenType::ADDORSUB || token.type == TokenType::MUTLIORDIV)
    {
        return biopNode(token.value);
    }
}
