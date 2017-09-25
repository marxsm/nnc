#pragma once

#include <deque>
#include "Element.h"
#include "Matcher.h"
#include "Writter.h"

class Expression;
class Declaration;

class Statement : public Element
{
public:
	Statement();
	~Statement();

	Expression * exp;

	deque<Element*> * elements;

	char DecType;

	Statement(Expression * var1);
	Statement(Expression * var1, deque<Element*> * var2);

	static Statement * getStatement(deque<Declaration*> * params);

	void GenerateAsm(char * decName);

	void GenerateDataAsm();
};

