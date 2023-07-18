#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "AssignmentThreeInventory.h"
#define DEFAULT_INPUT_NUMBER -1
#define DEFAULT_INPUT_CHAR '\0'

void runAssignmentOne(void);

void selectInsertNewPart(char* pntString, InventoryList** pntInventoryList);

void selectPrintPart(InventoryList** pntInventoryList);

void selectPrintInventory(InventoryList* inventoryList);

void selectUpdatePartQuantity(InventoryList** pntInventoryList);

void selectCloseProgram(InventoryList** pntInventoryList);

Part* getPartWithInputPartNumber(InventoryList** pntInventoryList);

int* getIntInput(int* pntInteger, char* strPrompt);

char* convertCharToUppercase(char* pntChar);

char* getCharInput(char* pntChar, char* strPrompt);

char* getStringInput(char* pntString, char* strPrompt);

void insertNewPart(char* pntString);

void printHeader(void);

void printPart(Part* pntPart);

void printOptions(void);

void printInventory(InventoryList* inventoryList);

int main(int argCount, char** argStrings) 
{
	runAssignmentOne();
	return 0;
}

void runAssignmentOne(void)
{
	char pntStrInput[PART_NAME_MAX_LENGTH];
	
	char charInput = DEFAULT_INPUT_CHAR;
	char* pntCharInput = &charInput;
	
	InventoryList* inventoryList = initializeInventoryList();
	InventoryList** pntInventoryList = &inventoryList;
	
	puts("Welcome to the Parts Database Tracking Application by Kyle Galway!");
	bool isProgramActive = true;
	while (isProgramActive)
	{
		printHeader();
		printOptions();
		getCharInput(pntCharInput, "Please select an option: ");
		printHeader();
		printf("You have entered: %c\n", charInput);
		
		switch (charInput)
		{
			case '1':
			case 'I': 
				selectInsertNewPart(pntStrInput, pntInventoryList);
				break;
			case '2':
			case 'S': 
				selectPrintPart(pntInventoryList);
				break;
			case '3':
			case 'P': 
				selectPrintInventory(inventoryList);
				break;
			case '4':
			case 'U': 
				selectUpdatePartQuantity(pntInventoryList);
				break;
			case '5':
			case 'Q': 
				selectCloseProgram(pntInventoryList);
				isProgramActive = false;
				break;
			default: 
				puts("Error: Please select a valid option!");
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

Part* getPartWithInputPartNumber(InventoryList** pntInventoryList)
{
	int partNumber = DEFAULT_INPUT_NUMBER;
	getIntInput(&partNumber, "Please enter the part number: ");
	
	Part* part = searchInventoryListForPartByPartNumber(pntInventoryList, partNumber);
	return part;
}

void selectPrintPart(InventoryList** pntInventoryList)
{
	Part* part = getPartWithInputPartNumber(pntInventoryList);
	
	if (part == NULL)
	{
		puts("Error: Part number is not present in database!");
	}
	else 
	{
		puts("Found part!");
		printPart(part);
	}
}

void selectPrintInventory(InventoryList* inventoryList)
{
	printInventory(inventoryList);
}

void selectUpdatePartQuantity(InventoryList** pntInventoryList)
{
	Part* part = getPartWithInputPartNumber(pntInventoryList);
	
	if (part == NULL)
	{
		puts("Error: Part number is not present in database!");
	}
	else 
	{
		puts("Found part!");
		printPart(part);
		
		int partQuantity = DEFAULT_INPUT_NUMBER;
		getIntInput(&partQuantity, "Please enter the updated quantity: ");
		
		setPartQuantity(part, partQuantity);
		puts("Updated part quantity!");
		printPart(part);
	}
}

void selectCloseProgram(InventoryList** pntInventoryList)
{
	puts("Deallocating memory...");
	freeAllInventoryListMemory(pntInventoryList);
	puts("Memory deallocated!");
	puts("Thank you for using the Parts Database Tracking Application by Kyle Galway!");
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
	puts("1. Add New Part (1 or I)\n"
		"2. Display Part Information (2 or S)\n"
		"3. Display All Part Information (3 or P)\n"
		"4. Update Part Quantity (4 or U)\n"
		"5. Close program (5 or Q)\n");
}


int* getIntInput(int* pntInteger, char* strPrompt)
{
	printf("%s", strPrompt);
	fflush(stdin);
	int numResult = scanf("%d", pntInteger);
	
	if (numResult == 0 || *pntInteger < 0)
	{
		puts("Error, please enter a positive integer!");
		getIntInput(pntInteger, strPrompt);
	}
	return pntInteger;
}

char* convertCharToUppercase(char* pntChar)
{
	if (*pntChar >= 97 && *pntChar <= 121)
	{
		*pntChar = *pntChar - 32;
	}
	return pntChar;
}

char* getCharInput(char* pntChar, char* strPrompt)
{
	printf("%s", strPrompt);
	fflush(stdin);
	*pntChar = getchar();
	return pntChar;
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
	return pntString;
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
