#include "AssignmentThreeInventory.h"
#include<stdlib.h>
#include<stdbool.h>

InventoryList* initializeInventoryList()
{
	return NULL;
}

InventoryList* initializeBlankInventoryNode()
{
	InventoryList inventory;
	InventoryList* pntInventory = malloc(sizeof(InventoryList));
	*pntInventory = inventory;
	
	pntInventory -> pntNextNode = NULL;
	
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

InventoryList* initializeDetailedInventoryNode(Part* part)
{
	InventoryList* pntInventory = initializeBlankInventoryNode();
	pntInventory -> pntPart = part;
	
	return pntInventory;
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


