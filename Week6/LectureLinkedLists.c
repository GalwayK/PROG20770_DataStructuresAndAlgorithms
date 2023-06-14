#include<stdio.h>
#include<stdlib.h>

typedef struct Number
{
	struct Number* pntNextNumber;
	int intNumber;
} Number;


Number* getLastNumber(Number* pntNumber)
{
	if (pntNumber == NULL || pntNumber -> pntNextNumber == NULL)
	{
		return pntNumber;
	}
	else 
	{
		return getLastNumber(pntNumber -> pntNextNumber);
		printf("Number: %d\n", pntNumber -> intNumber);
	}
}

Number getFirstNumber(Number* pntNumber)
{
	return *pntNumber;
}

Number* createNumber()
{
	Number varNumber;
	printf("%s", "Please enter an integer: ");
	scanf("%d", &(varNumber.intNumber));
	printf("Read number: %d\n", varNumber.intNumber);
	varNumber.pntNextNumber = NULL;
	Number* pntNumber = (Number*)calloc(1, sizeof(Number));
	*pntNumber = varNumber;
	return pntNumber;
}

void addNumberToListEnd(Number* listNumbers)
{
	Number* pntNewNumber = createNumber();
	Number* pntLastNumber = getLastNumber(listNumbers);

	pntLastNumber -> pntNextNumber = pntNewNumber;
	
}

void addNumberToListStart(Number* listNumbers)
{
	Number* pntNewNumber = createNumber();
	Number* oldFirst = (Number*)malloc(sizeof(Number));
	*oldFirst = *listNumbers; 
	*listNumbers = *pntNewNumber;
	listNumbers -> pntNextNumber = oldFirst;	
}

Number* insertNumber(Number* listNumbers, Number* newNumber, int* numIndex)
{
	if (*numIndex != 1)
	{
		printf("Iteration %d\n", *numIndex);
		*numIndex -= 1;
		listNumbers -> pntNextNumber = insertNumber(listNumbers -> pntNextNumber, newNumber, numIndex);
	}
	else 
	{
		newNumber -> pntNextNumber = listNumbers -> pntNextNumber;
		listNumbers -> pntNextNumber = newNumber;
	}
	return listNumbers;
}

void addNumberToListSection(Number* listNumbers)
{
	int numIndex;
	printf("Enter the index to insert: ");
	scanf("%d", &numIndex);
	
	Number* pntInsert = createNumber();
	insertNumber(listNumbers, pntInsert, &numIndex);
}

void printListNumbers(Number* listNumbers)
{
	if (listNumbers != NULL)
	{
		printf("The current number is: %d\n", listNumbers -> intNumber);
		printListNumbers(listNumbers -> pntNextNumber);
	}
}

int main (int argCount, char** argStrings)
{
	puts("Hello world!");
	Number firstNumber;
	Number* listNumbers = &firstNumber;
	
	listNumbers -> intNumber = 0;
	listNumbers -> pntNextNumber = NULL;
	
	puts("Adding numbers to end of list!");
	addNumberToListEnd(listNumbers);
	addNumberToListEnd(listNumbers);
	addNumberToListEnd(listNumbers);
	
	puts("Adding numbers to start of list!");
	addNumberToListStart(listNumbers);
	addNumberToListStart(listNumbers);
	addNumberToListStart(listNumbers);
	
	puts("Adding numbers to middle of list!");
	addNumberToListSection(listNumbers);
	
	puts("Printing list!");
	printListNumbers(listNumbers);
}
