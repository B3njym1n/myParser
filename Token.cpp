#include "Token.h"

Token::Token(TokenType type, std::string value, size_t pos): type(type), value(value), startPos(pos)
{
}

std::ostream& operator<<(std::ostream& os, const Token& token)
{
	os << "@pos: " << token.startPos << " Type: " << TokenTypeToString(token.type) << " Value: " << token.value << "\n";
	return os;
}

constexpr const char* TokenTypeToString(TokenType type)
{
	switch (type)
	{
	case TokenType::NUMBER:
		return "number";
		break;
	case TokenType::SUFFIXINCRORDECR:
		return "suffix increase decrease";
		break;
	case TokenType::UNARYPLUSORMINUS:
		return "unary plus minus";
		break;
	case TokenType::PREFIXINCRORDECR:
		return "prefix increase decrease";
		break;
	case TokenType::ADDORSUB:
		return "addition or subtraction";
		break;
	case TokenType::MUTLIORDIV:
		return "multiply or division";
		break;
	case TokenType::BITWISESHIFT:
		return "bitwise shift";
		break;
	case TokenType::BITWISEAND:
		return "bitwise and";
		break;
	case TokenType::BITWISEXOR:
		return "bitwise xor";
		break;
	case TokenType::BITWISEOR:
		return "bitwise or";
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
		return "keyword";
		break;
	default:
		break;
	}
	return nullptr;
}
;