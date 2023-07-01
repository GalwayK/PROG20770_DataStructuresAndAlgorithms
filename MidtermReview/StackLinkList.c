#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

char* arrStatusCodes[] = {"Program initialized!", 
	"Something went wrong!", 
	"Successful insert in new stack", 
	"Successful insertion at end of stack", 
	"Cannot peek, stack is empty!", 
	"Successfully peeked top value!", 
	"Cannot pop, stack is empty!", 
	"Successfully popped top value, stack is not empty!", 
	"Successfully popped top value, stack is empty!"};
	
int currentStatusCode = 0;

typedef struct NumStack 
{
	int numValue;
	struct NumStack* pntNextNode;
} NumStack;

NumStack* createNumNode(int intValue)
{
	printf("Creating node with intValue of %d\n", intValue);
	NumStack* numStack = calloc(1, sizeof(NumStack));
	if (numStack != NULL)
	{
		numStack -> numValue = intValue;
		numStack -> pntNextNode = NULL;	
	}
	return numStack;
}

NumStack* peekNumStack(NumStack** pntNumStack)
{
	NumStack* numStack = *pntNumStack;
	
	if (numStack == NULL)
	{
		currentStatusCode = 4;
		return NULL;
	}
	else
	{
		while (numStack -> pntNextNode != NULL)
		{
			numStack = numStack -> pntNextNode;
		}
		return numStack;
	}
}

NumStack* popNumStack(NumStack** pntNumStack)
{
	NumStack* numStack = *pntNumStack;
	
	if (numStack == NULL)
	{
		currentStatusCode = 6;
		return NULL;
	}
	else 
	{
		NumStack* prevNode = NULL;
		while (numStack -> pntNextNode != NULL)
		{
			prevNode = numStack;
			numStack = numStack -> pntNextNode;
		}
		if (prevNode != NULL)
		{
			prevNode -> pntNextNode = NULL;
		}
		else 
		{
			*pntNumStack = NULL;
		}
		return numStack;
	}
}

int pushNumStack(NumStack** pntNumStack, NumStack* insertNode)
{
	NumStack* numStack = *pntNumStack;
	
	if (numStack == NULL)
	{
		*pntNumStack = insertNode;
		return 2;
	}
	else 
	{
		while (numStack -> pntNextNode != NULL)
		{
			numStack = numStack -> pntNextNode;
		}
		numStack -> pntNextNode = insertNode;
		return 3;
	}
	return 1;
}

void putNumNode(NumStack* numNode);

int getIntInput(void);

int main(int argCount, char** argStrings)
{
	int numOperations = 0;
	NumStack* numStack = NULL;
	NumStack** pntNumStack = &numStack;
	
	while (numOperations < 3)
	{
		printf("Performing operation #%d!\n", ++numOperations);
		
		int intValue = getIntInput();
		printf("Retrieved Input Value: %d\n", intValue);
		
		NumStack* numNode = createNumNode(intValue);
		printf("Created Number Node of Value: %d\n", numNode -> numValue);
		
		int statusCode = pushNumStack(pntNumStack, numNode);
		printf("%s\n", arrStatusCodes[statusCode]);
		
		puts("Peeking the Top of the Stack!");
		NumStack* peekedNode = peekNumStack(pntNumStack);
		
		puts("Printing the Peeked Node!");
		putNumNode(peekedNode);
		puts("");
	}
	
	puts("\nEmptying the Stack!");
	while (numStack != NULL)
	{
		puts("Popping the Top of the Stack!");
		NumStack* poppedStack = popNumStack(pntNumStack);
		
		puts("Printing the Popped Node!");
		putNumNode(poppedStack);
	}
	
	puts("Stack is now empty!");
	printf("Stack Address: %p\n", numStack);
}

void putNumNode(NumStack* numNode)
{
	if (numNode == NULL)
	{
		puts("Error, node is null!");
	}
	else 
	{
		printf("The value of the node is: %d\n", numNode -> numValue);
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
