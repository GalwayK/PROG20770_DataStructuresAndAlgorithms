#define DEF_PART_NAME_MAX_LENGTH 255

const static int PART_NAME_MAX_LENGTH = DEF_PART_NAME_MAX_LENGTH;

typedef struct Part
{
	int intPartNumber;
	char strPartName[DEF_PART_NAME_MAX_LENGTH];
	int intPartQuantity;
} Part;

Part* initializeBlankPart(void);

Part* initializeDetailedPart(int partNumber, char* partName, int partQuantity);

int getPartNumber(Part* pntPart);

int getPartQuantity(Part* pntPart);

char* getPartName(Part* pntPart);

void setPartQuantity(Part* pntPart, int partQuantity);

void setPartNumber(Part* pntPart, int partQuantity);

void setPartName(Part* pntPart, char* partName);

#undef DEF_PART_NAME_MAX_LENGTH
