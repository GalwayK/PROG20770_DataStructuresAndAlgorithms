#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdbool.h>

int currentStatusCode = 0;

char* arrStatusCodes[] = {"Application intialized!", 
	"Successful creation of num node", 
	"Error creating num node, memory full!",
	"Successful enqueue into empty queue", 
	"Successful enqueue into queue", 
	"Cannot dequeue, queue is empty!"};

typedef struct MyQueue 
{
	void* pntValue;
	struct MyQueue* pntNextNode;
} MyQueue;

MyQueue* createNumNode(int numValue)
{
	MyQueue* numQueue = malloc(sizeof(MyQueue) * 1);
	
	if (numQueue != NULL)
	{
		currentStatusCode = 1;
		numQueue -> pntNextNode = NULL;
			
		int* pntValue = calloc(1, sizeof(int));
		*pntValue = numValue;
	
		numQueue -> pntValue = pntValue;
		
		
	}
	else 
	{
		currentStatusCode = 2;
	}
	
	return numQueue;
}

void enqueueNumber(MyQueue** pntNumQueue, MyQueue* insertNode)
{
	MyQueue* numQueue = *pntNumQueue;
	
	if (numQueue == NULL)
	{
		*pntNumQueue = insertNode;
	}
	else 
	{
		while (numQueue -> pntNextNode != NULL)
		{
			numQueue = numQueue -> pntNextNode;
		}
		numQueue -> pntNextNode = insertNode;
	}
}

MyQueue* dequeueNumber(MyQueue** pntNumQueue)
{
	MyQueue* numQueue = *pntNumQueue;
	
	if (numQueue == NULL)
	{
		return NULL;
	}
	else 
	{
		int* numValue = numQueue -> pntValue;
		printf("Dequeueing value: %d\n", *numValue);
		*pntNumQueue = numQueue -> pntNextNode;
		numQueue -> pntNextNode = NULL;
		return numQueue;
	}
}

void printNumNode(MyQueue* numNode);

int getIntInput(void);

int main(int argCounts, char** argStrings)
{
	puts("This is an exercise to create a Queue with a Linked List!");
	MyQueue* numQueue = NULL;
	MyQueue** pntNumQueue = &numQueue;
	int numOperations = 0;
	
	puts("Populating Queue!");
	while (numOperations < 3)
	{
		printf("\nCreating node value #%d\n", ++numOperations);	
		int intValue = getIntInput();
		MyQueue* newNode = createNumNode(intValue); 
		enqueueNumber(pntNumQueue, newNode);
		
		printf("Enqueuing node of value %d\n", *(int*)(newNode -> pntValue));
	}
	
	puts("\nEmptying Queue!");
	while (numQueue != NULL)
	{
		puts("Dequeuing the front of the queue!");
		MyQueue* dequeuedNode = dequeueNumber(pntNumQueue);
		
		puts("Printing the dequeued node!");
		int* pntValue = dequeuedNode -> pntValue;
		printf("Dequeueing value: %d\n", *pntValue);
		printNumNode(dequeuedNode);
		puts("");
	}
	puts("Queue emptied!");
}

void printNumNode(MyQueue* numNode)
{
	if (numNode  != NULL)
	{
		printf("The Value of the Node is: %d\n", *(int*)(numNode -> pntValue));
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
