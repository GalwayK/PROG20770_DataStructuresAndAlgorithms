#include "Test3Review_SelectionSort.h"

void selectionSwapPointers(int** arrPointers, int indexOne, int indexTwo)
{
	int* temp = arrPointers[indexOne];
	arrPointers[indexOne] = arrPointers[indexTwo];
	arrPointers[indexTwo] = temp;
}

void selectionSwapNumbers(int* arrNumbers, int indexOne, int indexTwo)
{
	int temp = arrNumbers[indexOne];
	arrNumbers[indexOne] = arrNumbers[indexTwo];
	arrNumbers[indexTwo] = temp;
}

void selectionSortPointerArray(int** arrPointers, int lengthArr)
{
	for (int i = 0; i < lengthArr - 1; i++)
	{
		int indexSmallest = i;
		for (int j = i; j < lengthArr; j++)
		{
			if (*arrPointers[j] < *arrPointers[indexSmallest])
			{
				indexSmallest = j;
			}
		}
		selectionSwapPointers(arrPointers, i, indexSmallest);
	}
}

void selectionSortNumberArray(int* arrNumbers, int lengthArr)
{
	for (int i = 0; i < lengthArr; i++)
	{
		int indexSmallest = i;
		for (int j = i + 1; j < lengthArr; j++)
		{
			if (arrNumbers[j] < arrNumbers[indexSmallest])
			{
				indexSmallest = j;
			}
		}
		selectionSwapNumbers(arrNumbers, i, indexSmallest);
	}
}
