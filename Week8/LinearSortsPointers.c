#include<stdio.h>
#include<stdlib.h>

void bubbleSortArray(int* arrPointers[], int numArrLength);

void selectionSortArray(int* arrPointers[], int numArrLength);

void insertionSortArray(int* arrPointers[], int numArrLength);

void printArrPointers(int* arrPointers[], int numArrLength);

int main(int argCount, char** argStrings)
{
	int numArrLength = 10;
	int arrNumbers[] = {3, 5, 9, 1, 2, 4, 8, 7, 0, 6};
	int* arrPointers[10];
	
	for (int i = 0; i < numArrLength; i++)
	{
		arrPointers[i] = &arrNumbers[i];
	}
	
	// bubbleSortArray(arrPointers, numArrLength);
	// selectionSortArray(arrPointers, numArrLength);
	insertionSortArray(arrPointers, numArrLength);
}

void selectionSortArray(int* arrPointers[], int numArrLength)
{
	puts("Selection Sort!");
	printArrPointers(arrPointers, numArrLength);
	
	for (int i = 0; i < numArrLength; i++)
	{
		int numLowestIndex = i;
		
		for (int k = i; k < numArrLength; k++)
		{
			if (*arrPointers[k] < *arrPointers[numLowestIndex])
			{
				numLowestIndex = k;
			}
		}
		
		int temp = *arrPointers[numLowestIndex];
		*arrPointers[numLowestIndex] = *arrPointers[i];
		*arrPointers[i] = temp;		
	}
		printArrPointers(arrPointers, numArrLength);	
}

void bubbleSortArray(int* arrPointers[], int numArrLength)
{
	puts("Bubble Sort!");
	printArrPointers(arrPointers, numArrLength);
	
	for (int i = numArrLength - 1; i >= 0; i--)
	{
		int temp;
		
		for (int k = i; k >= 0; k--)
		{
			if (*arrPointers[k] > *arrPointers[i])
			{
				temp = *arrPointers[i];
				*arrPointers[i] = *arrPointers[k];
				*arrPointers[k] = temp;
			}
		}
	}
	
	printArrPointers(arrPointers, numArrLength);
}

void insertionSortArray(int* arrPointers[], int numArrLength)
{
	puts("Insertion Sort!");
	printArrPointers(arrPointers, numArrLength);
	
	for (int i = 1; i < numArrLength; i++)
	{
		if (*arrPointers[i] < *arrPointers[i - 1])
		{
			int temp;
			for (int k = i; k > 0; k--)
			{
				if (*arrPointers[k] > *arrPointers[k - 1])
				{
					break;
				}
				temp = *arrPointers[k];
				*arrPointers[k] = *arrPointers[k - 1];
				*arrPointers[k - 1] = temp;
			}
		}
	}
		
	printArrPointers(arrPointers, numArrLength);
}

void printArrPointers(int* arrPointers[], int numArrLength)
{
	fflush(stdout);
	puts("\nPrinting Array!");
	for (int i = 0; i < numArrLength; i++)
	{
		printf("%d at %p\n", *arrPointers[i], arrPointers[i]);
	}
	puts("\n");
}
