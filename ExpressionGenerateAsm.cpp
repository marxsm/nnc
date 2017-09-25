#include "Expression.h"


#pragma warning(disable: 4996)


int getOperPriority(Expression * oper)
{
	if (!strcmp(oper->name, "="))
		return 0;
	if (!strcmp(oper->name, "+") || !strcat(oper->name, "-"))
		return 1;
	if (!strcmp(oper->name, "*") || !strcat(oper->name, "/"))
		return 2;
	return -1;
}

void ProcessOperator(Expression * expression) 
{
	if (!strcmp(expression->name, "+")) {
		Wrinst->Writeln("\tpop ebx");
		Wrinst->Writeln("\tpop eax");
		Wrinst->Writeln("\tadd eax, ebx");
	}
	if (!strcmp(expression->name, "-")) {
		Wrinst->Writeln("\tpop ebx");
		Wrinst->Writeln("\tpop eax");
		Wrinst->Writeln("\tSUB eax, ebx");
	}
	if (!strcmp(expression->name, "*")) {
		Wrinst->Writeln("\tpop ebx");
		Wrinst->Writeln("\tpop eax");
		Wrinst->Writeln("\tmul ebx");
	}
	if (!strcmp(expression->name, "/")) {
		Wrinst->Writeln("\tpop ebx");
		Wrinst->Writeln("\tpop eax");
		Wrinst->Writeln("\tdiv ebx");
	}
	Wrinst->Writeln("\tpush eax");
	Wrinst->Writeln("");
}

void Expression::GenerateAsm(char * decName)
{

	switch (DecType)
	{
	case 'N': {
		Log("Assemblying name %s", name);

		Wrinst->Writeln("\tpush [%s]", name);
	}break;
	case 'D': {
		Log("Assemblying number %u", *num);

		Wrinst->Writeln("\tpush %u", *num);
	}break;
	case 'A': {
		Log("Assemblying assignment %s", name);

		exp->GenerateAsm(decName);
		Wrinst->Writeln("\tpop eax");
		Wrinst->Writeln("\tmov [%s], eax", name);
	}break;
	case 'S': {
		Log("Assemblying string %s", str);

		Wrinst->Writeln("\tpush %s", name);
	}break;
	case 'F': {

		Log("Assemblying function call %s", name);

		Expression * expression = nullptr;

		reverse(exps->begin(), exps->end());

		for (auto expression : *exps)

			expression->GenerateAsm(decName);

		reverse(exps->begin(), exps->end());


		if (!strcmp(name, "printf"))
			Wrinst->Writeln("\tcall [%s]", name);
		else {
			Wrinst->Writeln("\tCALL %s", name);
			Wrinst->Writeln("\tadd esp, %u", exps->size() * 4);
			Wrinst->Writeln("\tpush eax");
		}

		Wrinst->Writeln("");
	}break;
	case 'E': {
		Log("Assemblying expression");

		deque<Expression*> * operStack = new deque<Expression*>();

		Expression * expression = nullptr;

		for (auto expression : *exps) {

			if (expression->DecType == 'O') {

				while (operStack->size() && (getOperPriority(operStack->front()) <= getOperPriority(expression))) ProcessOperator(operStack->front()), operStack->pop_front();

				operStack->push_front(expression);
			}
			else
				expression->GenerateAsm(decName);
		}

		Expression * oper = nullptr;

		for (auto oper : *operStack) {

			Expression * oper = operStack->front();

			operStack->pop_front();

			ProcessOperator(oper);
		}

		delete operStack;

	}break;
	default: {
		Log("Assemblying unknown %s type %c", name, DecType);
	}
			 break;
	}
}