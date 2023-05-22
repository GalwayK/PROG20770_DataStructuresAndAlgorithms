#include<stdio.h>
#include<stdbool.h>
#include<string.h>

void readNumbers(int* arrNumbers, int numIndex)
{
	if (numIndex > 0)
	{
		readNumbers(arrNumbers, numIndex - 1);
	}
	printf("%s", "Enter a number: ");
	int numPrompt;
	scanf("%d", &numPrompt);
	arrNumbers[numIndex] = numPrompt;
}

void printArrNumbers(int* arrNumbers, int numArrLength)
{
	if (numArrLength > 0)
	{
		printArrNumbers(arrNumbers, numArrLength - 1);
	}
	printf("Element %d: %d\n", numArrLength + 1, arrNumbers[numArrLength]);
}

int calcArraySum(int* arrNumbers, int arrNumLength)
{
	int intSum = 0;
	if (arrNumLength > 0)
	{
		intSum = calcArraySum(arrNumbers, arrNumLength - 1) 
			+ arrNumbers[arrNumLength];
	}
	return intSum;
}

int calcArrayMin(int* arrNumbers, int arrNumLength)
{
	int numMin;
	
	if (arrNumLength > 0)
	{
		numMin = calcArrayMin(arrNumbers, arrNumLength - 1);
	}
	else 
	{
		numMin = arrNumbers[arrNumLength];
	}
	
	numMin = arrNumbers[arrNumLength] < numMin 
		? arrNumbers[arrNumLength] 
		: numMin;
		
	printf("Lowest value found: %d\n", numMin);
		
	return numMin;
}

int calcArrayMax(int* arrNumbers, int arrNumLength)
{
	int numMax;
	
	if (arrNumLength > 0)
	{
		numMax = calcArrayMax(arrNumbers, arrNumLength - 1);
	}
	else 
	{
		numMax = arrNumbers[arrNumLength];
	}
	
	numMax = arrNumbers[arrNumLength] > numMax 
		? arrNumbers[arrNumLength] 
		: numMax;
		
	printf("Highest value found: %d\n", numMax);
		
	return numMax;
}

void exerciseStatisticsCalculator()
{
	int numArrLength;
	printf("How many elements do you want to enter: ");
	scanf("%d", &numArrLength);
	
	int arrNumbers[numArrLength];
	
	numArrLength -= 1;
	
	readNumbers(arrNumbers, numArrLength);
	
	printArrNumbers(arrNumbers, numArrLength);
	int numArrSum = calcArraySum(arrNumbers, numArrLength);
	int numArrMin = calcArrayMin(arrNumbers, numArrLength);
	int numArrMax = calcArrayMax(arrNumbers, numArrLength);
	
	printf("The sum of the elements is: %d\n", numArrSum);
	printf("The minimum value is: %d\n", numArrMin);
	printf("The maximum value is %d: \n", numArrMax);
}

int main(int arcCount, char** argStrings)
{
	char strOne[] = "Hello";
    long long int intStrSize = sizeof(strOne) / sizeof(char);
	char * strTwo= &strOne[0];
	
	for (long long int length = 0; length < intStrSize; length++)
	{
		printf("ArrayOne: %c\n", strOne[length]);
		printf("PointerOne: %c\n", *strTwo);
		strTwo++;
		
	}
//	strcpy(strTwo, strOne);
//	
//	printf("%d\n", *strOne);
//	printf("%d\n", *strTwo);
//	printf("%s\n", strOne);
//	printf("%s\n", strTwo);
}
