#include <stdio.h>
#include <stdlib.h>
#include "AssignmentTwoScore.h"

void displayAllScores(Score** pntScoreList);

void displayScore(Score* score);

void displayChoices(void);

void getNameInput(char* pntFirstName, char* pntLastName);

void getScoreInput(int* pntPoints);

void insertFirst(Score** pntScoreList, char* pntFirstName, 
	char* pntLastName, int* pntPoints);
	
void insertLast(Score** pntScoreList, char* pntFirstName, 
	char* pntLastName, int* pntPoints);
	
void insertAnywhere(Score** pntScoreList, char* pntFirstName, 
	char* pntLastName, int* pntPoints);
	
void deleteFirst(Score** pntScoreList);

void deleteLast(Score** pntScoreList);

void deleteAnywhere(Score** pntScoreList);

void searchByName(Score** pntScoreList, char* pntFirstName, char* pntLastName);

void searchByScore(Score** pntScoreList, int* pntPoints);

void runTest(void);

void runProgram(void);

void displayAllScores(Score** pntScoreList)
{
	Score* scoreList = *pntScoreList;

	puts("\n====================");
	puts("Printing scores");

	if (scoreList != NULL)
	{
		int numScores = 1;
		do 
		{
			printf("%d. %s %s has scored %d!\n", 
				numScores++,
				getFirstName(&scoreList -> fullName), 
				getLastName(&scoreList -> fullName), 
				scoreList -> numScore);
			scoreList = scoreList -> pntNextScore;
		} while (scoreList != NULL);
	}
}

void displayScore(Score* pntScore)
{
	puts("\n====================");
	puts("Printing Score");
	if (pntScore != NULL)
	{
		printf("%s %s has scored %d!\n", 
			getFirstName(&pntScore -> fullName), 
			getLastName(&pntScore -> fullName), 
			pntScore -> numScore);
	}
}

void displayChoices(void)
{
	puts("\n====================");
	printf("1)	Display\n2)	Insert at Start\n3)	Insert At End\n4)	Insert "
		"Anywhere\n5)	Delete at Start\n6)	Delete at End\n7)	Delete Anywhere\n"
		"8)	Search by Name\n9)	Search by Score\n0)	Exit Program\n");
}

void getScoreInput(int* pntPoints)
{
	puts("Prompting for score entry...");
	printf("%s", "Please enter the score: ");
	scanf("%d", pntPoints);
}

void getNameInput(char* pntFirstName, 
	char* pntLastName)
{
	puts("Prompting for name entry...");
	printf("%s", "Please enter the first name: ");
	scanf("%s", pntFirstName);
	printf("%s", "Please enter the second name: ");
	scanf("%s", pntLastName);
}

void insertFirst(Score** pntScoreList, char* pntFirstName, 
	char* pntLastName, int* pntPoints)
{
	getNameInput(pntFirstName, pntLastName);
	getScoreInput(pntPoints);
	printf("Inserting '%s %s with Score: %d.\'\n", pntFirstName, pntLastName, 
		*pntPoints);
	
	Score* score = createScore(pntFirstName, pntLastName, *pntPoints);
	if (score != NULL)
	{
		insertScoreAtStart(pntScoreList, score);
		puts("Successfully inserted score!");
	}
	else 
	{
		puts("Error: Memory unavailable!");
	}
}

void insertLast(Score** pntScoreList, char* pntFirstName, 
	char* pntLastName, int* pntPoints)
{
	getNameInput(pntFirstName, pntLastName);
	getScoreInput(pntPoints);
	printf("Inserting '%s %s with Score: %d.\'\n", pntFirstName, pntLastName, 
		*pntPoints);
	
	Score* score = createScore(pntFirstName, pntLastName, *pntPoints);
	if (score != NULL)
	{
		insertScoreAtEnd(pntScoreList, score);
		puts("Successfully inserted score!");
	}
	else 
	{
		puts("Error: Memory unavailable!");
	}
}

void insertAnywhere(Score** pntScoreList, char* pntFirstName, 
	char* pntLastName, int* pntPoints)
{
	int numIndex;
	
	getNameInput(pntFirstName, pntLastName);
	getScoreInput(pntPoints);
	printf("Inserting '%s %s with Score: %d.\'\n", pntFirstName, pntLastName, 
		*pntPoints);
		
	printf("Please enter index to insert: ");
	scanf("%d", &numIndex);
	numIndex -= 1;
		
	Score* score = createScore(pntFirstName, pntLastName, *pntPoints);
	
	if (score != NULL)
	{
		insertScoreAtIndex(pntScoreList, score, numIndex);
		puts("Successfully inserted score!");
	}
	else 
	{
		puts("Error: Memory unavailable!");
	}
}

void deleteFirst(Score** pntScoreList)
{
	int result = deleteScoreAtStart(pntScoreList);
	if (result == 0)
	{
		printf("%s", "Successfully deleted first index!\n");
	}
	else
	{
		printf("Error: List is Empty!\n");
	}
}

void deleteLast(Score** pntScoreList)
{
	int result = deleteScoreAtEnd(pntScoreList);
	if (result == 0)
	{
		printf("%s", "Successfully deleted last index!\n");
	}
	else
	{
		printf("Error: List is Empty!\n");
	}
}

void deleteAnywhere(Score** pntScoreList)
{
	int numIndex;
	printf("Please enter the index to delete: ");
	scanf("%d", &numIndex);
	numIndex -= 1;
	
	int result = deleteScoreAtIndex(pntScoreList, numIndex);
	if (result == 0)
	{
		printf("Successfully deleted index %d!\n", numIndex + 1);
	}
	else
	{
		printf("Error: Invalid index for deletion!\n");
	}
}

void searchByName(Score** pntScoreList, char* pntFirstName, char* pntLastName)
{
	getNameInput(pntFirstName, pntLastName);
	
	Score* searchedScore = searchScoreListByName(pntScoreList, pntFirstName, 
		pntLastName);
		
	if (searchedScore != NULL)
	{
		puts("Found Score!");
		displayScore(searchedScore);
	}
	else 
	{
		puts("Error: Cannot find matching score!");
	}
}

void searchByScore(Score** pntScoreList, int* pntPoints)
{
	getScoreInput(pntPoints);
	
	Score* searchedScore = searchScoreListByPoints(pntScoreList, *pntPoints);
	
	if (searchedScore != NULL)
	{
		puts("Found Score!");
		displayScore(searchedScore);
	}
	else 
	{
		puts("Error: Cannot find matching score!");
	}
}

void runProgram(void)
{
	Score* scoreList;
	Score** pntScoreList = &scoreList;
	initializeScoreList(pntScoreList);
	char* arrChoices[] = {"Exit Program", "Display All Scores", "Insert First", "Insert Last", 
		"Insert Anywhere", "Delete First", "Delete Last", "Delete Anywhere", 
		"Search by Name", "Search by Score"};
	
	char strFirstName[255];
	char strLastName[255];
	
	char* pntFirstName = (char*)&strFirstName;
	char* pntLastName = (char*)&strLastName;
	
	int numPoints;
	int* pntPoints = &numPoints;
	
	puts("Welcome to the Linked List Score Tracking Application by Kyle "
		"Galway!");
	
	short numPrompt;
	bool isRunning = true;
	
	while (isRunning)
	{
		displayChoices();
		numPrompt = -1;
		printf("Please select your choice: ");
		scanf("%hd", &numPrompt);
		puts("\n====================");
		printf("You selected choice %d: %s\n", numPrompt, 
			arrChoices[numPrompt]);
		
		switch (numPrompt)
		{
			case 1: 
				displayAllScores(pntScoreList);
				break;
			case 2: 
				insertFirst(pntScoreList, pntFirstName, pntLastName, pntPoints);
				break;
			case 3:
				insertLast(pntScoreList, pntFirstName, pntLastName, pntPoints);
				break;
			case 4: 
				insertAnywhere(pntScoreList, pntFirstName, pntLastName, pntPoints);
				break;
			case 5: 
				deleteFirst(pntScoreList);
				break;
			case 6: 
				deleteLast(pntScoreList);
				break;
			case 7: 
				deleteAnywhere(pntScoreList);
				break;
			case 8: 
				searchByName(pntScoreList, pntFirstName, pntLastName);
				break;
			case 9: 
				searchByScore(pntScoreList, pntPoints);
				break;
			case 0: 
				puts("\n====================");
				puts("Exiting program...");
				isRunning = false;
				break;
			default: 
				puts("Invalid input, try again!");
				break;
		}
	}
	deleteAllScores(pntScoreList);
}

int main(int argCount, char** argStrings) 
{
	runProgram();
	
	// runTests();
	puts("Thank you for using!");
	exit(0);
	return 0;
}

void runTests(void)
{
	Score* scoreList;
	Score** pntScoreList = &scoreList;
	initializeScoreList(pntScoreList);
	char strFirstName[255];
	char strLastName[255];
	
	int numPoints;
	int* pntPoints = &numPoints;

	for (int i = 0; i < 3; i++)
	{
		printf("%s", "Please enter the first name: ");
		scanf("%s", strFirstName);
		printf("%s", "Please enter the second name: ");
		scanf("%s", strLastName);
		printf("%s", "Please enter the score: ");
		scanf("%d", &numPoints);
		
		puts("Creating score!");
		Score* pntScore = createScore(strFirstName, strLastName, numPoints);
		if (i == 0)
		{
			puts("Adding Score to Start");
			insertScoreAtStart(pntScoreList, pntScore);
		}
		else if (i == 1)
		{
			puts("Adding Score to End");
			insertScoreAtEnd(pntScoreList, pntScore);
		}
		else 
		{
			puts("Adding Score to Middle");
			insertScoreAtIndex(pntScoreList, pntScore, 1);
		}
	}
	displayAllScores(pntScoreList);
	
	puts("\nGetting First Score!");
	Score* firstScore = getFirstScore(pntScoreList);
	displayScore(firstScore);
	
	puts("\nGetting Last Score!");
	Score* lastScore = getLastScore(pntScoreList);
	displayScore(lastScore);
	
	puts("\nGetting Middle Score!");
	Score* middleScore = getScoreAtIndex(pntScoreList, 1);
	displayScore(middleScore);
	
	puts("\nSearching by Name!");
	printf("%s", "Please enter the first name: ");
	scanf("%s", strFirstName);
	printf("%s", "Please enter the second name: ");
	scanf("%s", strLastName);
	Score* nameScore = searchScoreListByName(pntScoreList, strFirstName, 
		strLastName);
	printf("Found by Name Search!: ");
	displayScore(nameScore);
	
	puts("\nSearching by Score!");
	printf("%s", "Please enter the score: ");
	scanf("%d", &numPoints);
	Score* pointsScore = searchScoreListByPoints(pntScoreList, numPoints);
	printf("Found by Score Search!\n");
	displayScore(pointsScore);
	
	puts("\nDeleting Middle Score!\n");
	deleteScoreAtIndex(pntScoreList, 1);
	displayAllScores(pntScoreList);
	
	puts("\nDeleting First Score!\n");
	deleteScoreAtStart(pntScoreList);
	displayAllScores(pntScoreList);
	
	puts("\nDeleting Last Score!\n");
	deleteScoreAtEnd(pntScoreList);
	displayAllScores(pntScoreList);
}

