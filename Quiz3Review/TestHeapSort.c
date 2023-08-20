#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

void ReHeap(int* a, int len, int parent);
void HeapSort(int* a, int n);

// My Functions

int main(int argCount, char** argStrings);

void myMaxHeapify(int* arrNumbers, int numLength, int parentIndex);

void myHeapSort(int* arrNumbers, int numLength);

void mySwap(int* arrNumbers, int indexOne, int indexTwo);

void printArray(int* arrNumbers, int numLength);

int main(int argCount, char** argStrings)
{
	int arrNumbers[] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int numLength = 10;
	
	puts("Before Sort!");
	printArray(arrNumbers, numLength);
	
	myHeapSort(arrNumbers, numLength);
	
	puts("After sort!");
	printArray(arrNumbers, numLength);
	
}

void myHeapSort(int* arrNumbers, int numLength)
{
	for (int i = numLength / 2; i >= 0; i--)
	{
		myMaxHeapify(arrNumbers, numLength, i);
	}
	
	for (int i = numLength - 1; i >= 0; i--)
	{
		mySwap(arrNumbers, i, 0);
		myMaxHeapify(arrNumbers, i, 0);
	}
}

void myMaxHeapify(int* arrNumbers, int numLength, int parentIndex)
{
	int childIndex = 2 * parentIndex + 1;
	
	while (childIndex < numLength - 1)
	{
		if (arrNumbers[childIndex] < arrNumbers[childIndex + 1])
		{
			childIndex = childIndex + 1;
		}
		
		if (arrNumbers[parentIndex] > arrNumbers[childIndex])
		{
			break;
		}
		
		mySwap(arrNumbers, parentIndex, childIndex);
		parentIndex = childIndex;
		childIndex = 2 * parentIndex + 1;
	}
}


void mySwap(int* arrNumbers, int indexOne, int indexTwo)
{
		int temp = arrNumbers[indexOne];
		arrNumbers[indexOne] = arrNumbers[indexTwo];
		arrNumbers[indexTwo] = temp;
}

void printArray(int* arrNumbers, int numLength)
{
	puts("Printing array!");
	for (int i = 0; i < numLength; i++)
	{
		printf("Index #%d: %d\n", i, arrNumbers[i]);
	}
}
