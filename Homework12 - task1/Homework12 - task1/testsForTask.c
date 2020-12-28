#include "numbersLexer.h"
#include "testsForTask.h"

bool testForTrueValue(void)
{
	const char* test2 = "123554.23445";
	const char* test3 = "34234.55324E+123";
	const char* test4 = "12364.3244E23";
	const char* test5 = "5866.234E-535";
	const char* test6 = "213E442";
	return isNumber("1235") && isNumber(test2) && isNumber(test3) && isNumber(test4) && isNumber(test5) && isNumber(test6);
}

bool testForFalseValue(void)
{
	const char* test1 = "rerf43.5";
	const char* test2 = "2344.";
	const char* test3 = "12332.3232d";
	const char* test4 = "213323E";
	const char* test5 = "213323E+";
	return !isNumber(test1) && !isNumber(test2) && !isNumber(test3) && !isNumber(test4) && !isNumber(test5);
}

bool testResult(void)
{
	return testForFalseValue() && testForTrueValue();
}