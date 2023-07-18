#include<stdio.h>
#include<stdlib.h>

void reverseSelectionSortArray(int* arrNumbers, int arrLength);

void selectionSortArray(int* arrNumbers, int numArrLength);

void bubbleSortArray(int* arrNumbers, int numArrLength);

void insertionSortArray(int* arrNumbers, int numArrLength);

void printArray(int* arrNumbers, int numArrLength);

void insertNumber(int* arrNumbers, int* numArrLength, int numArrLimit, int numInsert);

int main(int argCount, char** argStrings)
{
	printf("%s", "Hello world!\n");
	
	int numArrLimit = 12;
	int numArrLength = 10;
	int arrNumbers[] = {3, 5, 9, 1, 2, 4, 8, 7, 0, 6, 0, 0};

	selectionSortArray(arrNumbers, numArrLength);
	// insertionSortArray(arrNumbers, numArrLength);
	// bubbleSortArray(arrNumbers, numArrLength);
	// reverseSelectionSortArray(arrNumbers, numArrLength);	
	
	puts("Inserting Number");
	insertNumber(arrNumbers, &numArrLength, numArrLimit, 2);
	
	insertNumber(arrNumbers, &numArrLength, numArrLimit, -3);
}

void insertNumber(int* arrNumbers, int* numArrLength, int numArrLimit, 
	int numInsert)
{
	if (numArrLimit == *numArrLength)
	{
		return;
	}
	printf("%d\n", *numArrLength);
	
	arrNumbers[*numArrLength] = numInsert;
	*numArrLength += 1;
	
	printf("%d\n", *numArrLength);
	
	puts("Before!");
	printArray(arrNumbers, *numArrLength);
	
	for (int i = *numArrLength - 1; i > 0; i--)
	{
		if (arrNumbers[i] > arrNumbers[i - 1])
		{
			break;
		}
		numInsert = arrNumbers[i - 1];
		arrNumbers[i - 1] = arrNumbers[i];
		arrNumbers[i] = numInsert;
		printArray(arrNumbers, *numArrLength);
	}
	puts("After!");
	printArray(arrNumbers, *numArrLength);
}

void insertionSortArray(int* arrNumbers, int numArrLength)
{
	printArray(arrNumbers, numArrLength);
	int numLastIndex = numArrLength - 1;
	
	for (int i = 1; i <= numLastIndex; i++)
	{
		if (arrNumbers[i] < arrNumbers[i - 1])
		{
			
			for (int k = i; k > 0; k--)
			{
				if (arrNumbers[k] > arrNumbers[k - 1])
				{
					break;
				}
				int numTemp = arrNumbers[k];
				arrNumbers[k] = arrNumbers[k - 1];
				arrNumbers[k - 1] = numTemp;
			}
		}
	}
	printArray(arrNumbers, numArrLength);
}

void bubbleSortArray(int* arrNumbers, int numArrLength)
{
	printArray(arrNumbers, numArrLength);
	
	for (int i = 0; i < numArrLength - 1; i++)
	{
		int tempNum;
		
		for (int k = 0; k < numArrLength - i - 1; k++)
		{
			if (arrNumbers[k] > arrNumbers[numArrLength - 1 - i]) 
			{
				tempNum = arrNumbers[numArrLength - 1 - i];
				arrNumbers[numArrLength - 1 - i] = arrNumbers[k];
				arrNumbers[k] = tempNum;
			}
		}
	}
	printArray(arrNumbers, numArrLength);
}

void selectionSortArray(int* arrNumbers, int numArrLength)
{
	puts("Selection Sort");
	printArray(arrNumbers, numArrLength);
	int numLastIndex = numArrLength - 1;
	
	for (int i = 0; i <= numLastIndex; i++)
	{
		int numLowestIndex = i;
		
		for (int k = i; k <= numLastIndex; k++)
		{
			if (arrNumbers[k] < arrNumbers[numLowestIndex])
			{
				numLowestIndex = k;
			}
		}
		
		int temp = arrNumbers[i];
		
		arrNumbers[i] = arrNumbers[numLowestIndex];
		arrNumbers[numLowestIndex] = temp;
	}
	printArray(arrNumbers, numArrLength);
}

void reverseSelectionSortArray(int* arrNumbers, int numArrLength)
{	
	for (int i = 0; i < numArrLength - 1; i++)
	{
		int numMaxIndex = numArrLength - i - 1;
		
		for (int l = 0; l < numArrLength - i - 1; l++)
		{
			if (arrNumbers[l] > arrNumbers[numMaxIndex])
			{
				numMaxIndex = l;
			}
		}
		printArray(arrNumbers, numArrLength);
		printf("Biggest number: %d at %d, Last Number: %d at %d\n", 
			arrNumbers[numMaxIndex], numMaxIndex, 
			arrNumbers[numArrLength - i - 1], numArrLength - i - 1);
			
		int temp = arrNumbers[numMaxIndex];
		arrNumbers[numMaxIndex] = arrNumbers[numArrLength - i - 1];
		arrNumbers[numArrLength - i - 1] = temp;
		printArray(arrNumbers, numArrLength);
	}
	printArray(arrNumbers, numArrLength);
}

void printArray(int* arrNumbers, int numArrLength)
{
	fflush(stdin);
	printf("\nPrinting Array of Length: %d\n", numArrLength);
	for (int i = 0; i < numArrLength; i++)
	{
		printf("%d ", arrNumbers[i]);
	}
	puts("");
}
