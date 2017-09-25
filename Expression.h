#pragma once


#include "Element.h"
#include "Matcher.h"
#include "Writter.h"
#include "Utils.h"

using namespace std;

class Declaration;

class Expression : public Element
{
public:
	Expression();
	~Expression();

	char * name;
	char * str;
	BASE64 * num;
	Expression * exp;
	deque<Expression*> * exps;

	char DecType;

	// Name expression
	Expression(char * var1);
	// Oper expression
	Expression(char * var1, char * var2);
	// String expression
	Expression(char * var1, int i);
	// Number expression
	Expression(BASE64 * var1);
	// Function call expression
	Expression(char * var1, deque<Expression*> * var2);
	// Bare expression
	Expression(deque<Expression*> * var1);
	// Assignment
	Expression(char * var1, Expression * var2);

	static Expression * getExpression(bool isCommand, deque<Declaration*> * params);

	void GenerateAsm(char * decName);

	void GenerateDataAsm();
};