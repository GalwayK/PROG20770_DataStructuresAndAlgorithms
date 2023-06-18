#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAXSTACK 100
#define ROGUEVALUE -2000000

typedef struct 
{
	int top;
	int arrStack[MAXSTACK];
} NumStack;

NumStack numStack;

void initStack(void)
{
	numStack.top = -1;
}

bool isEmpty(void)
{
	return numStack.top == -1;
}

void pushNum(int number)
{
	if (numStack.top == MAXSTACK - 1)
	{
		puts("The stack is full!");
	}
	else 
	{
		numStack.top++;
		numStack.arrStack[numStack.top] = number;
		printf("Filled value: %d\n", numStack.arrStack[numStack.top]);
	}
}

int popNum(void)
{
	if (isEmpty())
	{
		return ROGUEVALUE;
	}
	else 
	{
		int number = numStack.arrStack[numStack.top--];
		return number;
	}
}

typedef struct 
{
	int top;
	char arrStack[MAXSTACK];
} CharStack;

CharStack charStack;

void initCharStack(void)
{
	charStack.top = -1;
}

bool isCharEmpty(void)
{
	return charStack.top == -1;
}

void pushChar(char character)
{
	if (charStack.top == MAXSTACK - 1)
	{
		puts("The stack is full!");
	}
	else 
	{
		charStack.top++;
		charStack.arrStack[charStack.top] = character;
		printf("Filled value: %c\n", charStack.arrStack[charStack.top]);
	}
}

char popChar(void)
{
	if (isCharEmpty())
	{
		return ROGUEVALUE;
	}
	else 
	{
		char character = charStack.arrStack[charStack.top--];
		return character;
	}
}

char peekChar()
{
	if (isCharEmpty())
	{
		return ROGUEVALUE;
	}
	else 
	{
		char character = charStack.arrStack[charStack.top];
		return character;
	}
}

void exerciseNumStack(void)
{
	initStack();
	puts("Filling Stack!");
	for (int i = 0; i < 10; i++)
	{
		pushNum(i);
	}
	
	puts("Emptying Stack!");
	while (!isEmpty())
	{
		printf("Emptied Value: %d\n", popNum());
	}
}

void fillCharStack(void)
{
	char strWord[255];
	gets(strWord);
	for (int i = 0; strWord[i] != '\0' ; i++)
	{
		pushChar(strWord[i]);
		strWord;
		printf("Just taking a peek at: %c\n", peekChar());
	}
	
	pushChar('\0');
}

void  printCharStack(void)
{
	printf("%s", "The word you entered is: ");
	while (!isCharEmpty())
	{
		printf("%c", popChar());
	}
	puts("");
}

void exerciseCharStack()
{
	initCharStack();
	fillCharStack();
	printCharStack();
}


int main(int argCount, char** argStrings)
{
	// exerciseNumStack();
	exerciseCharStack();
	return 0;
}
