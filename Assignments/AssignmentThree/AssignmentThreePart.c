#include "AssignmentThreePart.h"
#include<stdlib.h>
#include<string.h>

Part* initializeBlankPart(void)
{
	Part part;
	Part* pntPart = malloc(sizeof(Part));
	*pntPart = part;
	return pntPart;
}

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

int getPartNumber(Part* pntPart)
{
	return pntPart -> intPartNumber;
}

int getPartQuantity(Part* pntPart)
{
	return pntPart -> intPartQuantity;
}

char* getPartName(Part* pntPart)
{
	return pntPart -> strPartName;
}

void setPartNumber(Part* pntPart, int partNumber)
{
	pntPart -> intPartNumber = partNumber;
}

void setPartQuantity(Part* pntPart, int partQuantity)
{
	pntPart -> intPartQuantity = partQuantity;
}

void setPartName(Part* pntPart, char* partName)
{
	strncpy(pntPart -> strPartName, partName, PART_NAME_MAX_LENGTH);
}

