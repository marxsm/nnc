#include "Statement.h"



Statement::Statement()
{
}


Statement::~Statement()
{
}


Statement::Statement(Expression * var1)
{
	exp = var1;

	DecType = 'R';
}

Statement::Statement(Expression * var1, deque<Element*>* var2)
{
	exp = var1;
	elements = var2;

	DecType = 'I';
}