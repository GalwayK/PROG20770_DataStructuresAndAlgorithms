#include "Test3Review_BinaryTrees.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void swapNumbers(int* numberOne, int* numberTwo)
{
	int temp = *numberOne; 
	*numberOne = *numberTwo; 
	*numberTwo = temp;
}

NumberNode* initializeBlankNumberNode()
{
	NumberNode numberNode; 
	NumberNode* pntNumberNode = malloc(sizeof(NumberNode));
	*pntNumberNode = numberNode; 
	
	pntNumberNode -> pntLeftNode = NULL; 
	pntNumberNode -> pntRightNode = NULL; 
	pntNumberNode -> numberData = 0;
	
	return pntNumberNode; 
}

NumberNode* initializeDetailedNumberNode(int numberData)
{
	NumberNode* pntNumberNode = initializeBlankNumberNode();
	
	pntNumberNode -> numberData = numberData;
	
	return pntNumberNode; 
}

NumberTree* initializeNumberTree()
{
	NumberTree numberTree; 
	NumberTree* pntNumberTree = calloc(1, sizeof(NumberTree));
	
	*pntNumberTree = numberTree; 
	
	pntNumberTree -> pntRoot = NULL; 
	
	return pntNumberTree;
}

int countBinaryTreeNodes(NumberTree* pntBinaryTree)
{
	int countNodes = 0; 
	int* pntCountNodes = &countNodes; 
	countNumberNode(pntBinaryTree -> pntRoot, pntCountNodes);
	return countNodes;
}

void countNumberNode(NumberNode* pntNumberNode, int* pntCount)
{
	if (pntNumberNode == NULL)
	{
		return;
	}
	else 
	{
		*pntCount = *pntCount + 1;
		printf("Found node, count: %d\n", *pntCount);
	}
	
	countNumberNode(pntNumberNode -> pntLeftNode, pntCount);
	countNumberNode(pntNumberNode -> pntRightNode, pntCount);
	
}

void insertNumberIntoTree(NumberTree* pntNumberTree, int number)
{
	if (pntNumberTree -> pntRoot == NULL)
	{
		pntNumberTree -> pntRoot = initializeDetailedNumberNode(number);
	}
	else 
	{
		insertNumberIntoNode(&pntNumberTree -> pntRoot, number);
	}
}

bool isNumberNodeFull(NumberNode* pntNumberNode)
{
	return pntNumberNode -> pntLeftNode != NULL && pntNumberNode -> pntRightNode != NULL;
}

void insertNumberIntoNode(NumberNode** numberNode, int number)
{
	NumberNode* pntNumberNode = *numberNode;
	if (pntNumberNode == NULL)
	{
		*numberNode = initializeDetailedNumberNode(number);
		return;
	}
	else if (pntNumberNode -> numberData == number)
	{
		return;
	}
	else if (pntNumberNode -> numberData < number)
	{
		insertNumberIntoNode(&pntNumberNode -> pntRightNode, number);
	}
	else if (pntNumberNode -> numberData > number)
	{
		insertNumberIntoNode(&pntNumberNode -> pntLeftNode, number);
	}
	else 
	{
		printf("%s", "This should not be possible...\n");
	}
	
}

void printNumberNode(NumberNode* pntNumberNode, int numDepth, int* pntCount)
{
	if (pntNumberNode == NULL)
	{
		puts("Error: Empty leaf!");
	}
	else 
	{
		printf("Data: %d\tDepth: %d\tCount: %d\n", 
			pntNumberNode -> numberData, 
			numDepth, 
			(*pntCount)++);
	}
}

void printInOrderTreeTraversal(NumberTree* pntNumberTree)
{
	int numDepth = 1; 
	int numCount = 1; 
	int* pntCount = &numCount;
	
	puts("\nPrinting Tree In Order!");
	printInOrderNodeTraversal(pntNumberTree -> pntRoot, numDepth, pntCount);
}

void printInOrderNodeTraversal(NumberNode* pntNumberNode, int numDepth, int* pntCount)
{
	if (pntNumberNode == NULL)
	{
		return;
	}
	
	printInOrderNodeTraversal(pntNumberNode -> pntLeftNode, numDepth + 1, pntCount);
	printNumberNode(pntNumberNode, numDepth, pntCount);
	printInOrderNodeTraversal(pntNumberNode -> pntRightNode, numDepth + 1, pntCount);
}

void printPostOrderTreeTraversal(NumberTree* pntNumberTree)
{
	int numDepth = 1; 
	int numCount = 1; 
	int* pntCount = &numCount;
	
	puts("\nPrinting Tree Post Order!");
	printPostOrderNodeTraversal(pntNumberTree -> pntRoot, numDepth, pntCount);
}

void printPostOrderNodeTraversal(NumberNode* pntNumberNode, int numDepth, int* pntCount)
{
	if (pntNumberNode == NULL)
	{
		return;
	}
	
	printPostOrderNodeTraversal(pntNumberNode -> pntLeftNode, numDepth + 1, pntCount);
	printPostOrderNodeTraversal(pntNumberNode -> pntRightNode, numDepth + 1, pntCount);
	printNumberNode(pntNumberNode, numDepth, pntCount);
}

void printPreOrderTreeTraversal(NumberTree* pntNumberTree)
{
	int numDepth = 1; 
	int numCount = 1; 
	int* pntCount = &numCount;
	
	puts("\nPrinting Tree Pre Order!");
	printPreOrderNodeTraversal(pntNumberTree -> pntRoot, numDepth, pntCount);
}

void printPreOrderNodeTraversal(NumberNode* pntNumberNode, int numDepth, int* pntCount)
{
	if (pntNumberNode == NULL)
	{
		return;
	}
	
	printNumberNode(pntNumberNode, numDepth, pntCount);
	printPostOrderNodeTraversal(pntNumberNode -> pntLeftNode, numDepth + 1, pntCount);
	printPostOrderNodeTraversal(pntNumberNode -> pntRightNode, numDepth + 1, pntCount);
}

int searchNumberNodeForNumber(NumberNode* pntNumberNode, int searchNumber, int depth)
{
	if (pntNumberNode == NULL)
	{
		return -1;
	}
	else if (pntNumberNode -> numberData == searchNumber)
	{
		return depth;
	}
	else if (pntNumberNode -> numberData > searchNumber)
	{
		return searchNumberNodeForNumber(pntNumberNode -> pntLeftNode, searchNumber, depth + 1);
	}
	else if (pntNumberNode -> numberData < searchNumber)
	{
		return searchNumberNodeForNumber(pntNumberNode -> pntRightNode, searchNumber, depth + 1);
	}
	else 
	{
		puts("This should not be possible...");
		return -1;
	}
	
}

int searchBinaryTreeForNumber(NumberTree* pntNumberTree, int searchNumber)
{
	int depth = 1;
	searchNumberNodeForNumber(pntNumberTree -> pntRoot, searchNumber, depth);
}

