#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#define bitsNum 8
#define CIRCLE_AREA(X) ((PI) * (X) * (X))
#define ARR_SIZE 5
#define STRING_SIZE 255

void reviewPreprocessorDirectives();

void reviewPrintingAndScanning();

void reviewVariables();

void testScanWithPointer();

void calculateArea();

void reviewGoTo();

void reviewSelection();

void reviewGlobalVariables();

double calculateAverage();

int calculateSum();

void calculateMin();

void calculateMax();

void reviewArrays();

void reviewStrings();

int addByValue();

void addByReference();

int incrementByValue();

void incrementByReference();

void readNumber();

void myStrCat();

void reviewStringsExercise();

char* myStrCpy();

char* myStrConcat();

const char* globalVariable = "This is a global variable. It is saved in the "
	"data segment reserved for global variables and static variables.";

static const double PI = 3.14159;

int main(int argCount, char** arrStrings)
{
	printf("%s", "Hello world!\n");
	
//	printf("Sizeof: %hd\n", sizeof(long long int));
	
//	int numOutput;
//	int* pntOutput = &numOutput;
//	
//	int numOne = 3;
//	int numTwo = 4;
//	
//	int* pntOne = &numOne;
//	int* pntTwo = &numTwo;
//	
//	*pntOutput = addByValue(*pntOne, *pntTwo);
//	
//	printf("The sum of %d and %d is %d\n", *pntOne, *pntTwo, *pntOutput);
//	
//	*pntOne = 5;
//	*pntTwo = 8;
//	
//	addByReference(&numOutput, &numOne, &numTwo);
//	
//	printf("The sum of %d and %d is %d\n", numOne, numTwo, numOutput);
	
	
//	int numOne = 0;
//	int numTwo = 0;
//	numOne = incrementByValue(numOne);
//	incrementByReference(&numTwo);
//	
//	printf("The value of numOne is now: %d\n", numOne);
//	printf("The value of numTwo is now: %d\n", numTwo);
	
	// reviewStrings();
	// reviewArrays();
	// reviewPreprocessorDirectives();
	// reviewGlobalVariables();
	// reviewSelection();
	// reviewGoTo();
	// reviewVariables();
	// reviewPrintingAndScanning();
	reviewStringsExercise();
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

void reviewStrings()
{
	char chaString[STRING_SIZE] = {'s', 't', 'r', 'i', 'n', 'g', '!', '\0'};
	printf("This is a %s\n", chaString);
	
	printf("The length of this string is %d, which is not the same as the "
		"length of the char array, which is %d.\n\n", 
		strlen(chaString), 
		sizeof(chaString));
		
	char* strPointer = "string!";
	printf("We compare strings with strcmp\n. 0 is equal. Output s > s: %d\n", 
		strcmp(chaString, strPointer));
	printf("-1 if lesser. Output s > z: %d\n", strcmp(chaString, "z"));
	
	printf("1 if greater. Output s > a: %d\n", strcmp(chaString, "a"));
	
	char* strCopy = (char*)malloc(sizeof(char) * 255);
	strcpy(strCopy, chaString);
	
	printf("%s == %s output: %d\n", chaString, 
		strCopy, 
		strcmp(strCopy, chaString));
	free(strCopy);
	
	char* strVariable = (char*)malloc(sizeof(char) * 255);
	
	printf("Enter a string: ");
	scanf("%99s", strVariable);
	
	printf("%s\n", strVariable);
	
	free(strVariable);
	
	char* stringVar = "String!";
	char* stringEven = (char*)malloc(sizeof(char) * 255);
	char* stringOdd = (char*)malloc(sizeof(char) * 255);
	
	int numEven = 1;
	int numOdd = 1;
	
	printf("%d\n", strlen(stringVar));
	
	int numLength = strlen(stringVar);
	
	for (int i = 0; i < numLength; i++)
	{
		printf("Index %d. Current char: %c\n", i, *stringVar);
		if (i % 2 == 1)
		{
			*stringEven = *stringVar;
			stringEven++;
			numEven++;
		}
		else 
		{
			*stringOdd = *stringVar;
			stringOdd++;
			numOdd++;
		}
		stringVar++;
	}
	
	
	*stringEven = '\0';
	++stringEven;
	*stringOdd = '\0';
	++stringOdd;
	
	stringEven = stringEven - numEven;
	stringOdd = stringOdd - numOdd;
	
	printf("%s\n", stringEven);
	printf("%s\n", stringOdd);
	free(stringEven);
	free(stringOdd);
}

void reviewArrays(void)
{
	puts("Reviewing arrays and strings.");
	puts("I can use gets to retrieve a string from the input buffer.");
//	char* strInput = malloc(sizeof(char) * STRING_SIZE);
//	gets(strInput);
//	printf("%s\n", strInput);
//	free(strInput);

	printf("Size of Char Pointer: %d\n", sizeof(char*) * 8);
	printf("Size of Int Pointer: %d\n", sizeof(int*) * 8);
	
	int arrNumbers[5];
	int* pntNumbers = arrNumbers;
	
	for (int index = 0; index < ARR_SIZE; index++)
	{
		printf("%s", "Please enter an integer: ");
		scanf("%d", pntNumbers);
		pntNumbers++;
	}
	printf("All numbers entered!\n");
	pntNumbers = pntNumbers - ARR_SIZE;
	
	int numMinNumber = *pntNumbers;
	int numMaxNumber = *pntNumbers;
	
	for (int index = 0; index < ARR_SIZE; index++)
	{
		printf("Number %d: %d\n", index + 1, *pntNumbers);
		
		calculateMin(&numMinNumber, numMinNumber, *pntNumbers);
		calculateMax(&numMaxNumber, numMaxNumber, *pntNumbers);
		
		pntNumbers++;	
	}
	pntNumbers = pntNumbers - ARR_SIZE;
	double numAverage = calculateAverage(pntNumbers, ARR_SIZE);
	printf("The average is %g\n", numAverage);
	printf("The max number is %d\n", numMaxNumber);
	printf("The min number is %d\n", numMinNumber);
	
}

void calculateMin(int* pntMinNumber, int numMinNumber, int currentNumber)
{
	*pntMinNumber = numMinNumber < currentNumber 
		? numMinNumber
		: currentNumber;
}

void calculateMax(int* pntMaxNumber, int numMaxNumber, int currentNumber)
{
	*pntMaxNumber = numMaxNumber > currentNumber 
		? numMaxNumber
		: currentNumber;
}

double calculateAverage(int* pntNumbers, int numArrLength)
{
	int numSum = calculateSum(&pntNumbers, numArrLength);
	return 1.0 * numSum / numArrLength;
}

int calculateSum(int** pntNumbers, int numArrLength)
{
	int numSum = 0;
	
	if (numArrLength > 1)
	{
		numSum = calculateSum(pntNumbers, numArrLength - 1);
	}
	
	printf("Current number: %d\n", **pntNumbers);
	numSum = numSum + **pntNumbers;
	(*pntNumbers)++;
	
	return numSum;
}

void reviewPreprocessorDirectives(void)
{
	puts("Reviewing preprocessor directives.");
	double circleArea = CIRCLE_AREA(5.0);
	printf("Circle area: %lf\n", circleArea);
	
	int arrNumbers[ARR_SIZE] = {5, 4, 3, 2, 1};
	
	for (int i = 0; i < ARR_SIZE; i++)
	{
		
		printf("Index %d. %d\n", i, arrNumbers[i]);
	}
}

void copyString(char** pntString)
{
	char* strVar = (char*)malloc(sizeof(char) * 255);
	int numChars = sprintf(strVar, "%s", "This is a dynamically allocated variable. It is "
		"stored in the heap, and must be freed when it is no longer needed.");
	*pntString = strVar;
}

void reviewGlobalVariables(void)
{
	char* localVariable = "This is a local variable. It is saved in the stack," 
		" which contains all the local variables for all functions.";
		
	char* heapVariable;
	copyString(&heapVariable);
	
	printf("%s\n", globalVariable);
	printf("%s\n", localVariable);
	printf("%s\n", heapVariable);
	
	printf("Freeing allocated memory %p\n", heapVariable);
	free(heapVariable);
}

void reviewSelection(void)
{
		
	int inputNum;
	int* pntInputNum = &inputNum;
	printf("Please enter an integer: ");
	scanf("%d", pntInputNum);
	
	switch (inputNum % 2)
	{
		case 0: 
			printf("Number is even\n");
			break;
		case 1: 
			printf("Number is odd.\n");
			break;
		default: 
			printf("Something went wrong.\n");
			break;
	}
}

void reviewGoTo(void)
{
	int numLoop;
	int* pntNumLoop = &numLoop;
	
	int terNum = 1 > 2 
		? 3
		: 4;
	printf("TerNum: %d\n", *&terNum);
	
	for(int i = 0; i< 10; i++)
	{
		printf("Loop counter: %d\n", *&i);
		if (i == 3)
		{
			*pntNumLoop = i + 1;
			goto endLoop;
		}
	}
	
	endLoop:
		printf("The loop ended on iteration %d\n", *pntNumLoop);
}

void reviewVariables(void)
{
	char* localVariable = "This is a local variable. It is saved in the stack.";
	
	long long numLong = 1L;
	
	printf("%s\n", localVariable);
	printf("%s\n", globalVariable);
	char varChar = -1;
	printf("sizeof char: %.0lf\n", pow(2, sizeof(char) * 8));
	
	
	printf("Short bytes: %hd, bits: %hd, max: %hd, min: %hd\n", 
		sizeof(short), 
		sizeof(short) * 8, 
		(long int)pow(2, (sizeof(short) * 8) - 1), 
		(short int)1 - (short int)pow(2, (sizeof(short) * 8 - 1)));
		
	printf("int bytes: %hd, bits: %hd, max: %d, min : %d\n", 
		sizeof(int),
		sizeof(int) * 8,
		(int)pow(2, (sizeof(int) * 8) - 1), 
		1 - (int)pow(2, (sizeof(int) * 8) - 1));
		
	printf("long int bytes: %hd, bits: %hd, max: %lld, min: %lld\n", 
		sizeof(long long), 
		sizeof(long long) * 8, 
		(long long)pow(2, (sizeof(long long) * 8) - 1),
		1L - (long long)pow(2, (sizeof(long long) * 8) - 1));
		
	printf("double bytes: %hd, bits: %hd\n", 
		sizeof(double), 
		sizeof(double) * 8);
		
	printf("float bytes: %hd, bits: %hd\n", 
		sizeof(float), 
		sizeof(float) * 8);
		
	printf("bool bytes: %hd, bits: %hd\n", 
		(short)sizeof(bool), 
		(short)sizeof(bool) * 8);
		
	testScanWithPointer();
}

void testScanWithPointer(void)
{
	bool blnNumber = 0;
	printf("Bool number: %b\n", blnNumber);
	
	int intNumber;
	int* pntNumber = &intNumber;
	
	unsigned int uIntNumber = 1U;
	unsigned long uLngNUmber = 1UL;
	
	printf("Enter an integer: ");
	scanf("%d", pntNumber);
	printf("You have entered %d\n", *pntNumber);
}

void calculateCircumference(void)
{
	double radius;
	printf("%s", "Please enter the radius of a circle: ");
		
	int numVariables = scanf("%lf", &radius);
	
	if (numVariables == 1)
	{
		printf("The circumference of the circle is: %.2lf\n", radius * 2 * PI);
	}
}

void reviewPrintingAndScanning(void)
{
	char* myName = "Kyle Galway";
	
	printf("%s\n", myName);
	printf("Printing float: %f\n", 1.0f);
	printf("Printing integer: %d\n", -2);
	printf("Printing long integer: %ld\n", 3);
	printf("Printing double: %.2lf\n", 4.0);
	printf("Also printing double: %.3f\n", 4.0);
	printf("Printing char: %c\n", '5');
	printf("Printing string: %s\n", "678");
	printf("Printing unsigned integer: %u\n", 2);
	printf("Printing unsigned long integer: %lu\n", 3);
	printf("Printing hexadecimal integer: %x\n", 18);
	printf("Printing scientific notation double: %e\n", 220.2);
	printf("Printing auto formatted double: %g\n", 220.2);
	printf("%s", "\tThis is a tab.\n");
	printf("%s", "\aThis is an alert.\n");
	printf("This is a backslash \\.\n");
	printf("This is a \"double quote.\"");
}
	
void readNumber(void)
{
	int numInput;
	printf("%s", "Enter an integer: ");
	int numVariables = scanf("%d", &numInput);
	if (numVariables == 1)
	{
		printf("\nSuccessfully scanned %d\n", numInput);
	}
	else 
	{
		printf("Unsuccessully read variable.\n");
	}

}

void myStrCat(char* strDest, char* strSource, char** pntDest)
{
	int lengthDest = strlen(strDest);
	int lengthSource = strlen(strSource);
	int lengthString = lengthDest + lengthSource;
	char* catString = malloc(sizeof(char) * lengthString);
	printf("Allocating memory for pointer %p\n", catString);	
	
	printf("Word one: ");
	for (int i = 0; i < lengthDest; i++)
	{
		*catString = strDest[i];
		printf("%c", *catString);
		catString++;
	}
	printf("\nWord two:");
	
	for (int i = 0; i < lengthSource; i++)
	{
		*catString = strSource[i];
		printf("%c", *catString);
		catString++;
	}
	
	*catString = '\0';
	
	catString -= lengthString;
	
	printf("\nNew string: %s\n", catString);
	
	*pntDest = catString;
	printf("Assigning memory %p\n", *pntDest);
}

int myStrLen(char* strInput)
{
	static int numLength = 0;
	if (strInput[numLength] != '\0')
	{
		printf("Index %d. %c\n", numLength + 1, strInput[numLength]);
		numLength++;
		myStrLen(strInput);
	}
	return numLength;
}

char myStrCmp(char* strOne, char* strTwo)
{
	return *strOne - *strTwo;
}

char* myStrCpy(char* sourceString)
{
	printf("%d\n", strlen(sourceString));
	char* copyString = calloc(strlen(sourceString), sizeof(char));
	printf("%p\n", copyString);
	while(*sourceString != '\0')
	{
		*copyString = *sourceString;
		printf("Copying: %c\n", *copyString);
		copyString++;
		sourceString++;
	}
	*copyString = '\0';
	copyString = copyString - strlen(sourceString);
	printf("%p\n", copyString);
	printf("CopyString: %s\n", copyString);
	return copyString;
}

char* myStrConcat(char* strDest, char* strSource)
{
	int lengthDest = strlen(strDest);
	int lengthSource = strlen(strSource);
	int lengthString = lengthDest + lengthSource;
	char* catString = malloc(sizeof(char) * lengthString);
	printf("Allocation for char* return!\nAllocated memory: %p\n", catString);
		
	printf("Word one: ");
	for (int i = 0; i < lengthDest; i++)
	{
		*catString = strDest[i];
		printf("%c", *catString);
		catString++;
	}
	printf("\nWord two:");
	
	for (int i = 0; i < lengthSource; i++)
	{
		*catString = strSource[i];
		printf("%c", *catString);
		catString++;
	}
	
	*catString = '\0';
	
	catString -= lengthString;
	
	printf("\nNew string: %s\n", catString);
	
	printf("Returning memory: %p\n", catString);
	return catString;
}

void reviewStringsExercise(void)
{
	char* destString = "Hello";
	char* sourceString = " World!";

	char* catString = myStrConcat(destString, sourceString);
	
	myStrCat(destString, sourceString, &destString);
	
	printf("\nNew string through pointer allocation at %p: : %s\n", destString, destString);
	
	printf("New string through return at %p: %s\n", catString, catString);
	

	printf("Length with strlen: %d\n", strlen(catString));

	
	puts("");
	
	char* strCopy = myStrCpy(catString);
	
	printf("Copy string: %s\n", strCopy);
	
//	printf("Compare with strcmp: %d\n", strcmp(destString, sourceString));
//	printf("Compare with myStrCmp: %hd\n", myStrCmp(destString, sourceString));
	
//	printf("Compare with strcmp: %d\n", strcmp(destString, catString));
//	printf("Compare with myStrCmp: %hd\n", myStrCmp(sourceString, sourceString));
//	
//	printf("Compare with strcmp: %d\n", strcmp(sourceString, destString));
//	printf("Compare with myStrCmp: %d\n", myStrCmp(sourceString, destString));

//	printf("Freeing destString at %p\n", destString);
//	printf("Freeing catString at %p\n", catString);
//	free(catString);
//	free(destString);
	
}

