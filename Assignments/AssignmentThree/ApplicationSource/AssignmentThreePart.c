#include "AssignmentThreePart.h"

// Function to initialize blank part
Part* initializeBlankPart(void)
{
	Part part;
	Part* pntPart = malloc(sizeof(Part));
	*pntPart = part;
	return pntPart;
}

// Function to initialize detailed part
Part* initializeDetailedPart(int partNumber, char* partName, int partQuantity)
{
	Part part;
	Part* pntPart = malloc(sizeof(Part));
	*pntPart = part;
	
	setPartNumber(pntPart, partNumber);
	setPartName(pntPart, partName);
	setPartQuantity(pntPart, partQuantity);
	
	return pntPart;
}

// Function to get part number field
int getPartNumber(Part* pntPart)
{
	return pntPart -> intPartNumber;
}

// Function to get part quantity field
int getPartQuantity(Part* pntPart)
{
	return pntPart -> intPartQuantity;
}

// Function to get part name field
char* getPartName(Part* pntPart)
{
	return pntPart -> strPartName;
}

// Function to set part number field
void setPartNumber(Part* pntPart, int partNumber)
{
	pntPart -> intPartNumber = partNumber;
}

// Function to set part quantity field
void setPartQuantity(Part* pntPart, int partQuantity)
{
	pntPart -> intPartQuantity = partQuantity;
}

// Function to set part name field
void setPartName(Part* pntPart, char* partName)
{
	strncpy(pntPart -> strPartName, partName, PART_NAME_MAX_LENGTH);
}

