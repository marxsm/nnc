#include "Reader.h"

char * Reader::getToken()
{
	// Skip first spaces
	while (1) {
		if (!rawData[0]) return nullptr;		
		if (getCharType(rawData[0]) == CT_UNKNOWN)
			Error("Unknown character '%c'.", rawData[0]);
		if (getCharType(rawData[0]) != CT_SKIP) break;
		rawData++;
	}

	char tmp[256];
	char* result = NULL;
	int count = 0;

	// String constant token
	if (rawData[0] == '\"') {
		bool skip = true;
		while (rawData[0]) {
			tmp[++count - 1] = rawData[0];
			rawData++;

			if (tmp[count - 1] == '\"' && !skip)
				break;

			if (skip) {
				skip = false;

				if (count >= 2) {

					char p = tmp[count - 1];

					tmp[count - 2] = '\"';
					tmp[count - 1] = ',';

					switch (p)
					{
					case 'n': {
						tmp[++count - 1] = '1';
						tmp[++count - 1] = '3';
						tmp[++count - 1] = ',';
						tmp[++count - 1] = '1';
						tmp[++count - 1] = '0';
						tmp[++count - 1] = ',';
					}break;
					case '\"': {
						tmp[++count - 1] = 34;
						tmp[++count - 1] = ',';
					}break;
					default:
						break;
					}
					tmp[++count - 1] = '\"';
				}				
			}
			else
				if (tmp[count - 1] == '\\')
					skip = true;
		}
	}
	else
		// Char constant token
		if (rawData[0] == '\'') {
			bool skip = true;
			while (rawData[0]) {
				count++;
				tmp[count - 1] = rawData[0];
				rawData++;

				if (tmp[count - 1] == '\'' && !skip)
					break;

				if (skip)
					skip = false;
				else
					if (tmp[count - 1] == '\\')
						skip = true;
			}
		}
		else
			// Square Token
			if (getCharType(rawData[0]) == CT_SQUARE) {
				count = 1;
				tmp[0] = rawData[0];
				rawData++;
			}
			else
				// Standard token
				while (rawData[0]) {
					int t = getCharType(rawData[0]);
					if (t == CT_UNKNOWN)
						Error("Undefined character");

					if (count > 0 && t != getCharType(tmp[count - 1]))
						break;
					count++;
					tmp[count - 1] = rawData[0];
					rawData++;
				}

	// Return token result
	result = (char*)calloc(1, count + 1);
	memcpy(result, tmp, count);
	return result;
}