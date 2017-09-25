#include "Writter.h"



Writter::Writter()
{
}


Writter::~Writter()
{
}

Writter * Writter::instance;

Writter * Writter::Instance()
{
	if (!instance)
		instance = new Writter();

	return instance;
}
