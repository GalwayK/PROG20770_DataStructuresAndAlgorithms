#include <stdio.h>
#include <stdlib.h>
#include "Test3Review_BubbleSort.h"
#include "Test3Review_SelectionSort.h"
#include "Test3Review_InsertionSort.h"
#include "Test3Review_HeapSort.h"
#include "Test3Review_QuickSort.h"
#include "Test3Review_ShellSort.h"
#include "Test3Review_Searching.h"
#include "Test3Review_AutoSort.h"
#include "Test3Review_BinaryTrees.h"
#define LENGTH_ARRAY 10

// Function Declarations 

void printNumberArray(int* arrNumbers, int lengthArr);

void printPointerArray(int** arrNumbers, int lengthArr);

// Review Exercises to Complete

// Done
void reviewBubbleSortNumberArray(int* arrNumbers, int lengthArr);

// Done
void reviewBubbleSortPointerArray(int** arrPointers, int lengthArr);

// Done
void reviewSelectionSortNumberArray(int* arrNumbers, int lengthArr);

// Done
void reviewSelectionSortPointerArray(int** arrPointers, int lengthArr);

// Done
void reviewInsertionSortNumberArray(int* arrNumbers, int lengthArr);

// Done
void reviewInsertionSortPointerArray(int** arrPointers, int lengthArr);

// Done
void reviewQuickSortNumberArray(int* arrNumbers, int lengthArr);

// Done
void reviewQuickSortPointerArray(int** arrPointers, int lengthArr);

// Done
void reviewHeapSortNumberArray(int* arrNumbers, int lengthArr);

// Done
void reviewHeapSortPointerArray(int** arrPointers, int lengthArr);

// Done
void reviewShellSortNumberArray(int* arrNumbers, int lengthArr);

// Done
void reviewShellSortPointerArray(int** arrPointers, int lengthArr);

// Done 
void reviewAutoSortNumberArray(int* arrNumbers, int lengthArr);

// Done
void reviewAutoSortPointerArray(int** arrPointers, int lengthArr);

// Done
NumberTree* reviewBinaryTreeCreation();

// Done
void reviewBinaryTreeInsertion(NumberTree* pntNumberTree, int* arrNumbers, int lengthArr);

void reviewBinaryTreeBuilding();

// Done
void reviewBinaryTreeInOrderTraversal(NumberTree* pntNumberTree);

// Done
void reviewBinaryTreePreOrderTraversal(NumberTree* pntNumberTree);

// Done
void reviewBinaryTreePostOrderTraversal(NumberTree* pntNumberTree);

// Done
void reviewBinaryTreeSearching(NumberTree* pntNumberTree);

// Done
void reviewBinaryTreeCounting(NumberTree* pntNumberTree);

void reviewBubbleSortLinkList();

// Done
void reviewLinearSearchNumberArray(int* arrNumbers, int lengthArr);

// Done
void reviewLinearSearchPointerArray(int** arrPointers, int lengthArr);

// Done
void reviewBinarySearchNumberArray(int* arrNumbers, int lengthArr);

// Done
void reviewBinarySearchPointerArray(int** arrPointers, int lengthArr);

int** generatePointerArray(int* arrNumbers, int lengthArr);

int* generateNumberArray(int lengthArr);

// Function Implementations

int* generateNumberArray(int lengthArr)
{
	int* arrNumbers = malloc(sizeof(int) *  lengthArr);
	for (int i = lengthArr - 1; i >= 0; i--)
	{
		arrNumbers[i] = i;
	}
	return arrNumbers;
}

int main(int argCount, char** argStrings) 
{
	int lengthArr = LENGTH_ARRAY;
	int arrNumbers[] = {5, 9, 8, 7, 6, 1, 2, 3, 4, 0};
	
	int** arrPointers = malloc(sizeof(int*) * lengthArr);
	
	for (int i = 0; i < lengthArr; i++)
	{
		arrPointers[i] = &arrNumbers[i];
	}
	
//	puts("Unsorted Number Array!");
//	printNumberArray(arrNumbers, lengthArr);

//	puts("Unsorted Pointer Array!");
//	printPointerArray(arrPointers, lengthArr);
	
//	puts("\nSorting Pointer Array!");
//	reviewAutoSortPointerArray(arrPointers, lengthArr);
//	reviewInsertionSortPointerArray(arrPointers, lengthArr);
//	reviewSelectionSortPointerArray(arrPointers, lengthArr);
//	reviewBubbleSortPointerArray(arrPointers, lengthArr);
//	reviewQuickSortPointerArray(arrPointers, lengthArr);
//	reviewShellSortPointerArray(arrPointers, lengthArr);
//	reviewHeapSortPointerArray(arrPointers, lengthArr);

//	puts("\nSorting Number Array!");	
//	reviewAutoSortNumberArray(arrNumbers, lengthArr);
//	reviewInsertionSortNumberArray(arrNumbers, lengthArr);	
//	reviewSelectionSortNumberArray(arrNumbers, lengthArr);
//	reviewBubbleSortNumberArray(arrNumbers, lengthArr);
//	reviewQuickSortNumberArray(arrNumbers, lengthArr);
//	reviewShellSortNumberArray(arrNumbers, lengthArr);
//	reviewHeapSortNumberArray(arrNumbers, lengthArr);

//	puts("\nSorted Number Array!");
//	printNumberArray(arrNumbers, lengthArr);
	
//	puts("\nSorted Pointer Array!");
//	printPointerArray(arrPointers, lengthArr);
	
//	puts("\nSearching Number Array!");
//  reviewLinearSearchNumberArray(arrNumbers, lengthArr);
//	reviewBinarySearchNumberArray(arrNumbers, lengthArr);

//	puts("\nSearching Pointer Array!");
//	reviewLinearSearchPointerArray(arrPointers, lengthArr);
//	reviewBinarySearchPointerArray(arrPointers, lengthArr);

//	puts("\nReviewing Binary Trees!");
//	NumberTree* pntNumberTree = reviewBinaryTreeCreation();
//	reviewBinaryTreeInsertion(pntNumberTree, arrNumbers, lengthArr);
//	reviewBinaryTreeInOrderTraversal(pntNumberTree);
//	reviewBinaryTreePostOrderTraversal(pntNumberTree);
//	reviewBinaryTreePreOrderTraversal(pntNumberTree);
//	reviewBinaryTreeSearching(pntNumberTree);
//	reviewBinaryTreeCounting(pntNumberTree);

	return 0;
}

void reviewBinaryTreeCounting(NumberTree* pntNumberTree)
{
	int countNodes = countBinaryTreeNodes(pntNumberTree);
	printf("The tree has %d nodes!\n", countNodes);
	return;
}

void reviewBinaryTreeSearching(NumberTree* pntNumberTree)
{
	int searchNumber = -1;
	int countInputs = 0;
	while (countInputs == 0)
	{
		printf("Please enter a number: ");
		countInputs = scanf("%d", &searchNumber);
	}
	
	int indexNum = searchBinaryTreeForNumber(pntNumberTree, searchNumber);
	if (indexNum == -1)
	{
		puts("Error, number not found!");
	}
	else 
	{
		printf("%d is located at depth %d!\n", 	
			searchNumber, indexNum);
	}
	return;	
}

NumberTree* reviewBinaryTreeCreation()
{
	return initializeNumberTree();
}

void reviewBinaryTreeInsertion(NumberTree* pntNumberTree, int* arrNumbers, int lengthArr)
{
	for (int i = 0; i < lengthArr; i++)
	{
		insertNumberIntoTree(pntNumberTree, arrNumbers[i]);
	}
}

void reviewBinaryTreeInOrderTraversal(NumberTree* pntNumberTree)
{
	printInOrderTreeTraversal(pntNumberTree);
	return;
}

void reviewBinaryTreePreOrderTraversal(NumberTree* pntNumberTree)
{
	printPreOrderTreeTraversal(pntNumberTree);
	return;
}

void reviewBinaryTreePostOrderTraversal(NumberTree* pntNumberTree)
{
	printPostOrderTreeTraversal(pntNumberTree);
	return;
}

void reviewBinaryTreeBuilding()
{
	
}


void reviewHeapSortNumberArray(int* arrNumbers, int lengthArr)
{
	heapSortNumberArray(arrNumbers, lengthArr);
}

void reviewHeapSortPointerArray(int** arrPointers, int lengthArr)
{
	heapSortPointerArray(arrPointers, lengthArr);
}

void reviewShellSortPointerArray(int** arrPointers, int lengthArr)
{
	shellSortPointerArray(arrPointers, lengthArr);
}

void reviewShellSortNumberArray(int* arrNumbers, int lengthArr)
{
	shellSortNumberArray(arrNumbers, lengthArr);
}

void reviewAutoSortPointerArray(int** arrPointers, int lengthArr)
{
	autoSortPointerArray(arrPointers, lengthArr);
}

void reviewAutoSortNumberArray(int* arrNumbers, int lengthArr)
{
	autoSortNumberArray(arrNumbers, lengthArr);
}

void reviewBinarySearchNumberArray(int* arrNumbers, int lengthArr)
{
	int searchNumber = -1;
	int countInputs = 0;
	while (countInputs == 0)
	{
		printf("Please enter a number: ");
		countInputs = scanf("%d", &searchNumber);
	}
	
	int indexNum = binarySearchNumberArray(arrNumbers, 0, lengthArr - 1, searchNumber);
	if (indexNum == -1)
	{
		puts("Error, number not found!");
	}
	else 
	{
		printf("%d is located at index %d!\n", 	
			searchNumber, indexNum);
	}
}

void reviewBinarySearchPointerArray(int** arrPointers, int lengthArr)
{
	int searchNumber = -1;
	int countInputs = 0;
	while (countInputs == 0)
	{
		printf("Please enter a number: ");
		countInputs = scanf("%d", &searchNumber);
	}
	
	int indexNum = binarySearchPointerArray(arrPointers, 0, lengthArr - 1, searchNumber);
	if (indexNum == -1)
	{
		puts("Error, number not found!");
	}
	else 
	{
		printf("%d is located at index %d!\n", 	
			searchNumber, indexNum);
	}
	return;	
}

void reviewLinearSearchNumberArray(int* arrNumbers, int lengthArr)
{
	int searchNumber = -1;
	int countInputs = 0;
	while (countInputs == 0)
	{
		printf("Please enter a number: ");
		countInputs = scanf("%d", &searchNumber);
	}
	
	int indexNum = linearSearchNumberArray(arrNumbers, lengthArr, searchNumber);
	if (indexNum == -1)
	{
		puts("Error, number not found!");
	}
	else 
	{
		printf("%d is located at index %d!\n", 	
			searchNumber, indexNum);
	}
	return;
}

void reviewLinearSearchPointerArray(int** arrPointers, int lengthArr)
{
	int searchNumber = -1;
	int countInputs = 0;
	while (countInputs == 0)
	{
		printf("Please enter a number: ");
		countInputs = scanf("%d", &searchNumber);
	}
	
	int indexNum = linearSearchPointerArray(arrPointers, lengthArr, searchNumber);
	if (indexNum == -1)
	{
		puts("Error, number not found!");
	}
	else 
	{
		printf("%d is located at index %d!\n", 	
			searchNumber, indexNum);
	}
	return;	
}

void reviewQuickSortNumberArray(int* arrNumbers, int lengthArr)
{
	quickSortNumberArray(arrNumbers, 0, lengthArr - 1);
}

void reviewQuickSortPointerArray(int** arrPointers, int lengthArr)
{
	quickSortPointerArray(arrPointers, 0, lengthArr - 1);
}

void reviewInsertionSortNumberArray(int* arrNumbers, int lengthArr)
{
	insertionSortNumberArray(arrNumbers, lengthArr);
}

void reviewInsertionSortPointerArray(int** arrPointers, int lengthArr)
{
	insertionSortPointerArray(arrPointers, lengthArr);
}

void reviewSelectionSortPointerArray(int** arrPointers, int lengthArr)
{
	selectionSortPointerArray(arrPointers, lengthArr);
}


void reviewSelectionSortNumberArray(int* arrNumbers, int lengthArr)
{
	selectionSortNumberArray(arrNumbers, lengthArr);
}

void reviewBubbleSortNumberArray(int* arrNumbers, int lengthArr)
{
	bubbleSortNumberArray(arrNumbers, lengthArr);

}

void reviewBubbleSortPointerArray(int** arrPointers, int lengthArr)
{
	bubbleSortPointerArray(arrPointers, lengthArr);
}

void printPointerArray(int** arrPointers, int lengthArr)
{
	puts("Printing Pointer Array!");
	for (int i = 0; i < lengthArr; i++)
	{
		printf("#%d: %d\n", i + 1, *(arrPointers[i]));
	}
	puts("Printing Complete!\n");
	return;
}

void printNumberArray(int* arrNumbers, int lengthArr)
{
	puts("Printing Number Array!");
	for (int i = 0; i < lengthArr; i++)
	{
		printf("#%d: %d\n", i + 1, arrNumbers[i]);
	}
	puts("Printing Complete!\n");
	return;
}

#undef LENGTH_ARRAY

