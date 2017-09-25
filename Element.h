#pragma once

class Element
{
public:
	Element() {};
	~Element() {};

	virtual void GenerateAsm(char * decName) {};

	virtual void GenerateDataAsm() {}
};