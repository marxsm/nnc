#include "Reader.h"

int getCharTypeAdvanced(char ch)
{
	// Alphanum
	if (ch >= '0' && ch <= '9')
		return CT_NUM;
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch == '_'))
		return CT_ALPHA;
	// Square
	char squares[] = "()[]{},;";
	for (char& c : squares)
		if (c == ch)
			return CT_SQUARE;
	// Operator
	char operators[] = "~!@#$%^&*/*-+\\|<>?=";
	for (char& c : operators)
		if (c == ch)
			return CT_OPERATOR;
	// Skip
	char skips[] = " \n\t\v\r\f";
	for (char& c : skips)
		if (c == ch)
			return CT_SKIP;
	// Unknown and space
	return CT_UNKNOWN;
}