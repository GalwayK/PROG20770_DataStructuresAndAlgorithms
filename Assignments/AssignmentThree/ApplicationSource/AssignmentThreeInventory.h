#include "AssignmentThreePart.h"
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

// GenericList structure which can be used to contain any data type
typedef struct GenericList 
{
	struct GenericList* pntNextNode;
	void* pntData;
} GenericList;

// Alias for GenericList to contain specifically Part structure data
typedef GenericList InventoryList;

// Function Prototypes

// Function to intialize default list as NULL
InventoryList* initializeInventoryList(void);

// Functon to initialize blank Inventory Node with data as NULL pointer
InventoryList* initializeBlankInventoryNode(void);

// Function to initialize detailed Ineentory Node with data as Part pointer
InventoryList* initializeDetailedInventoryNode(Part* part);

// Function to compare two nodes by Part Number within Part Pointer
bool isPartGreater(InventoryList* pntNodeOne, InventoryList* pntNodeTwo);

// Function to retrieve Part pointer from Node by casting void pointer to Part
Part* getPartFromInventoryNode(InventoryList* pntInventoryNode);

// Function to search Inventory for Part by Part Number 
Part* searchInventoryListForPartByPartNumber(InventoryList** pntInventoryList, 
	int partNumber);
	
// Function to delete a Part from Inventory if Inventory contains Part
void deletePartFromInventoryList(InventoryList** pntInventoryList, Part* part);

// Function for Inserting part into Inventory ordered by Part Number
void insertPartIntoInventory(InventoryList** pntInventoryList, 
	int partNumber, char* partName, int partQuantity);
	
// Function for clearing Inventory List by freeing allocated memory
void freeAllInventoryListMemory(InventoryList** pntInventoryList);


