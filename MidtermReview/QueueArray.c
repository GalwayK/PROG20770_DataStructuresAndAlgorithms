#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 10

typedef struct MyQueue
{
	int headIndex;
	int tailIndex;
	int arrNumbers[MAX_SIZE];
} MyQueue;

MyQueue* initializeMyQueue(void)
{
	// Always initialize pointers to NULL
	MyQueue* myQueue = NULL;
	
	// If reallic passed a NULL pointer, acts as malloc
	myQueue = realloc(myQueue, sizeof(MyQueue));
	
	if (myQueue != NULL)
	{
		myQueue -> headIndex = 0;
		myQueue -> tailIndex = 0;	
	}
	
	return myQueue;
}

void enqueueNumber(MyQueue** pntNumQueue, int numValue)
{
	MyQueue* numQueue = *pntNumQueue;
	numQueue -> arrNumbers[numQueue -> tailIndex] = numValue;
	numQueue -> tailIndex += 1;
}

int getIntInput(void);

int main(int argCount, char** argStrings)
{
	puts("Making a Queue with an Array!");
	MyQueue* numQueue = initializeMyQueue();
	MyQueue** pntNumQueue = &numQueue;
	
	puts("Created queue!");
	printf("Head Index: %d\n", numQueue -> headIndex);
	printf("Head Index: %d\n", numQueue -> tailIndex);
	
	int numOperations = 0;
	
	while (numOperations < 3)
	{
		printf("Getting number #%d\n", ++numOperations);
		int numValue = getIntInput();
		
		enqueueNumber(pntNumQueue, numValue);
	}
}

int getIntInput(void)
{
	int intInput;
	fflush(stdin);
	printf("%s", "Please enter an integer: ");
	int numInputs = scanf("%d", &intInput);
	if (numInputs != 1)
	{
		intInput = getIntInput();
	}
	return intInput;
}
