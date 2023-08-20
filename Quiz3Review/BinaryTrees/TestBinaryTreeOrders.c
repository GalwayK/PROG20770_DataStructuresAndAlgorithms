#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct MyBinaryNode
{
	char strData[255];
	struct MyBinaryNode* pntLeftNode; 
	struct MyBinaryNode* pntRightNode; 
} MyBinaryNode;

typedef struct MyBinaryTree
{
	struct MyBinaryNode* pntRoot;
} MyBinaryTree;

void printNode(MyBinaryNode* pntBinaryNode, int depth);

void printBinaryTree(MyBinaryTree* pntBinaryTree);

MyBinaryNode* initializeBlankBinaryNode();

MyBinaryNode* initializeDetailedBinaryNode(char* strData);

MyBinaryNode* buildMyBinaryTree(FILE* in);

MyBinaryTree* initializeBlankBinaryTree();

void printSingleNode(MyBinaryNode* pntBinaryNode, int depth, int* order);

void printTreePreOrder(MyBinaryTree* pntBinaryTree);

void printTreeInOrder(MyBinaryTree* pntBinaryTree);

void printTreePostOrder(MyBinaryTree* pntBinaryTree);

void printNodePreOrder(MyBinaryNode* pntBinaryNode, int depth, int* order);

void printNodeInOrder(MyBinaryNode* pntBinaryNode, int depth, int* order);

void printNodePostOrder(MyBinaryNode* pntBinaryNode, int depth, int* order);

MyBinaryTree* initializeBlankBinaryTree()
{
	MyBinaryTree binaryTree;
	MyBinaryTree* pntBinaryTree = malloc(sizeof(MyBinaryTree));
	*pntBinaryTree = binaryTree;
	pntBinaryTree -> pntRoot = NULL;
	return pntBinaryTree;
}

MyBinaryNode* initializeBlankBinaryNode()
{
	MyBinaryNode binaryNode; 
	
	MyBinaryNode* pntBinaryNode = calloc(1, sizeof(MyBinaryNode));
	*pntBinaryNode = binaryNode;
	 
	pntBinaryNode -> pntLeftNode = NULL;
	pntBinaryNode -> pntRightNode = NULL;
	return pntBinaryNode;
}

MyBinaryNode* initializeDetailedBinaryNode(char* strData)
{
	MyBinaryNode* pntBinaryNode = initializeBlankBinaryNode();
	strcpy(pntBinaryNode -> strData, strData);
	return pntBinaryNode;
}

MyBinaryNode* buildMyBinaryTree(FILE* in)
{
	char strWord[255];
	int count = fscanf(in, "%s", strWord);
	
	if (count != 1 || strcmp(strWord, "@") == 0)
	{
		return NULL;
	}
	
	MyBinaryNode* pntCurrentNode = initializeDetailedBinaryNode(strWord);
	
	pntCurrentNode -> pntLeftNode = buildMyBinaryTree(in);
	pntCurrentNode -> pntRightNode = buildMyBinaryTree(in);
	return pntCurrentNode;
}

void printSingleNode(MyBinaryNode* pntBinaryNode, int depth, int* order)
{
	if (pntBinaryNode == NULL)
	{
		return;
	}
	
	printf("Word: %s Depth: %d Order: %d\n", pntBinaryNode -> strData, depth, *order);
	*order += 1;
}

void printNodePreOrder(MyBinaryNode* pntBinaryNode, int depth, int* order)
{
	if (pntBinaryNode == NULL)
	{
		return;
	}
	
	printSingleNode(pntBinaryNode, depth, order);
	depth = depth + 1;
	printNodePreOrder(pntBinaryNode -> pntLeftNode, depth, order);
	printNodePreOrder(pntBinaryNode -> pntRightNode, depth, order);
}

void printTreePreOrder(MyBinaryTree* pntBinaryTree)
{
	int order = 1;
	int* pntOrder = &order;
	printNodePreOrder(pntBinaryTree -> pntRoot, 1, pntOrder);
}

void printNodeInOrder(MyBinaryNode* pntBinaryNode, int depth, int* order)
{
	if (pntBinaryNode == NULL)
	{
		return;
	}

	printNodeInOrder(pntBinaryNode -> pntLeftNode, depth + 1, order);
	printSingleNode(pntBinaryNode, depth, order);
	printNodeInOrder(pntBinaryNode -> pntRightNode, depth + 1, order);
}

void printTreeInOrder(MyBinaryTree* pntBinaryTree)
{
	int order = 1;
	int* pntOrder = &order;
	printNodeInOrder(pntBinaryTree -> pntRoot, 1, pntOrder);
}

void printNodePostOrder(MyBinaryNode* pntBinaryNode, int depth, int* order)
{
	if (pntBinaryNode == NULL)
	{
		return;
	}
	
	printNodePostOrder(pntBinaryNode -> pntLeftNode, depth + 1, order);
	printNodePostOrder(pntBinaryNode -> pntRightNode, depth + 1, order);
	printSingleNode(pntBinaryNode, depth, order);
}

void printTreePostOrder(MyBinaryTree* pntBinaryTree)
{
	int order = 1;
	int* pntOrder = &order;
	printNodePostOrder(pntBinaryTree -> pntRoot, 1, pntOrder);
}


int main(int argCount, char** argStrings)
{
	FILE* fileInput = fopen("btree.txt", "r");
	MyBinaryTree* pntBinaryTree = initializeBlankBinaryTree();
	puts("Building Tree!");
	pntBinaryTree -> pntRoot = buildMyBinaryTree(fileInput);
	
	puts("\n Printing Pre Order!");
	printTreePreOrder(pntBinaryTree);
	
	puts("\nPrinting In Order!");
	printTreeInOrder(pntBinaryTree);
	
	puts("\nPrinting Post Order!");
	printTreePostOrder(pntBinaryTree);
	
	puts("Tree Testing Application Complete!");
}
