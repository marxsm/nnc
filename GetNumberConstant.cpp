#include "Matcher.h"

BASE64 * Matcher::GetNumberConstant(bool required)
{
	BASE64 * result = nullptr;

	if (!Empty() && currentTokenIsNumber()) {

		result = new BASE64;

		*result = stoi(tokens->front(), nullptr);

		NextToken();
	}
	else
		if (required)
			Error("A number constant is required");

	return result;
}