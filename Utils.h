#pragma once

#include <string>

#include "StandardType.h"

using namespace std;

namespace Utils {

	char * getRawFileName(char * fileName);

	char * getAsFileName(char * fileName);

	char * getExeFileName(char * fileName);

	extern BASE64 ConstCounting;

	char* GetConstLabel();
}