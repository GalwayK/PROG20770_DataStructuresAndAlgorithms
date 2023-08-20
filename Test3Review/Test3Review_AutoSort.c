#include <stdlib.h>
#include <stdio.h>

int compareNumbers(const void* numberOne, const void* numberTwo)
{
	return *(int*)numberOne - *(int*)numberTwo;
}

int comparePointers(const void* pointerOne, const void* pointerTwo)
{
	int** pointerNumOne = (int**)pointerOne;
	int** pointerNumTwo = (int**)pointerTwo;
	int numOne = **pointerNumOne;
	int numTwo = **pointerNumTwo;
	printf("Number One: %d\n", numOne);
	printf("Number One: %d\n", numTwo);
	printf("Returning %d\n\n", numOne - numTwo);
	
	return numOne - numTwo;
}

void autoSortNumberArray(int* arrNumbers, int lengthArr)
{
	qsort(arrNumbers, lengthArr, sizeof(int), compareNumbers);
}

void autoSortPointerArray(int** arrPointers, int lengthArr)
{
	qsort(arrPointers, lengthArr, sizeof(int*), comparePointers);
}
