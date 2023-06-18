#define NUM_MAX_SCORE 100
#define NUM_MIN_SCORE 0

const int MAX_SCORE = NUM_MAX_SCORE;
const int MIN_SCORE = NUM_MIN_SCORE;

typedef int points;

FullName fullName;

typedef struct Score
{
	FullName fullName;
	points numScore;
	struct score* pntNextScore;
} Score;

#undef NUM_MAX_SCORE
#undef NUM_MIN_SCORE

