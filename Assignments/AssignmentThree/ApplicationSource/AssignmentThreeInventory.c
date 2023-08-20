#include "AssignmentThreeInventory.h"

// Function to intialize default list as NULL
InventoryList* initializeInventoryList()
{
	return NULL;
}

// Functon to initialize blank Inventory Node with data as NULL pointer
InventoryList* initializeBlankInventoryNode()
{
	InventoryList inventory;
	InventoryList* pntInventory = malloc(sizeof(InventoryList));
	*pntInventory = inventory;
	
	pntInventory -> pntData = NULL;
	pntInventory -> pntNextNode = NULL;
	
	return pntInventory;
}

// Function to initialize detailed Ineentory Node with data as Part pointer
InventoryList* initializeDetailedInventoryNode(Part* part)
{
	InventoryList* pntInventory = initializeBlankInventoryNode();
	pntInventory -> pntData = part;
	
	return pntInventory;
}

// Function to compare two nodes by Part Number within Part Pointer
bool isPartGreater(InventoryList* pntNodeOne, InventoryList* pntNodeTwo)
{
	Part* pntPartOne = getPartFromInventoryNode(pntNodeOne);
	Part* pntPartTwo = getPartFromInventoryNode(pntNodeTwo);
	
	return pntPartOne -> intPartNumber > pntPartTwo -> intPartNumber;
}

// Function to retrieve Part pointer from Node by casting void pointer to Part
Part* getPartFromInventoryNode(InventoryList* pntInventoryNode)
{
	return (Part*)pntInventoryNode -> pntData;
}

// Function for Inserting part into Inventory ordered by Part Number
void insertPartInOrder(InventoryList** pntInventoryList, Part* pntPart)
{
	InventoryList* pntInsertNode = initializeDetailedInventoryNode(pntPart);
	InventoryList* pntCurrentNode = *pntInventoryList;
	
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

// Function for Inserting part into Inventory ordered by Part Number
void insertPartIntoInventory(InventoryList** pntInventoryList, 
	int partNumber, char* partName, int partQuantity)
{
	Part* pntPart = initializeDetailedPart(partNumber, partName, partQuantity);
	InventoryList* pntInventoryNode = initializeDetailedInventoryNode(pntPart);
	
	insertPartInOrder(pntInventoryList, pntPart);
}

// Function to delete a Part from Inventory if Inventory contains Part
void deletePartFromInventoryList(InventoryList** pntInventoryList, Part* part)
{
	int partNumber = part -> intPartNumber;
	InventoryList* pntCurrentNode = *pntInventoryList;
	if (pntCurrentNode != NULL && getPartFromInventoryNode(pntCurrentNode) 
		-> intPartNumber == partNumber)
	{
		*pntInventoryList = pntCurrentNode -> pntNextNode;
		free(pntCurrentNode);
	}
	else 
	{
		InventoryList* pntPreviousNode = NULL;
		while (pntCurrentNode -> pntNextNode != NULL)
		{
			pntPreviousNode = pntCurrentNode;
			pntCurrentNode = pntCurrentNode -> pntNextNode;
			
			if (getPartFromInventoryNode(pntCurrentNode) -> intPartNumber == partNumber)
			{
				pntPreviousNode -> pntNextNode = pntCurrentNode -> pntNextNode;
				free(pntCurrentNode); 
				break;
			}
		}
	}
}

// Function to search Inventory for Part by Part Number 
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
	return pntCurrentNode != NULL ? pntCurrentNode -> pntData : NULL;
}

// Function for clearing Inventory List by freeing allocated memory
void freeAllInventoryListMemory(InventoryList** pntInventoryList)
{
	InventoryList* pntCurrentNode = *pntInventoryList;
	InventoryList* pntPreviousNode = NULL;
	
	while (pntCurrentNode != NULL)
	{
		pntPreviousNode = pntCurrentNode;
		pntCurrentNode = pntCurrentNode -> pntNextNode;
		free(pntPreviousNode -> pntData);
		free(pntPreviousNode);
	}
	
	*pntInventoryList = initializeInventoryList();
}
