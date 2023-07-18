#include "AssignmentThreeInventory.h"
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

InventoryList* initializeInventoryList()
{
	return NULL;
}

InventoryList* initializeBlankInventoryNode()
{
	InventoryList inventory;
	InventoryList* pntInventory = malloc(sizeof(InventoryList));
	*pntInventory = inventory;
	
	pntInventory -> pntPart = NULL;
	pntInventory -> pntNextNode = NULL;
	
	return pntInventory;
}

InventoryList* initializeDetailedInventoryNode(Part* part)
{
	InventoryList* pntInventory = initializeBlankInventoryNode();
	pntInventory -> pntPart = part;
	
	return pntInventory;
}

Part* getPartFromInventoryNode(InventoryList* pntInventoryNode)
{
	return (Part*)pntInventoryNode -> pntPart;
}

bool isPartGreater(InventoryList* pntNodeOne, InventoryList* pntNodeTwo)
{
	Part* pntPartOne = getPartFromInventoryNode(pntNodeOne);
	Part* pntPartTwo = getPartFromInventoryNode(pntNodeTwo);
	
	return pntPartOne -> intPartNumber > pntPartTwo -> intPartNumber;
}

void insertPartInOrder(InventoryList** pntInventoryList, Part* pntPart)
{
	InventoryList* pntInsertNode = initializeDetailedInventoryNode(pntPart);
	InventoryList* pntCurrentNode = *pntInventoryList;
	InventoryList* pntPreviousNode = NULL;
	
	// Implement sorted insert into inventory
	if (pntCurrentNode == NULL || isPartGreater(pntInsertNode, pntCurrentNode))
	{
		pntInsertNode -> pntNextNode = pntCurrentNode;
		*pntInventoryList = pntInsertNode;
	}
	else
	{
		while (pntCurrentNode -> pntNextNode != NULL)
		{
			if (isPartGreater(pntInsertNode, pntCurrentNode -> pntNextNode))
			{
				break;
			}
			pntCurrentNode = pntCurrentNode -> pntNextNode;
		}
		pntInsertNode -> pntNextNode = pntCurrentNode -> pntNextNode;
		pntCurrentNode -> pntNextNode = pntInsertNode;
	}
}

void insertPartIntoInventory(InventoryList** pntInventoryList, 
	int partNumber, char* partName, int partQuantity)
{
	Part* pntPart = initializeDetailedPart(partNumber, partName, partQuantity);
	InventoryList* pntInventoryNode = initializeDetailedInventoryNode(pntPart);
	
	insertPartInOrder(pntInventoryList, pntPart);
}

Part* searchInventoryListForPartByPartNumber(InventoryList** pntInventoryList, 
	int partNumber)
{
	InventoryList* pntCurrentNode = *pntInventoryList;
	while (pntCurrentNode != NULL)
	{
		if (getPartFromInventoryNode(pntCurrentNode) -> intPartNumber == partNumber)
		{
			break;
		}
		pntCurrentNode = pntCurrentNode -> pntNextNode;
	}
	return pntCurrentNode != NULL ? pntCurrentNode -> pntPart : NULL;
}

void freeAllInventoryListMemory(InventoryList** pntInventoryList)
{
	InventoryList* pntCurrentNode = *pntInventoryList;
	InventoryList* pntPreviousNode = NULL;
	
	while (pntCurrentNode != NULL)
	{
		pntPreviousNode = pntCurrentNode;
		pntCurrentNode = pntCurrentNode -> pntNextNode;
		free(pntPreviousNode);
	}
	
	*pntInventoryList = initializeInventoryList();
}


