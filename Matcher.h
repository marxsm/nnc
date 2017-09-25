#pragma once

#include <deque>
#include <string>

#include "Logger.h"
#include "StandardType.h"

using namespace std;

using namespace Logger;

#define CT_UNKNOWN	-1
#define CT_SKIP		0
#define CT_ALPHANUM	1
#define CT_SQUARE	2
#define CT_OPERATOR 3
#define CT_ALPHA	4
#define CT_NUM		5

#define Minst Matcher::Instance()


int getCharTypeAdvanced(char ch);

class Matcher {
private:
	deque<char*> * tokens;
public:
	void SetTokens(deque<char*> * newTokens);
	deque<char*> * GetTokens();

	static Matcher * instance;
	static Matcher * Instance();

	bool currentTokenIsName();
	bool currentTokenIsNumber();
	bool currentTokenIsOperator();
	bool Empty();

	void NextToken();
	void PrevToken(char* token);
	bool Equal(char* st);
	bool Match(char* st);
	void Matching(char* word);
	char* GetName(bool required);
	char* GetOperator(bool required);
	BASE64 * GetNumberConstant(bool required);
	char* GetStringConstant(bool required);

};