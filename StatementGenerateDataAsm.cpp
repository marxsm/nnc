#include "Statement.h"

#include "Expression.h"


void Statement::GenerateDataAsm()
{
	switch (DecType)
	{
	case 'R': {

		exp->GenerateDataAsm();
	}break;
	default:
		break;
	}
}