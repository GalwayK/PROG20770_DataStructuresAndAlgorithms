#include "Test3Review_Searching.h"
#include <stdio.h>

int linearSearchNumberArray(int* arrNumbers, int lengthArr, int searchNumber)
{
	for (int i = 0; i < lengthArr; i++)
	{
		if (arrNumbers[i] == searchNumber)
		{
			return i;
		}
	}
	return -1;
}

int binarySearchNumberArray(int* arrNumbers, int startIndex, int endIndex, int searchNumber)
{	
	int currentIndex = (startIndex + endIndex) / 2;
	
	printf("Start Index: %d\n", startIndex);
	printf("End Index: %d\n", endIndex);
	printf("Current Index: %d\n", currentIndex);
	
	if (arrNumbers[currentIndex] == searchNumber)
	{
		return currentIndex;
	}
	else if (startIndex == endIndex)
	{
		return -1;
	}
	else if (arrNumbers[currentIndex] < searchNumber)
	{
		return binarySearchNumberArray(arrNumbers, currentIndex + 1, endIndex, searchNumber);
	}
	else 
	{
		return binarySearchNumberArray(arrNumbers, startIndex, currentIndex - 1, searchNumber);
	}
}

int linearSearchPointerArray(int** arrPointers, int lengthArr, int numberSearch)
{
	for (int i = 0; i < lengthArr; i++)
	{
		if (*arrPointers[i] == numberSearch)
		{
			return i;
		}
	}
	return -1;
}

int binarySearchPointerArray(int** arrPointers, int startIndex, int endIndex, int numberSearch)
{
	int splitIndex = (startIndex + endIndex) / 2;
	
	if (*arrPointers[splitIndex] == numberSearch)
	{
		return splitIndex;
	}
	else if (startIndex == endIndex)
	{
		return -1;
	}
	else if (*arrPointers[splitIndex] > numberSearch)
	{
		return binarySearchPointerArray(arrPointers, startIndex, splitIndex - 1, numberSearch);
	}
	else 
	{
		return binarySearchPointerArray(arrPointers, splitIndex + 1, endIndex, numberSearch);
	}
}
