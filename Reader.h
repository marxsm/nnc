#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <deque>
#include <string.h>

#include "Logger.h"

using namespace std;

using namespace Logger;

#define CT_UNKNOWN	-1
#define CT_SKIP		0
#define CT_ALPHANUM	1
#define CT_SQUARE	2
#define CT_OPERATOR 3
#define CT_ALPHA	4
#define CT_NUM		5


int getCharType(char ch);


class Reader {
private:
	char* rawData;

	char* readFile(char* srcFile);

	char* getToken();
public:
	Reader(char* srcFile);

	deque<char*> * getTokens();
};
