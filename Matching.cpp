#include "Matcher.h"

void Matcher::Matching(char * word)
{
	if (!Match(word)) {
		Log("At position ");
		for (int i=0; i<3; i++)
			if (!Empty()) {
				printf("%s ", tokens->front());
				NextToken();
			}

		printf("\n");

		Error("Token %s expected.", word);
	}
}