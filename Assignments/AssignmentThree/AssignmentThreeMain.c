#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "AssignmentThreeInventory.h"
#define DEFAULT_INPUT_NUMBER -1

void runAssignmentOne(void);

void selectInsertNewPart(char* pntString, InventoryList** pntInventoryList);

void selectPrintPart(InventoryList** pntInventoryList);

void selectPrintInventory(InventoryList* inventoryList);

void selectUpdatePartNumber(InventoryList** pntInventoryList);

int* getIntInput(int* pntInteger, char* strPrompt);

char* getStringInput(char* pntString, char* strPrompt);

void insertNewPart(char* pntString);

void printHeader(void);

void printPart(Part* pntPart);

void printOptions(void);

void printInventory(InventoryList* inventoryList);

int main(int argCount, char** argStrings) 
{
	puts("Hello world!");
	runAssignmentOne();
	return 0;
}

void runAssignmentOne(void)
{
	char pntStrInput[PART_NAME_MAX_LENGTH];
	
	int numInput = -1;
	int* pntNumInput = &numInput;
	
	InventoryList* inventoryList = initializeInventoryList();
	InventoryList** pntInventoryList = &inventoryList;
	
	puts("Welcome to the Parts Database Organization Program!");
	bool isProgramActive = true;
	while (isProgramActive)
	{
		printHeader();
		printOptions();
		getIntInput(pntNumInput, "Please select an option: ");
		printHeader();
		printf("You have entered: %d\n", numInput);
		
		switch (numInput)
		{
			case 1: 
				selectInsertNewPart(pntStrInput, pntInventoryList);
				break;
			case 2: 
				selectPrintPart(pntInventoryList);
				break;
			case 3: 
				selectPrintInventory(inventoryList);
				break;
			case 4: 
				selectUpdatePartNumber(pntInventoryList);
			case 5: 
				isProgramActive = false;
				break;
		}
	}
}

void selectInsertNewPart(char* pntString, InventoryList** pntInventoryList)
{
	printHeader();
	printf("Inserting new part...");
	int partNumber;
	int partQuantity;
	
	getIntInput(&partNumber, "Please enter the part number: ");

	getStringInput(pntString, "Please enter the part name: ");
	
	getIntInput(&partQuantity, "Please enter the part quantity: ");
	
	insertPartIntoInventory(pntInventoryList, partNumber, pntString, partQuantity);
}

void selectPrintPart(InventoryList** pntInventoryList)
{
	
}

void selectPrintInventory(InventoryList* inventoryList)
{
	printInventory(inventoryList);
}

void selectUpdatePartNumber(InventoryList** pntInventoryList)
{
	
}

void printInventory(InventoryList* pntInventoryList)
{
	int numParts = 1;
	while (pntInventoryList != NULL)
	{
		printf("Printing part #%d\n", numParts++);
		printPart(getPartFromInventoryNode(pntInventoryList));
		pntInventoryList = pntInventoryList -> pntNextNode;
	}
}

void printPart(Part* pntPart)
{	
	printf("\tPart Number: %d\n\tPart Quantity: %d\n\tPartName: %s\n", 
		getPartNumber(pntPart), 
		getPartQuantity(pntPart), 
		getPartName(pntPart));
}

void printHeader(void)
{
	puts("====================");
}

void printOptions(void)
{
	puts("1. Add New Part\n"
		"2. Display Part Information\n"
		"3. Display All Part Information\n"
		"4. Update Part Quantity\n"
		"5. End program\n");
}


int* getIntInput(int* pntInteger, char* strPrompt)
{
	printf("%s", strPrompt);
	fflush(stdin);
	int numResult = scanf("%d", pntInteger);
	
	if (numResult == 0)
	{
		puts("Error, please enter an integer!");
		getIntInput(pntInteger, strPrompt);
	}
}

char* getStringInput(char* pntString, char* strPrompt)
{
	printf("%s", strPrompt);
	fflush(stdin);
	int numResult = scanf("%s", pntString);
	
	if (numResult == 0)
	{
		puts("Error, please enter a valid string!");
		getStringInput(pntString, strPrompt);
	}
}

/*
TODO: 

Add update quantity functionality 
Add search for inventory functionality 
Separate InventoryList into Generic Linked List 
Implement quitting application and clearing memory
Add status codes and messages to InventoryList
Implement character comparisons to select options


*/

//void testPartStruct(void)
//{
//	int partNumber;
//	int partQuantity;
//	char partName[255];
//	
//	printf("Max Length: %d\n", PART_NAME_MAX_LENGTH);
//	
//	Part* pntPart = initializeBlankPart();
//	
//	printf("Enter ID: ");
//	scanf("%d", &partNumber);
//	printf("Recorded ID: %d\n", partNumber);
//	printf("Enter quantity: ");
//	scanf("%d", &partQuantity);
//	printf("Enter name: ");
//	scanf("%s", partName);
//	
//	setPartNumber(pntPart, partNumber);
//	setPartQuantity(pntPart, partQuantity);
//	setPartName(pntPart, partName);
//		
//	Part* secondPart = initializeDetailedPart(partNumber, partName, partQuantity);
//
//	printPart(pntPart);
//	printPart(secondPart);
//}
//void testModules(void)
//{
//	testPartStruct();
//}
