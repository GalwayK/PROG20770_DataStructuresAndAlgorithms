#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int mapNumbers[100];
int statusNumber;

int makeHashNumber(int numUnhashed)
{
	return (numUnhashed % 100 + 1);
}

int getHashNumber(int numSearch, int repetitions)
{
	int hashNumber = makeHashNumber(numSearch);
	
	int numRetrieved = mapNumbers[hashNumber + repetitions];
	
	if (makeHashNumber(numRetrieved) != hashNumber)
	{
		return -1;
	}
	else if (numRetrieved == numSearch)
	{
		return numRetrieved;
	}
	else 
	{
		return getHashNumber(numSearch, repetitions + 1);
	}
}

void insertHashNumber(int numInsert, int repetitions)
{
	int hashNumber = makeHashNumber(numInsert);
	
	int storedNumber = mapNumbers[hashNumber + repetitions];
	
	if (makeHashNumber(storedNumber) != hashNumber && storedNumber == 0)
	{
		mapNumbers[hashNumber + repetitions] = numInsert;
	}
	else if (hashNumber + repetitions < 100)
	{
		insertHashNumber(numInsert, repetitions + 1);
	}
	else 
	{
		statusNumber = -1;
		printf("Cannot insert, list is full!\n");
	}
}

void printNumberMap()
{
	
	for (int i = 0; i < 100; i++)
	{
		printf("%d. %d\n", i + 1, mapNumbers[i]);
	}
	
}

char* mapWords[100];
int wordMapStatus;

int makeHashWord(char* word)
{
	int wordLength = strlen(word);
	int wordHash = 0; 
	
	for (int i = 0; i < wordLength; i++)
	{
		wordHash = wordHash + (word[i] * i);	
	}
	
	return makeHashNumber(wordHash);
}

int makeQuadraticIndex(int index, int cycles)
{
	return (index + cycles + (cycles * cycles)) % 100;
}

void insertIntoWordMap(char* word, int repetitions)
{
	int wordHash = makeHashWord(word);
	int numIndex = makeQuadraticIndex(wordHash, repetitions);
	char* storedWord = mapWords[numIndex];
	
	if (storedWord == NULL)
	{
		mapWords[numIndex] = word;
	}
	else if (repetitions < 100)
	{
		insertIntoWordMap(word, repetitions + 1);
	}
	else 
	{
		puts("Unable to add new element into array...");
	}
}

char* getFromWordMap(char* word, int repetitions)
{
	
}

void printWordMap()
{
	
	for (int i = 0; i < 100; i++)
	{
		if (mapWords[i] != NULL)
		{
			printf("%d. %s\n", i, mapWords[i]);
		}
	}
	
}

typedef struct NumList
{
	int number;
	struct NumList* pntNextNode;
} NumList;

int* arrPointers[10];

NumList* arrNumLists[10];

int main(int argCount, char** argStrings)
{
//	puts("Hello world!");
//	for (int i = 1; i < 999; i++)
//	{
//		if (statusNumber == -1)
//		{
//			break;
//		}
//		insertHashNumber(9, 0);
//		
//	}
//	printNumberMap();

//	char* arrWords[] = {"Hello", "There!", "Friends"};
//	
//	for (int i = 0; i < 30; i++)
//	{
//		insertIntoWordMap(arrWords[0], 0);
//	}
//	insertIntoWordMap(arrWords[0], 0);
//	printWordMap();

	printf("%p\n", arrPointers[0]);
	printf("%p\n", arrNumLists[0]);
	
	
	NumList numList;
	NumList* pntNumList = malloc(sizeof(NumList));
	*pntNumList = numList; 
	pntNumList -> number = 1;
	pntNumList -> pntNextNode = NULL; 

	if (arrNumLists[0] == NULL)
	{
		
		puts("Inserting into start of NumList!");
		arrNumLists[0] = pntNumList;
		puts("Inserted into top of NumList!");
	}
	else 
	{
		puts("Inserting into NumList");
		NumList* pntList = arrNumLists[0];
		
		while (pntList -> pntNextNode != NULL)
		{
			pntList = pntList -> pntNextNode;
		}
		pntList -> pntNextNode = pntNumList;
		puts("Inserted into NumList!");
	}
	
	if (arrNumLists[0] == NULL)
	{
		
		puts("Inserting into start of NumList!");
		arrNumLists[0] = pntNumList;
		puts("Inserted into top of NumList!");
	}
	else 
	{
		puts("Inserting into NumList");
		NumList* pntList = arrNumLists[0];
		
		while (pntList -> pntNextNode != NULL)
		{
			pntList = pntList -> pntNextNode;
		}
		pntList -> pntNextNode = pntNumList;
		puts("Inserted into NumList!");
	}
	
}








































