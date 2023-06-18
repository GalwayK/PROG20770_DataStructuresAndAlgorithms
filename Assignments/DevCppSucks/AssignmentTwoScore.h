#define NUM_MAX_SCORE 100
#define NUM_MIN_SCORE 0
#include<stdbool.h>
#include "AssignmentTwoFullName.h"

const static int MAX_SCORE = NUM_MAX_SCORE;
const static int MIN_SCORE = NUM_MIN_SCORE;

typedef int points;

typedef struct Score
{
	FullName fullName;
	points numScore;
	struct Score* pntNextScore;
} Score;

void initializeScoreList(Score** scoreList);

Score* createScore(char* firstName, char* lastName, points numScore);

void insertScoreAtEnd(Score** scoreList, Score* score);

void insertScoreAtStart(Score** scoreList, Score* score);

void insertScoreAtIndex(Score** scoreList, Score* score, int numIndex);

Score* getLastScore(Score** pntScoreList);

Score* getFirstScore(Score** pntScoreList);

Score* getScoreAtIndex(Score** pntScoreList, int numIndex);

int deleteScoreAtEnd(Score** pntScoreList);

int deleteScoreAtStart(Score** pntScoreList);

int deleteScoreAtIndex(Score** pntScoreList, int numIndex);

void deleteAllScores(Score** pntScoreList);

Score* searchScoreListByName(Score** pntScoreList, char* strFirstName, 
	char* strLastName);
	
Score* searchScoreListByPoints(Score** pntScoreList, points numPoints);

void freeScore(Score* score);

bool isScoreListEmpty(Score** pntScoreList);

int getScoreListLength(Score** scoreList);

#undef NUM_MAX_SCORE
#undef NUM_MIN_SCORE


