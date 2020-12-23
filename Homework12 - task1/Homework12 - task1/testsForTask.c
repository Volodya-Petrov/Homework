#include "numbersLexer.h"
#include "testsForTask.h"

bool testForTrueValue(void)
{
	char test1[] = "1235";
	char test2[] = "123554.23445";
	char test3[] = "34234.55324E+123";
	char test4[] = "12364.3244E23";
	char test5[] = "5866.234E-535";
	char test6[] = "213E442";
	return isNumber(test1) && isNumber(test2) && isNumber(test3) && isNumber(test4) && isNumber(test5) && isNumber(test6);
}

bool testForFalseValue(void)
{
	char test1[] = "rerf43.5";
	char test2[] = "2344.";
	char test3[] = "12332.3232d";
	char test4[] = "213323E";
	char test5[] = "213323E+";
	return !isNumber(test1) && !isNumber(test2) && !isNumber(test3) && !isNumber(test4) && !isNumber(test5);
}

bool testResult(void)
{
	return testForFalseValue() && testForTrueValue();
}