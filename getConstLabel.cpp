#include "Utils.h"

#pragma warning(disable: 4996)

BASE64 Utils::ConstCounting = 0;

char* Utils::GetConstLabel()
{
	ConstCounting++;

	string s = to_string(ConstCounting);

	char* result = new char[s.length() + 3];

	strcpy(result, "_C");
	strcat(result, s.c_str());

	return result;
}