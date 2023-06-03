#include<stdio.h>

int addByValue();

void addByReference();

int incrementByValue();

void incrementByReference();

int main(int argCount, char** arrStrings)
{
	printf("%s", "Hello world!\n");
	
	int numOutput;
	int* pntOutput = &numOutput;
	
	int numOne = 3;
	int numTwo = 4;
	
	int* pntOne = &numOne;
	int* pntTwo = &numTwo;
	
	*pntOutput = addByValue(*pntOne, *pntTwo);
	
	printf("The sum of %d and %d is %d\n", *pntOne, *pntTwo, *pntOutput);
	
	*pntOne = 5;
	*pntTwo = 8;
	
	addByReference(&numOutput, &numOne, &numTwo);
	
	printf("The sum of %d and %d is %d\n", numOne, numTwo, numOutput);
	
	
	numOne = 0;
	numTwo = 0;
	
	numOne = incrementByValue(numOne);
	incrementByReference(&numTwo);
	
	printf("The value of numOne is now: %d\n", numOne);
	printf("The value of numTwo is now: %d\n", numTwo);
	
	return 0;
}

int incrementByValue(int intNumber)
{
	return intNumber + 1;
}
void incrementByReference(int* pntNumber)
{
	++*pntNumber;
}

void addByReference(int* pntSum, int* pntOne, int* pntTwo)
{
	*pntSum = *pntOne + *pntTwo;	
}

int addByValue(int numOne, int numTwo)
{
	return numOne + numTwo;
}
