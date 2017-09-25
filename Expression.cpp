#include "Expression.h"



Expression::Expression()
{
}


Expression::~Expression()
{
}


Expression::Expression(char * var1)
{
	name = var1;

	DecType = 'N';
}

Expression::Expression(char * var1, char * var2)
{
	name = var1;

	DecType = 'O';
}

Expression::Expression(char * var1, int i)
{
	name = Utils::GetConstLabel();
	str = var1;

	DecType = 'S';
}

Expression::Expression(BASE64 * var1)
{
	num = var1;

	DecType = 'D';
}

Expression::Expression(char * var1, deque<Expression*>* var2)
{
	name = var1;
	exps = var2;

	DecType = 'F';
}

Expression::Expression(deque<Expression*>* var1)
{
	exps = var1;

	DecType = 'E';
}

Expression::Expression(char * var1, Expression * var2)
{
	name = var1;
	exp = var2;

	DecType = 'A';
}
