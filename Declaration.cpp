#include "Declaration.h"

#include "Expression.h"

Declaration::Declaration(char * var1, char * var2, char * var3)
{
	rawName = var2;
	type = var1;
	name = var3;

	DecType = 'P';
}

Declaration::Declaration(char * var1, char * var2, Expression * var3)
{
	name = var2;
	type = var1;
	value = var3;

	if (!value)
		value = new Expression(new BASE64(0));

	DecType = 'V';
}

Declaration::Declaration(char * var1, char * var2, deque<Declaration*>* var3, deque<Element*>* var4)
{
	name = var2;
	type = var1;
	params = var3;
	elements = var4;

	DecType = 'F';
}

Declaration::Declaration()
{
}


Declaration::~Declaration()
{
}
