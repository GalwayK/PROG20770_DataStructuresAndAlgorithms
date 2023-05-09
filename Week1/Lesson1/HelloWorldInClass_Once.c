// Import statement for standard input and output.
#include<stdio.h>

char strMyName[] = "Kyle";

void funcHelloWorld(char strUserName[])
{
	printf("Hello %s! My name is %s! Glad to meet you!\n", strUserName, strMyName);
}


// Main method - beginning of code execution. 
int main(int argc, char** argv)
{	
	printf("Please enter your name: ");
	char strUserName[255];
	scanf("%s", &strUserName);
	
	funcHelloWorld(strUserName);		
	return 0;
}
