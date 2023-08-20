#include "Test3Review_QuickSort.h"
#include<stdio.h>

void swapQuickPointers(int** arrPointers, int indexOne, int indexTwo)
{
	int* temp = arrPointers[indexOne];
	arrPointers[indexOne] = arrPointers[indexTwo];
	arrPointers[indexTwo] = temp;
}

void swapQuickNumbers(int* arrNumbers, int indexOne, int indexTwo)
{
	int temp = arrNumbers[indexOne];
	arrNumbers[indexOne] = arrNumbers[indexTwo];
	arrNumbers[indexTwo] = temp;
}

void quickSortNumberArray(int* arrNumbers, int lowIndex, int highIndex)
{
	if (lowIndex >= highIndex)
	{
		puts("\nList partially sorted!");
		return;
	}
	puts("\nBeginning new recursion!");
	int pivotIndex = highIndex; 
	int splitIndex = lowIndex;
	printf("Pivot Index: %d\nSplit Index: %d\n", pivotIndex, splitIndex);
	
	for (int i = lowIndex; i <= highIndex; i++)
	{
		if (arrNumbers[i] < arrNumbers[pivotIndex])
		{
			swapQuickNumbers(arrNumbers, i, splitIndex);
			splitIndex++;
		}
	}
	swapQuickNumbers(arrNumbers, splitIndex, pivotIndex);
	
	quickSortNumberArray(arrNumbers, lowIndex, splitIndex - 1);
	quickSortNumberArray(arrNumbers, splitIndex + 1, highIndex);
}





































void quickSortPointerArray(int** arrPointers, int lowIndex, int highIndex)
{
	if (lowIndex >= highIndex)
	{
		return;
	}
	
	int splitIndex = lowIndex; 
	int pivotIndex = highIndex;
	
	for (int i = lowIndex; i < highIndex; i++)
	{
		if (*arrPointers[i] < *arrPointers[pivotIndex])
		{
			swapQuickPointers(arrPointers, i, splitIndex);
			splitIndex++;
		}
	}
	swapQuickPointers(arrPointers, pivotIndex, splitIndex);
	quickSortPointerArray(arrPointers, lowIndex, splitIndex - 1);
	quickSortPointerArray(arrPointers, splitIndex + 1, highIndex);
}
