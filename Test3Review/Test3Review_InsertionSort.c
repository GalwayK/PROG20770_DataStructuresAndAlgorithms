#include "Test3Review_InsertionSort.h"

void swapInsertionPointers(int** arrPointers, int indexOne, int indexTwo)
{
	int* temp = arrPointers[indexOne];
	arrPointers[indexOne] = arrPointers[indexTwo];
	arrPointers[indexTwo] = temp;
}

void insertionSwapNumbers(int* arrNumbers, int indexOne, int indexTwo)
{
	int temp = arrNumbers[indexOne];
	arrNumbers[indexOne] = arrNumbers[indexTwo];
	arrNumbers[indexTwo] = temp;
}

void insertionSortPointerArray(int** arrPointers, int lengthArr)
{
	for (int i = 1; i < lengthArr; i++)
	{
		int indexCurrent = i;
		while (indexCurrent > 0)
		{
			if (*arrPointers[indexCurrent] < *arrPointers[indexCurrent - 1])
			{
				swapInsertionPointers(arrPointers, indexCurrent, indexCurrent - 1);
				indexCurrent--;
			}
			else 
			{
				break;
			}
		}
	}
}

void insertionSortNumberArray(int* arrNumbers, int lengthArr)
{
	for (int i = 1; i < lengthArr; i++)
	{
		int tempIndex = i;
		
		while (tempIndex > 0)
		{
			if (arrNumbers[tempIndex] < arrNumbers[tempIndex - 1])
			{
				insertionSwapNumbers(arrNumbers, tempIndex, tempIndex - 1);
				tempIndex--;
			}
			else 
			{
				break;
			}
		}
	}
}
