#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "AssignmentThreeInventory.h"
#define DEFAULT_INPUT_NUMBER -1
#define DEFAULT_INPUT_CHAR '\0'
#define LOWERCASE_RANGE_START 97
#define LOWERCASE_RANGE_END 122
#define UPPERCASE_LOWERCASE_DISTANCE 32

// Function Prototypes

// Function to run Assignment Three
void runAssignmentThree(void);

// Function when user selects to insert a new part
void selectInsertNewPart(char* pntString, InventoryList** pntInventoryList);

// Function when user selects to print a part
void selectPrintPart(InventoryList** pntInventoryList);

// Function when user selects to print entire inventory
void selectPrintInventory(InventoryList* inventoryList);

// Function when user selects to update a part's quantity
void selectUpdatePartQuantity(InventoryList** pntInventoryList);

// Function when user selects to delete a part
void selectDeletePart(InventoryList** pntInventoryList);

// Function when user selects to close the program
void selectCloseProgram(InventoryList** pntInventoryList);

// Function to retrieve a Part from Inventory by accepting quantity from input
Part* getPartWithInputPartNumber(InventoryList** pntInventoryList);

// Function to retrieve valid int input from user
int* getIntInput(int* pntInteger, char* strPrompt);

// Function for converting lowercase char to uppercase
char* convertCharToUppercase(char* pntChar);

// Function to retrieve valid char input from user
char* getCharInput(char* pntChar, char* strPrompt);

// Function to retrieve valid string input from user
char* getStringInput(char* pntString, char* strPrompt);

// Function to print section header for application output
void printHeader(void);

// Function to print data member of Part structure
void printPart(Part* pntPart);

// Function to print application options to user
void printOptions(void);

// Function to print entire contents of InventoryList 
void printInventory(InventoryList* inventoryList);

// Function Implementations

// Application entry point
int main(int argCount, char** argStrings) 
{
	runAssignmentThree();
	return 0;
}

// Function to run Assignment Three
void runAssignmentThree(void)
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
			case 'D': 
				selectDeletePart(pntInventoryList);
				break;
			case '6':
			case 'Q': 
				selectCloseProgram(pntInventoryList);
				isProgramActive = false;
				break;
			default: 
				puts("Error: Please select a valid option!");
		}
		
		charInput = DEFAULT_INPUT_CHAR;
	}
}

// Function when user selects to insert a new part
void selectInsertNewPart(char* pntString, InventoryList** pntInventoryList)
{
	printHeader();
	puts("Inserting new part...");
	int partNumber;
	int partQuantity;
	
	getIntInput(&partNumber, "Please enter the part number: ");

	getStringInput(pntString, "Please enter the part name: ");
	
	getIntInput(&partQuantity, "Please enter the part quantity: ");
	
	insertPartIntoInventory(pntInventoryList, partNumber, pntString, partQuantity);
}

// Function to retrieve a Part from Inventory by accepting quantity from input
Part* getPartWithInputPartNumber(InventoryList** pntInventoryList)
{
	int partNumber = DEFAULT_INPUT_NUMBER;
	getIntInput(&partNumber, "Please enter the part number: ");
	
	Part* part = searchInventoryListForPartByPartNumber(pntInventoryList, partNumber);
	return part;
}

// Function when user selects to print a part
void selectPrintPart(InventoryList** pntInventoryList)
{
	printHeader();
	puts("Printing part...");
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

// Function when user selects to print entire inventory
void selectPrintInventory(InventoryList* inventoryList)
{
	printInventory(inventoryList);
}

// Function when user selects to update a part's quantity
void selectUpdatePartQuantity(InventoryList** pntInventoryList)
{
	printHeader();
	puts("Updating part quantity...");
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

// Function when user selects to delete a part
void selectDeletePart(InventoryList** pntInventoryList)
{
	printHeader();
	puts("Deleting part...");
	Part* part = getPartWithInputPartNumber(pntInventoryList);
	
	if (part == NULL)
	{
		puts("Error: Part not in database!");
	}
	else 
	{
		puts("Part found, deleting from database...");
		deletePartFromInventoryList(pntInventoryList, part);
		puts("Part deleted!");
	}
}

// Function when user selects to close the program
void selectCloseProgram(InventoryList** pntInventoryList)
{
	printHeader();
	puts("Closing application...");
	puts("Deallocating memory...");
	freeAllInventoryListMemory(pntInventoryList);
	puts("Memory deallocated!");
	puts("Thank you for using the Parts Database Tracking Application by Kyle Galway!");
}


// Function to print entire contents of InventoryList 
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

// Function to print data member of Part structure
void printPart(Part* pntPart)
{	
	printf("\tPart Number: %d\n\tPart Quantity: %d\n\tPartName: %s\n", 
		getPartNumber(pntPart), 
		getPartQuantity(pntPart), 
		getPartName(pntPart));
}

// Function to print section header for application output
void printHeader(void)
{
	puts("====================");
}

// Function to print application options to user
void printOptions(void)
{
	puts("1. Add New Part (1 or I)\n"
		"2. Display Part Information (2 or S)\n"
		"3. Display All Part Information (3 or P)\n"
		"4. Update Part Quantity (4 or U)\n"
		"5. Delete Part (5 or D)\n"
		"6. Close program (5 or Q)\n");
}

// Function to retrieve valid int input from user
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

// Function for converting lowercase char to uppercase
char* convertCharToUppercase(char* pntChar)
{
	if (*pntChar >= LOWERCASE_RANGE_START && *pntChar <= LOWERCASE_RANGE_END)
	{
		*pntChar = *pntChar - UPPERCASE_LOWERCASE_DISTANCE;
	}
	return pntChar;
}

// Function to retrieve valid char input from user
char* getCharInput(char* pntChar, char* strPrompt)
{
	printf("%s", strPrompt);
	fflush(stdin);
	*pntChar = getchar();
	convertCharToUppercase(pntChar);
	return pntChar;
}

// Function to retrieve valid string input from user
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

#undef DEFAULT_INPUT_NUMBER
#undef DEFAULT_INPUT_CHAR
#undef UPPERCASE_RANGE_START
#undef UPPERCASE_RANGE_END
#undef UPPERCASE_LOWERCASE_DISTANCE
