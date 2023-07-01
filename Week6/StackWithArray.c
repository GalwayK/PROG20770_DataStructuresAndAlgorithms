#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define STACK_LENGTH 10

typedef struct Score
{
	int numScore;
} Score;

typedef struct VoidLinkStack
{
	struct VoidLinkStack* pntNextVoidStack;
	void* pntValue;
} VoidLinkStack;

typedef struct VoidArrStack
{
	int numIndex;
	void* arrPointers[STACK_LENGTH];
} VoidArrStack;

VoidArrStack* initializeVoidArrStack()
{
	VoidArrStack arrStack;
	VoidArrStack* pntArrStack = calloc(1, sizeof(VoidArrStack));
	arrStack.numIndex = 0;
	*pntArrStack = arrStack;
	return pntArrStack;
}

void addNumberToStack(VoidArrStack** pntArrStack)
{
	VoidArrStack* arrStack = *pntArrStack;
	int numInput;
	printf("Size of Void*: %d\n", sizeof(void*));
	printf("%s", "Please enter a number: ");
	scanf("%d", &numInput);
	
	printf("Enter numbered!\n");
	
	int* pntInput;
	pntInput = calloc(1, sizeof(int));
	*pntInput = numInput;
	void* voidInput = pntInput;
	
	printf("%d\n", arrStack -> numIndex);
	
	printf("Saved memory!\n");
	arrStack -> arrPointers[arrStack -> numIndex] = voidInput;
}

void printCurrentStack(VoidArrStack** pntArrStack)
{
	printf("%s",  "Printing number!");
	VoidArrStack* arrStack = *pntArrStack;
	int* pntNumber = (int*)(arrStack -> arrPointers[arrStack -> numIndex]);
	printf("Popped %d!\n", *pntNumber);
}

int main(int argCount, char** argStrings)
{
	int numValue = 10;
	void* pntVoid = &numValue;
	
	VoidArrStack* arrStack = initializeVoidArrStack();
	VoidArrStack** pntArrStack = &arrStack;
	addNumberToStack(pntArrStack);
	printCurrentStack(pntArrStack);
	
	return 0;
}

