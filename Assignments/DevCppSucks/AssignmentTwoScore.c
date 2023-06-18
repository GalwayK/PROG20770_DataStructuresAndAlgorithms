#include "AssignmentTwoScore.h"
#include <stdlib.h>
#include<stdio.h>

void initializeScoreList(Score** scoreList)
{
	*scoreList = NULL;
}

Score* createScore(char* firstName, char* lastName, points numScore)
{
	Score score;
	Score* pntScore = malloc(sizeof(struct Score));
	
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

void insertScoreAtStart(Score** pntScoreList, Score* score)
{
	printf("Adding score!\n");
	Score* scoreList = *pntScoreList;
	if (isScoreListEmpty(pntScoreList))
	{
		*pntScoreList = score;
	}
	else 
	{
		score -> pntNextScore = scoreList;
		*pntScoreList = score;
	}
}

void insertScoreAtIndex(Score** pntScoreList, Score* score, int numIndex)
{
	Score* prevScore = NULL;
	Score* scoreList = *pntScoreList;
	
	if (numIndex > getScoreListLength(pntScoreList) || numIndex < 0)
	{
		return;
	}
	else if (numIndex == 0)
	{
		insertScoreAtStart(pntScoreList, score);
	}
	else  
	{
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

Score* getLastScore(Score** pntScoreList)
{
	Score* scoreList = *pntScoreList;
	if (isScoreListEmpty(pntScoreList))
	{
		return NULL;
	}
	else 
	{
		while (scoreList -> pntNextScore != NULL)
		{
			scoreList = scoreList -> pntNextScore;
		}
		return scoreList;
	}
}

Score* getFirstScore(Score** pntScoreList)
{
	return *pntScoreList;
}

Score* getScoreAtIndex(Score** pntScoreList, int numIndex)
{
	Score* scoreList = *pntScoreList;
	
	if (numIndex >= getScoreListLength(pntScoreList) || numIndex < 0)
	{
		return NULL;
	}
	else if (numIndex == 0)
	{
		return getFirstScore(pntScoreList);
	}
	else  
	{
		int numScores = 0;
		while (numScores != numIndex)
		{
			scoreList = scoreList -> pntNextScore;
			numScores += 1;
		}
		return scoreList;
	}
}

int deleteScoreAtEnd(Score** pntScoreList)
{
	Score* prevScore = NULL;
	Score* scoreList = *pntScoreList;
	
	if (isScoreListEmpty(pntScoreList))
	{
		return -1;
	}
	else  
	{
		while (scoreList -> pntNextScore != NULL)
		{
			prevScore = scoreList;
			scoreList = scoreList -> pntNextScore;
		}
		
		free(scoreList);
		if (prevScore != NULL)
		{
			prevScore -> pntNextScore = NULL;
		}
		else 
		{
			*pntScoreList = NULL;
		}
		return 0;
	}
}

int deleteScoreAtStart(Score** pntScoreList)
{
	int lengthScoreList = getScoreListLength(pntScoreList);
	Score* scoreList = *pntScoreList;
	if (isScoreListEmpty(pntScoreList))
	{
		return -1;
	}
	else 
	{
		if (lengthScoreList == 1)
		{
			*pntScoreList = NULL;
		}
		else 
		{
			*pntScoreList = scoreList -> pntNextScore;
		}
		freeScore(scoreList);
	}
	return 0;
}

int deleteScoreAtIndex(Score** pntScoreList, int numIndex)
{
	Score* scoreList = *pntScoreList;
	
	if (numIndex >= getScoreListLength(pntScoreList) || numIndex < 0)
	{
		return -1;
	}
	else if (numIndex == 0)
	{
		deleteScoreAtStart(pntScoreList);
	}
	else  
	{
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
			prevScore -> pntNextScore = scoreList -> pntNextScore;
			freeScore(scoreList);
		}
		else 
		{
			deleteScoreAtStart(pntScoreList);
		}
	}
	return 0;
}

void deleteAllScores(Score** pntScoreList)
{
	Score* scoreList = *pntScoreList;
	Score* prevScore = NULL;
	
	if (scoreList != NULL)
	{
		while (scoreList -> pntNextScore != NULL)
		{
			prevScore = scoreList;
			scoreList = scoreList -> pntNextScore;
			freeScore(prevScore);
		}
		free(scoreList);
		*pntScoreList = NULL;
	}
}

Score* searchScoreListByName(Score** pntScoreList, char* strFirstName, 
	char* strLastName)
{
	FullName* searchName = createFullName(strFirstName, strLastName);
	Score* scoreList = *pntScoreList;
	Score* searchScore = NULL;
	
	while (!isScoreListEmpty(pntScoreList) && scoreList != NULL)
	{
		if (compareNames(searchName, &scoreList -> fullName) == 0)
		{
			searchScore = scoreList;
			break;
		}
		scoreList = scoreList -> pntNextScore;
	}
	freeFullName(&searchName);
	return searchScore;
}

Score* searchScoreListByPoints(Score** pntScoreList, points numPoints)
{
	Score* scoreList = *pntScoreList;
	Score* searchScore = NULL;
	
	while (!isScoreListEmpty(pntScoreList) && scoreList != NULL)
	{
		if (scoreList -> numScore == numPoints)
		{
			searchScore = scoreList;
			break;
		}
		scoreList = scoreList -> pntNextScore;
	}
	return searchScore;
}

void freeScore(Score* score)
{
	free(score);
}

bool isScoreListEmpty(Score** pntScoreList)
{
	Score* scoreList = *pntScoreList;
	if (scoreList == NULL)
	{
		return true;
	}
	return false;
}

int getScoreListLength(Score** pntScoreList)
{
	int numScores = 0;
	Score* scoreList = *pntScoreList;
	
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
