#include "AssignmentTwoScore.h"
#include <stdlib.h>
#include <stdio.h>

// Function to set scorelist to NULL if empty (can be done in main)
void initializeScoreList(Score** scoreList)
{
	*scoreList = NULL;
}

// Function to intstantiate a score (mimics a constructor)
Score* createScore(char* firstName, char* lastName, points numScore)
{
	Score score;
	Score* pntScore = malloc(sizeof(struct Score));
	
	// If memory not full, fill in score fields
	if (pntScore != NULL)
	{
		*pntScore = score;
	
		pntScore -> numScore = numScore; 
		setFirstName(&(pntScore -> fullName), firstName);
		setLastName(&(pntScore -> fullName), lastName);
		pntScore -> pntNextScore = NULL;
	}

	return pntScore;
}

// Function for inserting score at end of Linked List
void insertScoreAtEnd(Score** pntScoreList, Score* score)
{
	Score* scoreList = *pntScoreList;
	if (isScoreListEmpty(pntScoreList))
	{
		*pntScoreList = score;
	}
	else 
	{
		while (scoreList -> pntNextScore != NULL)
		{
			scoreList = scoreList -> pntNextScore;
		}
		scoreList -> pntNextScore = score;
	}
}

// Function for inserting score at start of Linked List
void insertScoreAtStart(Score** pntScoreList, Score* score)
{
	printf("Adding score!\n");
	Score* scoreList = *pntScoreList;
	
	if (isScoreListEmpty(pntScoreList))
	{
		// If the list is NULL, make list point to new score
		*pntScoreList = score;
	}
	else 
	{
		// If list is not NULL, make first index into second index
		score -> pntNextScore = scoreList;
		*pntScoreList = score;
	}
}

// Function for inserting score and specific index
void insertScoreAtIndex(Score** pntScoreList, Score* score, int numIndex)
{
	Score* prevScore = NULL;
	Score* scoreList = *pntScoreList;
	
	// If index is not within List length, exist function
	if (numIndex > getScoreListLength(pntScoreList) || numIndex < 0)
	{
		return;
	}
	else if (numIndex == 0)
	{
		// If index is -, insert into start
		insertScoreAtStart(pntScoreList, score);
	}
	else  
	{
		// If index can fit within list, insert score into index
		int numScores = 0;
		while (numScores != numIndex)
		{
			prevScore = scoreList;
			scoreList = scoreList -> pntNextScore;
			numScores += 1;
		}
		score -> pntNextScore = scoreList;
		prevScore -> pntNextScore = score;
	}
}

// Function for getting last score in Linked List
Score* getLastScore(Score** pntScoreList)
{
	Score* scoreList = *pntScoreList;
	
	// If the list is empty, return NULL
	if (isScoreListEmpty(pntScoreList))
	{
		return NULL;
	}
	else 
	{
		// Return last score if list is not null
		while (scoreList -> pntNextScore != NULL)
		{
			scoreList = scoreList -> pntNextScore;
		}
		return scoreList;
	}
}

// Function for getting first score in Linked List
Score* getFirstScore(Score** pntScoreList)
{
	// Return first index (whether list is empty is irrelevant)
	return *pntScoreList;
}

// Function for getting score at specific index
Score* getScoreAtIndex(Score** pntScoreList, int numIndex)
{
	Score* scoreList = *pntScoreList;
	
	// If index not within list length, return NULL
	if (numIndex >= getScoreListLength(pntScoreList) || numIndex < 0)
	{
		return NULL;
	}
	else if (numIndex == 0)
	{
		// If index at first element, attempt to retrieve first index
		return getFirstScore(pntScoreList);
	}
	else  
	{
		// If list is not null, return score located at index
		int numScores = 0;
		while (numScores != numIndex)
		{
			scoreList = scoreList -> pntNextScore;
			numScores += 1;
		}
		return scoreList;
	}
}

// Function for deleting score at end of Linked List
int deleteScoreAtEnd(Score** pntScoreList)
{
	Score* prevScore = NULL;
	Score* scoreList = *pntScoreList;
	
	// If list is empty, return -1 status code indicating failure
	if (isScoreListEmpty(pntScoreList))
	{
		return -1;
	}
	else  
	{
		// If list is not empty delete score at end of list
		while (scoreList -> pntNextScore != NULL)
		{
			prevScore = scoreList;
			scoreList = scoreList -> pntNextScore;
		}
		
		free(scoreList);
		
		if (prevScore != NULL)
		{
			// If list is not empty, set prev score to end of list
			prevScore -> pntNextScore = NULL;
		}
		else 
		{
			// If list length is now 0, set list to NULL
			*pntScoreList = NULL;
		}
		return 0;
	}
}

// Function for deleting score at star of Linked List
int deleteScoreAtStart(Score** pntScoreList)
{
	int lengthScoreList = getScoreListLength(pntScoreList);
	Score* scoreList = *pntScoreList;
	
	// If list is empty, return -1 status code
	if (isScoreListEmpty(pntScoreList))
	{
		return -1;
	}
	else 
	{
		// Delete score at start of list
		if (lengthScoreList == 1)
		{
			// If list length is 1, set list to null
			*pntScoreList = NULL;
		}
		else 
		{
			// If list not empty, make list point to new first element
			*pntScoreList = scoreList -> pntNextScore;
		}
		freeScore(scoreList);
	}
	return 0;
}

// Function for deleting score at specific index
int deleteScoreAtIndex(Score** pntScoreList, int numIndex)
{
	Score* scoreList = *pntScoreList;
	
	// If list is empty, return -1 status code
	if (numIndex >= getScoreListLength(pntScoreList) || numIndex < 0)
	{
		return -1;
	}
	else if (numIndex == 0)
	{
		// If index is 0, attempt to delete at index start
		deleteScoreAtStart(pntScoreList);
	}
	else  
	{
		// Delete from list at index 
		Score* prevScore = NULL;
		int numScores = 0;
		while (numScores != numIndex)
		{
			prevScore = scoreList;
			scoreList = scoreList -> pntNextScore;
			numScores += 1;
		}
		
		if (prevScore != NULL)
		{
			// If score is not empty, set update next score and prev score
			prevScore -> pntNextScore = scoreList -> pntNextScore;
			freeScore(scoreList);
		}
		else 
		{
			// If score is empty, set list to null
			deleteScoreAtStart(pntScoreList);
		}
	}
	return 0;
}

// Function for deleting all scores
void deleteAllScores(Score** pntScoreList)
{
	Score* scoreList = *pntScoreList;
	Score* prevScore = NULL;
	
	// Delete all scores within list
	if (scoreList != NULL)
	{
		while (scoreList -> pntNextScore != NULL)
		{
			prevScore = scoreList;
			scoreList = scoreList -> pntNextScore;
			freeScore(prevScore);
		}
		// Se list to null
		free(scoreList);
		*pntScoreList = NULL;
	}
}

// Function for searching through score Linked List by name
Score* searchScoreListByName(Score** pntScoreList, char* strFirstName, 
	char* strLastName)
{
	// Create fullname to search through list
	FullName* searchName = createFullName(strFirstName, strLastName);
	Score* scoreList = *pntScoreList;
	Score* searchScore = NULL;
	
	// Search through list it is determined if the list contains the score
	while (!isScoreListEmpty(pntScoreList) && scoreList != NULL)
	{
		if (compareNames(searchName, &scoreList -> fullName) == 0)
		{
			// If score found, assign to return variable
			searchScore = scoreList;
			break;
		}
		scoreList = scoreList -> pntNextScore;
	}
	// Free the allocated name used for searching
	freeFullName(&searchName);
	
	// Retrieve the (NULL if not found)
	return searchScore;
}

// Function for searching through score Linked List by score
Score* searchScoreListByPoints(Score** pntScoreList, points numPoints)
{
	Score* scoreList = *pntScoreList;
	Score* searchScore = NULL;
	
	// Search through list until score is found
	while (!isScoreListEmpty(pntScoreList) && scoreList != NULL)
	{
		if (scoreList -> numScore == numPoints)
		{
			// If score found, assign to return variable
			searchScore = scoreList;
			break;
		}
		scoreList = scoreList -> pntNextScore;
	}
	// Return score (NULL if not found)
	return searchScore;
}

// Function for freeing a score node
void freeScore(Score* score)
{
	/*
	This function is unneeded in this program, but if the 
	structures of the list required a more sophiscated behaviour to 
	free internally allocated fields, this function could do so.
	*/
	free(score);
}

// Function for determining in Linked List is empty
bool isScoreListEmpty(Score** pntScoreList)
{
	Score* scoreList = *pntScoreList;
	 return scoreList == NULL;
}

// Function for retrieving the length of the list
int getScoreListLength(Score** pntScoreList)
{
	int numScores = 0;
	Score* scoreList = *pntScoreList;
	
	// Iterate list to calculate list length
	if (!isScoreListEmpty(pntScoreList))
	{
		numScores = 1;
		while (scoreList -> pntNextScore != NULL)
		{
			scoreList = scoreList -> pntNextScore;
			numScores += 1;
		}
	}
	return numScores;
}
