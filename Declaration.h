#pragma once

#include "Element.h"
#include "Matcher.h"
#include "Writter.h"

class Expression;

class Declaration
{
public:
	Declaration();
	~Declaration();

	char * name;
	char * rawName;
	char * type;
	Expression * value;
	deque<Declaration*> * params;
	deque<Element*> * elements;

	char DecType;

	Declaration(char * var1, char * var2);

	Declaration(char * var1, char * var2, char * var3);

	Declaration(char * var1, char * var2, Expression * var3);

	Declaration(char * var1, char * var2, deque<Declaration*> * var3, deque<Element*> * var4);

	static Declaration * getDeclaration();

	static Declaration * getParameter(char * parentName);

	void GenerateAsm(BASE64 index);

	void GenerateDataAsm();
};