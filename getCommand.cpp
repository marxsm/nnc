#include "Command.h"


Command * Command::getCommand()
{
	char * var1 = Minst->GetName(true);

	if (Minst->Match("=")) {

		Expression * exp = Expression::getExpression();

		Minst->Matching(";");

		return new Command(var1, exp);
	}
	else {
		Minst->Matching("(");

		deque<Expression*> * exps;

		Expression * tmp = nullptr;

		while (tmp = Expression::getExpression()) {
			exps->push_back(tmp);
			if (!Minst->Match(","))
				break;
		}

		Minst->Matching(")");

		return new Command(var1, exps);
	}
}