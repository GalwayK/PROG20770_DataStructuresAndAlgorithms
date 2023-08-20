#include "Test3Review_BubbleSort.h"

void bubbleSwapNumbers(int* arrNumbers, int indexOne, int indexTwo)
{
	int temp = arrNumbers[indexOne];
	arrNumbers[indexOne] = arrNumbers[indexTwo];
	arrNumbers[indexTwo] = temp;
}

void bubbleSwapPointers(int** arrPointers, int indexOne, int indexTwo)
{
	int* temp = arrPointers[indexOne];
	arrPointers[indexOne] = arrPointers[indexTwo];
	arrPointers[indexTwo] = temp;
}

void bubbleSortNumberArray(int* arrNumbers, int lengthArr)
{
	int indexFinal = lengthArr - 1;
	for (int i = 0; i < indexFinal; i++)
	{
		for (int j = 0; j < indexFinal - i; j++)
		{
			if (arrNumbers[j] > arrNumbers[j + 1])
			{
				bubbleSwapNumbers(arrNumbers, j, j + 1);
			}
		}
	}
}

void bubbleSortPointerArray(int** arrPointers, int lengthArr)
{
	for (int endIndex = lengthArr - 1; endIndex >= 0; endIndex --)
	{
		for (int currentIndex = 0; currentIndex < endIndex; currentIndex++)
		{
			if (*arrPointers[currentIndex] > *arrPointers[currentIndex + 1])
			{
				bubbleSwapPointers(arrPointers, currentIndex, currentIndex + 1);
			}
		}
	}
}
