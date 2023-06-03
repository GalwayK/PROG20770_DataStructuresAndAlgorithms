#define ARR_LENGTH 100
#include "midtermReview.h"

double globalDouble;
static long globalStaticNumber;

void reviewMidterm(void)
{
	puts("Reviewing for the midterm!");
	
	bool localBool;
	int arrNumbers[ARR_LENGTH];
	bool arrBoolean[ARR_LENGTH];
	static long localStaticNumber;
	
	printf("%lf\n", globalDouble);
	printf("%hd\n", localBool);
	printf("Local static: %ld\n", localStaticNumber);
	printf("Global static: %ld\n", globalStaticNumber);
	printf("Sizeof: %hd\n", sizeof(long long));
	
	
//	for (int i = 0; i < ARR_LENGTH; i++)
//	{
//		printf("Number: %d\n", arrNumbers[i]);
//		printf("Boolean: %hd\n", arrBoolean[i]);
//	}
	
}
