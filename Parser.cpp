#include "Parser.h"

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

Node* parenthesisParselet(Lexer& lex)
{
    Node* inner = parse(lex, 0);
    lex.consume();
    return inner;
}

Node* nud(Token& token, Lexer& lex)
{
    switch (token.type)
    {
    case TokenType::PARENTHESIS:
        return parenthesisParselet(lex);
        break;
    case TokenType::NUMBER:
        return new numericNode(token.value);
        break;
    default:
        break;
    }
}

Node* parse(Lexer& lex, double precedure)
{
    Token token = lex.consume();
    //Node* leftNode = new numericNode(token.value);
    Node* leftNode = nud(token, lex);
    while (lex.hasNext())
    {
        Token next = lex.peek();
        if (precedure < getTokenPredence(next.type).first)
        {
            Node* opNode = new biopNode(next.value);
            ((biopNode*) opNode)->setLeftChild(leftNode);
            lex.consume();
            Node* right = parse(lex, getTokenPredence(next.type).second);
            ((biopNode*)opNode)->setRightChild(right);
            leftNode = opNode;
        }
        else
        {
            break;
        }
    }
    return leftNode;
}