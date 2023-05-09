// Import statement for standard input and output.
#include<stdio.h>

void funcHelloWorld(int intRepetitions, char strFirstName[])
{
	for (int i = 0; i < intRepetitions; i++)
	{
		// C has no equivalent to template strings, so we must format methods.
		printf("Hello %s! Glad to meet you!\n", strFirstName);
	}
}

void funcMakeError()
{
	// Scanf seems like it will return default values if data type mismatches.
	int intError;
	scanf("%d", intError);
	printf("Error: %d", intError);
}

// Main method - beginning of code execution. 
int main(int argc, char** argv)
{	
/*
	printf("Please enter your name: ");
	char strFirstName[255];
	scanf("%s", &strFirstName);
	int intRepetitions = 10000;
	
	
	funcHelloWorld(intRepetitions, strFirstName);			
*/
	funcMakeError();
	return 0;
}

// Review Later 

/* 
Definitions
	High Level Languages: 
	Legacy Langauges: 
	Preprocessor: 
	Compiler: 
	Linker: 
	#include: 

C History
	C89 
		Publish Year: 
		Details: 
	C99
		Publish Year: 
		Details:  
	Which version used in course: 

C Compilation Lifeline: 
	.c Files: 
	.o Files: 
	.obj Files: 
	.h Files: 
	.cpp Files: 
	
How Compiler Processes Files: 
	.c Files: 
	.h Files: 
	
C Data Types: 
	
Questions for Prof: 
	1. Is there any quivalent to template strings or f-strings?
	2. How does C handle errors and exceptions? 
	3. 
*/

