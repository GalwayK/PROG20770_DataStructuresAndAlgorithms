#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct MyBinaryNode
{
	char chaLetter;
	struct MyBinaryNode* pntLeftNode; 
	struct MyBinaryNode* pntRightNode; 
} MyBinaryNode;

typedef struct MyBinaryTree
{
	struct MyBinaryNode* pntRoot;
} MyBinaryTree;

MyBinaryNode* initializeBlankBinaryNode();

MyBinaryNode* initializeDetailedBinaryNode(char chaLetter);

bool isBinaryNodeFull(MyBinaryNode* pntBinaryNode);

void addLetterToBinaryNode(MyBinaryNode* pntBinaryNode, char chaLetter);

void addLetterToBinaryTree(MyBinaryTree* pntBinaryTree, char chaLetter);

void printBinaryTree(MyBinaryTree* pntBinaryTree);

void printNode(MyBinaryNode* pntBinaryNode, int depth);

MyBinaryTree* initializeBlankBinaryTree();

MyBinaryTree* initializeBlankBinaryTree()
{
	MyBinaryTree myTree;
	myTree.pntRoot = NULL;
	MyBinaryTree* pntMyTree = &myTree;
	pntMyTree -> pntRoot = NULL;
	return pntMyTree;
}

MyBinaryNode* initializeBlankBinaryNode()
{
	MyBinaryNode binaryNode; 
	
	MyBinaryNode* pntBinaryNode = malloc(sizeof(MyBinaryNode));
	*pntBinaryNode = binaryNode;
	
	pntBinaryNode -> chaLetter = '\0';
	pntBinaryNode -> pntLeftNode = NULL;
	pntBinaryNode -> pntRightNode = NULL;
	return pntBinaryNode;
}

MyBinaryNode* initializeDetailedBinaryNode(char chaLetter)
{
	MyBinaryNode* pntBinaryNode = initializeBlankBinaryNode();
	pntBinaryNode -> chaLetter = chaLetter;
	return pntBinaryNode;
}

bool isBinaryNodeFull(MyBinaryNode* pntBinaryNode)
{
	return pntBinaryNode -> pntLeftNode != NULL && pntBinaryNode -> pntRightNode != NULL;
}

void addLetterToBinaryTree(MyBinaryTree* pntBinaryTree, char chaLetter)
{
	if (pntBinaryTree -> pntRoot == NULL)
	{
		puts("Filling root node!");
		pntBinaryTree -> pntRoot = initializeDetailedBinaryNode(chaLetter);
	}
	else 
	{
		addLetterToBinaryNode(pntBinaryTree -> pntRoot, chaLetter);
	}
}

void addLetterToBinaryNode(MyBinaryNode* pntBinaryNode, char chaLetter)
{
	if (pntBinaryNode -> chaLetter == '\0')
	{
		pntBinaryNode -> chaLetter = chaLetter;
	}
	else 
	{
		if (pntBinaryNode -> pntLeftNode == NULL)
		{
			pntBinaryNode -> pntLeftNode = initializeDetailedBinaryNode(chaLetter);
		}
		else if (pntBinaryNode -> pntRightNode == NULL)
		{
			pntBinaryNode -> pntRightNode = initializeDetailedBinaryNode(chaLetter);
		}
		else 
		{
			if (isBinaryNodeFull(pntBinaryNode -> pntLeftNode))
			{
				if (isBinaryNodeFull(pntBinaryNode -> pntRightNode))
				{
					addLetterToBinaryNode(pntBinaryNode -> pntLeftNode, chaLetter);
				}
				else 
				{
					addLetterToBinaryNode(pntBinaryNode -> pntRightNode, chaLetter);
				}
			}
		}
	}
}

void printNode(MyBinaryNode* pntBinaryNode, int depth)
{
	if (pntBinaryNode == NULL)
	{
		puts("End of Tree");
		return;
	}
	
	printf("Depth: %d\n", depth);
	printf("Data: %c\n", pntBinaryNode -> chaLetter);
	printNode(pntBinaryNode -> pntLeftNode, depth + 1);
	printNode(pntBinaryNode -> pntRightNode, depth + 1);
}

void printBinaryTree(MyBinaryTree* pntBinaryTree)
{
	printNode(pntBinaryTree -> pntRoot, 1);
}

int main(int argCount, char** argStrings)
{
	MyBinaryTree* pntBinaryTree = initializeBlankBinaryTree();
	addLetterToBinaryTree(pntBinaryTree, 'A');
//	printBinaryTree(pntBinaryTree);
	
	addLetterToBinaryTree(pntBinaryTree, 'B');
//	printBinaryTree(pntBinaryTree);
	
	addLetterToBinaryTree(pntBinaryTree, 'C');
	printBinaryTree(pntBinaryTree);
	printf("%s", "Learning Binary Trees!\n");
}
