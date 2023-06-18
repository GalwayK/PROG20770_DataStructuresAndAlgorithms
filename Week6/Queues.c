#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define LENGTH_QUEUE 3

typedef struct 
{
	int indexHead;	
	int indexTail;
	int arrStack[LENGTH_QUEUE];
} NumQueue;

static NumQueue numQueue;

void initializeNumQueue()
{
	numQueue.indexHead = 0;
	numQueue.indexTail = 0;
}

bool isNumQueueEmpty()
{
	return numQueue.indexHead == numQueue.indexTail;
}

int getNextIndex(int numIndex)
{
	if (numIndex == LENGTH_QUEUE - 1)
	{
		return 0;
	}
	else 
	{
		return numIndex + 1;
	}
}

bool isNumQueueFilled()
{
	return getNextIndex(numQueue.indexTail) == numQueue.indexHead;
}

//bool isNumQueueFull()
//{
//	int numElements = numQueue.indexTail - numQueue.indexHead + 1;
//	
//	if (numQueue.indexTail < numQueue.indexHead)
//	{
//		numElements = numElements + LENGTH_QUEUE;
//	}
//	return numElements == LENGTH_QUEUE;
//}

void enqueueNumber(int number)
{
	if (!isNumQueueFilled())
	{
		numQueue.arrStack[numQueue.indexTail] = number;
		printf("Inserted %d into index: %d\n", 
			number,
			numQueue.indexTail);
		numQueue.indexTail = getNextIndex(numQueue.indexTail);
	}
}

int dequeueNumber()
{
	int numReturn = -1;
	if (!isNumQueueEmpty())	
	{
		numReturn = numQueue.arrStack[numQueue.indexHead];
		printf("Returning %d from index %d\n", numReturn, numQueue.indexHead);
		numQueue.indexHead = getNextIndex(numQueue.indexHead);	
	}
	else 
	{
		printf("Queue empty!");
	}
	return numReturn;
}

int main(int argCount, char** arStrings)
{
	puts("Filling numbers!");
	while(!isNumQueueFilled())
	{
		int numInput;
		printf("Enter a number: ");
		scanf("%d", &numInput);
		enqueueNumber(numInput);
	}
	
	puts("Printing numbers!");
	while(!isNumQueueEmpty())
	{
		printf("Emptied Number: %d\n", dequeueNumber());
	}
	printf("Emptied One More Number: %d\n", dequeueNumber());
	
	printf("Index Tail: %d\n", numQueue.indexTail);
	printf("Index Head: %d\n", numQueue.indexHead);
}
