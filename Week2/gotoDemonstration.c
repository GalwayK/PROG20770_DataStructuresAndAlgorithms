#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* substring(char *string, int intStart, int intEnd)
{
	char strSubstring[255];
	
	if (intStart > intEnd || intEnd > strlen(string))
	{
		puts("Invalid specifier in function call.");
		return string;
	}
	
	while (1)
	{
		if (intStart == intEnd)
		{
			goto lblEndLoop;
		}
		strSubstring[intStart] = string[intStart];
		++intStart;
	}
	
	lblEndLoop: 
	
	strSubstring[intStart] = '\0';
	
	return strSubstring;
}

int breakLoopWithGoto()
{
	int arrCounters[2];
	for (arrCounters[0] = 0; arrCounters[0] < 10; arrCounters[0]++)
	{
		for (arrCounters[1] = 0; arrCounters[1] < 10; arrCounters[1]++)
		{
			printf("%s", "Enter 'quit' to quit: ");
			char strInput[255] = "";
			fgets(strInput, 255, stdin);
			int intLength = strlen(strInput);
			
			char* strSubString = substring(strInput, 0, intLength - 1);
			
			printf("You have entered: %s!\n", strSubString);
			
			// For some reason strcmp returns a 0 when the strings are not equal
			// This means that it checks for inequality instead of equality.
			if (strcmp(strInput, "quit\n") == 0)
			{
				// If quit is entered, break enter nested loop structure.
				goto lblQuit;
			}
		}
	}
	
	lblQuit: 
		puts("Thank you for using this weird little script!");
		
	return 0;
}

int findLargestOfThreeNumbers(int* arrNumbers)
{
	int intLargestNumber = arrNumbers[0] > arrNumbers[1] 
		? arrNumbers[0] > arrNumbers[2] 
			? arrNumbers[0]
			: arrNumbers[2]
		: arrNumbers[1];
		
	return intLargestNumber;
}

int main(int argCount, char** argStrings)
{
	int intIndex = 0;
	int arrNumbers[3] = {0, 0, 0};
	
	for (intIndex; intIndex < 3; intIndex++)
	{
		printf("%s", "Please enter a number: ");
		int intNumber = 0;
		
		scanf("%d", &intNumber);
	
		arrNumbers[intIndex] = intNumber;
		printf("Index %d. %d\n", intIndex + 1, arrNumbers[intIndex]);
	}
	
	int intLargest = findLargestOfThreeNumbers(arrNumbers);
	printf("The largest number was %d!\n", intLargest);
//	breakLoopWithGoto();
		
}

