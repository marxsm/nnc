#include "Command.h"



Command::Command()
{
}


Command::~Command()
{
}

Command::Command(char * var1, Expression * var2)
{
	name = var1;
	exp = var2;
	DecType = 'A';
}

Command::Command(char * var1, deque<Expression*>* var2)
{
	name = var1;
	exps = var2;
	DecType = 'R';
}
