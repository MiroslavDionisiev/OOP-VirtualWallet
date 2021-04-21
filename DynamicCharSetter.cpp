#include "DynamicCharSetter.h"
#include <iostream>
#include <cstring>

void DynamicCharSetter::setValue(char** field, const char* text)
{
	if (text != nullptr)
	{
		if (*field != nullptr)
		{
			delete[] *field;
		}
		*field = new char[strlen(text) + 1];
		strcpy_s(*field, strlen(text) + 1, text);
	}
	else
	{
		*field = new char[1];
		*field[0] = '\0';
	}
}