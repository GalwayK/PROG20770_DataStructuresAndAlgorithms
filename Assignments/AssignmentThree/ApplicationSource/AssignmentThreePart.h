#include<stdlib.h>
#include<string.h>
#define DEF_PART_NAME_MAX_LENGTH 255

// Constant to track max length of partName string
const static int PART_NAME_MAX_LENGTH = DEF_PART_NAME_MAX_LENGTH;

// Structure to contain part data
typedef struct Part
{
	int intPartNumber;
	char strPartName[DEF_PART_NAME_MAX_LENGTH];
	int intPartQuantity;
} Part;

// Function prototypes 

// Function to initialize blank part structure
Part* initializeBlankPart(void);

// Function to initialize detailed part structure
Part* initializeDetailedPart(int partNumber, char* partName, int partQuantity);

// Function to get partNumber from given part
int getPartNumber(Part* pntPart);

// Function to get part quantity from given part
int getPartQuantity(Part* pntPart);

// Function to get part name from given part
char* getPartName(Part* pntPart);

// Function to set part quantity field
void setPartQuantity(Part* pntPart, int partQuantity);

// Function to set part number field
void setPartNumber(Part* pntPart, int partQuantity);

// Function to set part name field
void setPartName(Part* pntPart, char* partName);

#undef DEF_PART_NAME_MAX_LENGTH
