#include "numbersLexer.h"
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isNumber(char string[])
{
	int index = 0;
	int state = 0;
	char currentChar = '\0';
	while (index != strlen(string))
	{	
		currentChar = string[index];
		switch (state)
		{
		case 0:
			state = 1;
			if (!isdigit(currentChar))
			{
				return false;
			}
			break;
		case 1:
			if (currentChar == '.')
			{
				state = 2;
				break;
			}
			if (currentChar == 'E')
			{
				state = 4;
				break;
			}
			if (!isdigit(currentChar))
			{
				return false;
			}
			break;
		case 2:
			if (!isdigit(currentChar))
			{
				return false;
			}
			state = 3;
			break;
		case 3:
			if (currentChar == 'E')
			{
				state = 4;
				break;
			}
			if (!isdigit(currentChar))
			{
				return false;
			}
			break;
		case 4:
			if (currentChar == '+' || currentChar == '-')
			{
				state = 5;
				break;
			}
			if (isdigit(currentChar))
			{
				state = 6;
				break;
			}
			return false;
		case 5:
			if (!isdigit(currentChar))
			{
				return false;
			}
			state = 6;
			break;
		case 6:
			if (!isdigit(currentChar))
			{
				return false;
			}
			break;
		}
		index++;
	}
	return state == 1 || state == 3 || state == 6;
}