#include "Statement.h"

#include "Expression.h"


Statement * Statement::getStatement(deque<Declaration*> * params)
{
	Statement * result = nullptr;

	if (Minst->Match("return")) {

		Expression * exp = Expression::getExpression(true, params);

		result = new Statement(exp);
	}
	else
		if (Minst->Match("if")) {

			Minst->Matching("(");

			Expression * condition = Expression::getExpression(false, params);

			Minst->Matching(")");

			deque<Element*> * elements = new deque<Element*>();

			Element * element = nullptr;

			if (Minst->Match("{")) {

				while ((element = Statement::getStatement(params)) || (element = Expression::getExpression(true, params)))

					elements->push_back(element);

				Minst->Matching("}");

				result = new Statement(condition, elements);
			}
			else {

				element = Expression::getExpression(false, params);

				Minst->Match(";");
			}
		}

	return result;
}