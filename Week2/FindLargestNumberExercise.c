#include<stdbool.h>
#include<stdio.h>
#include<string.h>

// Find largest number. 
// NOTE: Not efficient, for instuction only. 
int findLargestOfThreeNumbers(int* arrNumbers)
{
	int intLargestNumber = arrNumbers[0] > arrNumbers[1] 
		? arrNumbers[0] > arrNumbers[2] 
			? arrNumbers[0]
			: arrNumbers[2]
		: arrNumbers[1] > arrNumbers[2] 
			? arrNumbers[1]
			: arrNumbers[2];
		
	return intLargestNumber;
}

// Return 1 for odd number and 0 for even number. 
bool checkNumberIsOdd(int intNumber)
{
	bool boolType = intNumber % 2 == 1 ? 1 : 0;
	return boolType; 
}

// Recursive function to fill array. 
// NOTE: This function absolutely should not be done recursively. 
void fillArrayWithUserInput(int intNumbersCount, int* arrNumbers)
{
	if (intNumbersCount > 0)
	{
		fillArrayWithUserInput(intNumbersCount - 1, arrNumbers);
		printf("%s", "Please enter a number: ");
		scanf("%d", &arrNumbers[intNumbersCount - 1]);
		printf("Index %d. %d\n", intNumbersCount, arrNumbers[intNumbersCount - 1]);
	}
}

// In class exercise. 
void completeExercise()
{
	int intIndex = 0;
	int arrNumbers[3] = {0, 0, 0};
	
	fillArrayWithUserInput(3, arrNumbers);
	
	int intLargest = findLargestOfThreeNumbers(arrNumbers);
	
	char strType[255];
	
 	bool booType = checkNumberIsOdd(intLargest);
	
	switch (booType)
	{
		case 1: 
			strcpy(strType, "odd");
			break;
		case 0: 
			strcpy(strType, "even");
			break;
		default: 
			break;	
	}
	
	printf("The largest number was %d and it is %s!\n", intLargest, strType);
}

// Welcome to this highly inefficient yet interesting exercise solution.
int main(int argCount, char** argStrings)
{
	completeExercise();
}

