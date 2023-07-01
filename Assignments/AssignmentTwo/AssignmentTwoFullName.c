#include "AssignmentTwoFullName.h"
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

// Function to initialize a FullName (mimics constructor)
FullName* initializeFullName()
{
	FullName fullName;
	FullName* pntFullName = calloc(1, sizeof(FullName));
	*pntFullName = fullName;
	return pntFullName;
}

// Get first name of FullName struct
char* getFirstName(FullName* pntFullName)
{
	return pntFullName -> firstName;
}

// Get last name of FullName struct
char* getLastName(FullName* pntFullName)
{
	return pntFullName -> lastName;
}

// Set firstName of FullName struct
void setFirstName(FullName* pntFullName, char* strFirstName)
{
	strncpy(pntFullName -> firstName, strFirstName, MAX_NAME_LENGTH);
}

// Set lastName of FullName struct
void setLastName(FullName* pntFullName, char* strLastName)
{
	strncpy(pntFullName -> lastName, strLastName, MAX_NAME_LENGTH);
}

// Free a memory allocated FullName
void freeFullName(FullName** pntPntFullName)
{
	FullName* pntFullName = *pntPntFullName;
	free(pntFullName);
}

// Compare two FullName instances
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

// Function for creating a fullName instance
FullName* createFullName(char* strFirstName, char* strLastName)
{
	FullName* pntFullName = initializeFullName();
	setFirstName(pntFullName, strFirstName);
	setLastName(pntFullName, strLastName);
	return pntFullName;
}

