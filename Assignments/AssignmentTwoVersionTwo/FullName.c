#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "FullName.h"

FullName* initializeFullName()
{
	FullName fullName;
	FullName* pntFullName = calloc(1, sizeof(FullName));
	*pntFullName = fullName;
	return pntFullName;
}

char* getFirstName(FullName* pntFullName)
{
	return pntFullName -> firstName;
}

char* getLastName(FullName* pntFullName)
{
	return pntFullName -> lastName;
}

void setFirstName(FullName* pntFullName, char* strFirstName)
{
	strncpy(pntFullName -> firstName, strFirstName, MAX_NAME_LENGTH);
}

void setLastName(FullName* pntFullName, char* strLastName)
{
	strncpy(pntFullName -> lastName, strLastName, MAX_NAME_LENGTH);
}

void freeFullName(FullName** pntPntFullName)
{
	FullName* pntFullName = *pntPntFullName;
	free(pntFullName);
}

int compareNames(FullName* pntFirstName, FullName* pntSecondName)
{
	int numCompare = strncmp(pntFirstName -> firstName, 
		pntSecondName -> firstName, 
		MAX_NAME_LENGTH);
		
	if (numCompare == 0)
	{
		numCompare = strncmp(pntFirstName -> lastName, 
		pntSecondName -> lastName, 
		MAX_NAME_LENGTH);
	}
	return numCompare;
}

FullName* createFullName(char* strFirstName, char* strLastName)
{
	FullName* pntFullName = initializeFullName();
	setFirstName(pntFullName, strFirstName);
	setLastName(pntFullName, strLastName);
	return pntFullName;
}

