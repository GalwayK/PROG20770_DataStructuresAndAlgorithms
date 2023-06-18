#define NUM_NAME_MAX_LENGTH 255

const int MAX_NAME_LENGTH = NUM_NAME_MAX_LENGTH;

typedef struct FullName
{
	char firstName[NUM_NAME_MAX_LENGTH];
	char lastName[NUM_NAME_MAX_LENGTH];
} FullName;

FullName* initializeFullName(void);

char* getFirstName(FullName* pntFullname);

char* getLastName(FullName* pntFullName);

void setFirstName(FullName* pntFullName, char* strFirstName);

void setLastName(FullName* pntFullName, char* strLastName);

void freeFullName(FullName** pntPntFullName);

int compareNames(FullName* pntFirstName, FullName* pntSecondName);

FullName* createFullName(char* strFirstName, char* strLastName);

#undef NUM_NAME_MAX_LENGTH

