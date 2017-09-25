#include "Compiler.h"

#include <Windows.h>

#pragma warning(disable : 4996)

void Compiler::CompileToBin()
{
	char * asFile = Utils::getAsFileName(rawName);
	char * binFile = Utils::getExeFileName(rawName);

	wchar_t wtext[256];
	mbstowcs(wtext, asFile, strlen(asFile) + 1);//Plus null
	LPWSTR ptr = wtext;

	ShellExecute(0, NULL, L"\\fasm\\fasm.exe", ptr, NULL, SW_HIDE);
}