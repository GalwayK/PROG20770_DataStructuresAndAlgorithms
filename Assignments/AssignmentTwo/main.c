#include <stdio.h>
#include <stdlib.h>
#include "AssignmentTwoScore.h"

// Function Declarations

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

// Function Definitions

// Function for displaying all saved scores
void displayAllScores(Score** pntScoreList)
{
	Score* scoreList = *pntScoreList;

	puts("\n====================");
	puts("Printing scores");

	// Display all scores stored in Linked List if list contains scores
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

// Function for displaying single saved score
void displayScore(Score* pntScore)
{
	puts("\n====================");
	puts("Printing Score");
	
	// Display score if the score is not null
	if (pntScore != NULL)
	{
		printf("%s %s has scored %d!\n", 
			getFirstName(&pntScore -> fullName), 
			getLastName(&pntScore -> fullName), 
			pntScore -> numScore);
	}
}

// Function for displaying all input choices
void displayChoices(void)
{
	puts("\n====================");
	printf("1)	Display\n2)	Insert at Start\n3)	Insert At End\n4)	Insert "
		"Anywhere\n5)	Delete at Start\n6)	Delete at End\n7)	Delete Anywhere\n"
		"8)	Search by Name\n9)	Search by Score\n0)	Exit Program\n");
}

// Function for receiving integer score input
void getScoreInput(int* pntPoints)
{
	// Prompt for an received integer input for score
	puts("Prompting for score entry...");
	int numResults;
	while (numResults != 1)
	{
		numResults = 0;
		printf("%s", "Please enter the score: ");
		fflush(stdin);
		numResults = scanf("%d", pntPoints);
	}
	
}

// Function for receiving C-style string name input
void getNameInput(char* pntFirstName, 
	char* pntLastName)
{
	int numInputs;
	// Prompt for a receive string input for firstName and lastName
	while (numInputs != 2)
	{
		numInputs = 0;
		puts("Prompting for name entry...");
		printf("%s", "Please enter the first name: ");
		fflush(stdin);
		numInputs += scanf("%s", pntFirstName);
		fflush(stdin);
		printf("%s", "Please enter the second name: ");
		numInputs += scanf("%s", pntLastName);
	}
	
}

// Function for inserting into first index of LinkedList
void insertFirst(Score** pntScoreList, char* pntFirstName, 
	char* pntLastName, int* pntPoints)
{
	// Prompt for input of score node data fields
	getNameInput(pntFirstName, pntLastName);
	getScoreInput(pntPoints);
	printf("Inserting '%s %s with Score: %d.\'\n", pntFirstName, pntLastName, 
		*pntPoints);
	// Instantiate score from received input
	Score* score = createScore(pntFirstName, pntLastName, *pntPoints);
	
	// If memory is not full, insert score
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

// Function for inserting into last index of linked list.
void insertLast(Score** pntScoreList, char* pntFirstName, 
	char* pntLastName, int* pntPoints)
{
	// Prompt for input of score node data fields 
	getNameInput(pntFirstName, pntLastName);
	getScoreInput(pntPoints);
	printf("Inserting '%s %s with Score: %d.\'\n", pntFirstName, pntLastName, 
		*pntPoints);
	
	// Instantiate score from received input
	Score* score = createScore(pntFirstName, pntLastName, *pntPoints);
	
	// If memory is not full, insert score
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

// Function for inserting into specified index of Linked List
void insertAnywhere(Score** pntScoreList, char* pntFirstName, 
	char* pntLastName, int* pntPoints)
{
	int numIndex;
	
	// Prompt for input of score node data fields
	getNameInput(pntFirstName, pntLastName);
	getScoreInput(pntPoints);
	printf("Inserting '%s %s with Score: %d.\'\n", pntFirstName, pntLastName, 
		*pntPoints);
		
	// Prompt for input of index to insert node into
	printf("Please enter index to insert: ");
	scanf("%d", &numIndex);
	numIndex -= 1;
		
	// Instantiate score from received input
	Score* score = createScore(pntFirstName, pntLastName, *pntPoints);
	
	// If memory is not full, insert score
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


// Function for deleting first index of Linked List
void deleteFirst(Score** pntScoreList)
{
	// Attempt to delete score from list and receive status code
	int result = deleteScoreAtStart(pntScoreList);
	
	// Status code indicates whether deletion was successful
	if (result == 0)
	{
		printf("%s", "Successfully deleted first index!\n");
	}
	else
	{
		printf("Error: List is Empty!\n");
	}
}

// Function for deleting last index of Linked List
void deleteLast(Score** pntScoreList)
{
	// Attempt to delete score from list and receive status code
	int result = deleteScoreAtEnd(pntScoreList);
	
	// Status code indicates whether deletion was successful
	if (result == 0)
	{
		printf("%s", "Successfully deleted last index!\n");
	}
	else
	{
		printf("Error: List is Empty!\n");
	}
}

// Function for deleting specific index of Linked List
void deleteAnywhere(Score** pntScoreList)
{
	// Prompt for input to receive index to delete from list
	int numIndex;
	printf("Please enter the index to delete: ");
	scanf("%d", &numIndex);
	numIndex -= 1;
	
	// Attempt to delete at index and receieve status code
	int result = deleteScoreAtIndex(pntScoreList, numIndex);
	
	// Status code indicates whether deletion was successful
	if (result == 0)
	{
		printf("Successfully deleted index %d!\n", numIndex + 1);
	}
	else
	{
		printf("Error: Invalid index for deletion!\n");
	}
}

// Funcion for searching Linked List by FullName struct
void searchByName(Score** pntScoreList, char* pntFirstName, char* pntLastName)
{
	// Prompt for name input for search criteria
	getNameInput(pntFirstName, pntLastName);
	
	// Attempt to search for score node where name matches
	Score* searchedScore = searchScoreListByName(pntScoreList, pntFirstName, 
		pntLastName);
		
	// Display the score node if it is found
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

// Function for searching Linked List by numerical score
void searchByScore(Score** pntScoreList, int* pntPoints)
{
	// Prompt for input for score search criteria
	getScoreInput(pntPoints);
	
	//Attempt to search for score node with input criteria
	Score* searchedScore = searchScoreListByPoints(pntScoreList, *pntPoints);
	
	// Display the score node if it is found
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

// Central function for running assignment program
void runProgram(void)
{
	// Instantiate the initial score Node List
	Score* scoreList;
	
	// Create pointer to score list for passing into Score header functions
	Score** pntScoreList = &scoreList;
	
	// Set the empty score to NULL
	initializeScoreList(pntScoreList);
	
	// Initialize array of choice strings
	char* arrChoices[] = {"Exit Program", "Display All Scores", "Insert First", 
		"Insert Last", "Insert Anywhere", "Delete First", "Delete Last", 
		"Delete Anywhere", "Search by Name", "Search by Score"};
	
	// Initialize char arrays for holding string input
	char strFirstName[255];
	char strLastName[255];
	
	// Create pointer to array location for accessing arrays by reference
	char* pntFirstName = (char*)&strFirstName;
	char* pntLastName = (char*)&strLastName;
	
	// Initialize integer variable for receiving score input
	int numPoints;
	int* pntPoints = &numPoints;
	
	puts("Welcome to the Linked List Score Tracking Application by Kyle "
		"Galway!");
	
	short numPrompt;
	bool isRunning = true;
	
	// Repeat input choices until user enters 0
	while (isRunning)
	{
		// Display choices for user and accept input
		displayChoices();
		numPrompt = -1;
		printf("Please select your choice: ");
		scanf("%hd", &numPrompt);
		puts("\n====================");
		printf("You selected choice %d: %s\n", numPrompt, 
			arrChoices[numPrompt]);
		
		// Run action of user selected choice 
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

// Main function as program insertion point
int main(int argCount, char** argStrings) 
{
	runProgram();

	puts("Thank you for using!");
	exit(0);
	
	return 0;
}
