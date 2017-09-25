#include "Expression.h"

#include "Declaration.h"


Expression * Expression::getExpression(bool isCommand, deque<Declaration*> * params)
{
	if (Minst->Equal("}") || Minst->Equal(")"))
		return nullptr;

	int OpenSquares = 0;
	while (Minst->Match("(")) OpenSquares++;

	Expression * result = nullptr;

	bool PrevIsOper = true;

	char * oper = nullptr, *name = nullptr, * str = nullptr;
	BASE64 * num = nullptr;
	Expression * exp = nullptr;
	deque<Expression*> * exps = new deque<Expression*>();

	while ((PrevIsOper && (name = Minst->GetName(false))) || (PrevIsOper && (num = Minst->GetNumberConstant(false))) || (PrevIsOper && (str = Minst->GetStringConstant(false))) || (!PrevIsOper && (oper = Minst->GetOperator(false))) || (PrevIsOper && Minst->Equal("(") && (exp = Expression::getExpression(false, params)))) {

		if (name) {

			Declaration * param = nullptr;

			for (auto param : *params)

				if (!strcmp(param->rawName, name))

					name = param->name;

			if (Minst->Match("(")) {

				deque<Expression*> * childexps = new deque<Expression*>();
				Expression * childexp = nullptr;

				while ((childexp = Expression::getExpression(false, params))) {

					childexps->push_back(childexp);

					if (!Minst->Match(",")) break;
				}

				Minst->Matching(")");

				exps->push_back(new Expression(name, childexps));
			}
			else {
				if (Minst->Match("="))
					if (!exps->size()) {
						PrevIsOper = false;
						result = new Expression(name, Expression::getExpression(false, params));
						break;
					}
					else
						Error("Multiple assignment is not supported.");
				else
					exps->push_back(new Expression(name));
			}
		}
		if (num)
			exps->push_back(new Expression(num));
		if (str)
			exps->push_back(new Expression(str, 0));
		if (oper)
			exps->push_back(new Expression(oper, ""));
		if (exp)
			exps->push_back(exp);

		PrevIsOper = false;
		if (oper)
			PrevIsOper = true;

		name = nullptr;
		num = nullptr;
		str = nullptr;
		oper = nullptr;
		exp = nullptr;
	}

	if (PrevIsOper)
		Error("Cannot finish expression with an operator");

	if (exps->size())
		result = new Expression(exps);

	while (OpenSquares--) Minst->Matching(")");

	if (isCommand)
		Minst->Matching(";");

	return result;
}