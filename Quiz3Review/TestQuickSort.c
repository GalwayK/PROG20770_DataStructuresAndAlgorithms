#include<stdio.h>
#include<stdlib.h>

void QuickSort(int* arrNumbers, int numLength, int low, int high);

void myQuickSort(int* arrNumbers, int lowIndex, int highIndex);

void mySwap(int* arrNumbers, int indexOne, int indexTwo);

void mySwap(int* arrNumbers, int indexOne, int indexTwo);

void printArray(int* arrNumbers, int numLength);

int main(int argCount, char** argStrings)
{
	puts("Learning Quick Sort!");
	
	int arrNumbers[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	int numLength = 10;
	
	myQuickSort(arrNumbers, 0, 9);
	printArray(arrNumbers, numLength);
}

void myQuickSort(int* arrNumbers, int lowIndex, int highIndex)
{
	if (lowIndex >= highIndex)
	{
		return;
	}
	
	int pivotIndex = highIndex; 
	int splitIndex = lowIndex; 
	
	for (int i = lowIndex; i < highIndex; i++)
	{
		if (arrNumbers[i] < arrNumbers[pivotIndex])
		{
			mySwap(arrNumbers, splitIndex, i);
			splitIndex++;
		}
	}
	mySwap(arrNumbers, pivotIndex, splitIndex);
	printArray(arrNumbers, 10);
	
	myQuickSort(arrNumbers, lowIndex, splitIndex - 1);
	myQuickSort(arrNumbers, splitIndex + 1, highIndex);
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
