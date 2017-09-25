#include "Declaration.h"

#include "Statement.h"
#include "Expression.h"


Declaration * Declaration::getDeclaration()
{
	Declaration * result = nullptr;

	char *var1, *var2;

	Expression * var3 = nullptr;

	deque<Declaration*> * params = nullptr;

	deque<Element*> * elements = nullptr;

	if (var1 = Minst->GetName(false)) {

		var2 = Minst->GetName(true);

		if (Minst->Match("(")) {

			params = new deque<Declaration*>();

			Declaration* tmp = nullptr;

			while (tmp = Declaration::getParameter(var2)) {

				params->push_back(tmp);

				if (!Minst->Match(","))
					break;
			}

			Minst->Matching(")");

			Minst->Matching("{");

			Element * element;

			elements = new deque<Element*>();

			while ((element = Statement::getStatement(params)) || (element = Expression::getExpression(true, params)))

				elements->push_back(element);

			Minst->Matching("}");

			result = new Declaration(var1, var2, params, elements);
		}
		else {
			if (Minst->Match("="))
				var3 = Expression::getExpression(false, nullptr);

			result = new Declaration(var1, var2, var3);

			Minst->Matching(";");
		}
	}

	return result;
}