// Import statement for standard input and output.
#include<stdio.h>

char strMyName[] = "Kyle";

// Recursive function for printing name N number of times.
void funcHelloWorld(int intRepetitions, char strUserName[])
{
	if (intRepetitions > 1)
	{
		funcHelloWorld(intRepetitions - 1, strUserName);
	}
	
	printf("%d. Hello %s! My name is %s! Glad to meet you!\n", intRepetitions, strUserName, strMyName);
}


// Main method - beginning of code execution. 
int main(int argc, char** argv)
{	
	printf("Please enter your name: ");
	char strUserName[] = "User";
	scanf("%s", &strUserName);
	
	printf("Please enter a number (not too high please): ");
	int intRepetitions = 10;
	scanf("%d", &intRepetitions);
	
	funcHelloWorld(intRepetitions, strUserName);		
	return 0;
}
