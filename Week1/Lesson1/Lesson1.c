#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// The include lines are used to import header files. 
// System includes use <> and custom includes use " " 
// Include statements are handled by the C preprofessor.

const double NUM_PI = 355.0 / 113;

void funcPrintName(int intRepetitions, char* strFirstName)
{
	if (intRepetitions > 0)
	{
		funcPrintName(intRepetitions - 1, strFirstName);
		printf("%d. Hello %s\n", intRepetitions, strFirstName);
	}
}

void funcMultiplyPi()
{
	double numMultiplier;
	
	printf("Please enter a number to multiply by Pi: ");
	int intResult = scanf("%lf", &numMultiplier);
	
	// Flush standard input of extra entries.
	fflush(stdin);
	
	if (intResult < 1)
	{
		printf("Error in input!");
	}
	else 
	{
		printf("Pi multiplied by %f is %f", numMultiplier, NUM_PI * numMultiplier);
	}
}

// Main function 
int main(int argc, char** argv)
{
	printf("Please enter your name: ");
	
	// Strings are just arrays of char.
	
	int intFirstNameLength = 255;
	char strFirstName[intFirstNameLength];
	
	char strFirstNameLength[255];
	sprintf(strFirstNameLength, "%d", intFirstNameLength);
	char strTemplate[255] = "%";
	strcat(strTemplate, strFirstNameLength);
	strcat(strTemplate, "s");
	
	scanf(strTemplate, &strFirstName);
//	
//	// Must use print f
	funcPrintName(10, strFirstName);
//	funcMultiplyPi();
//	printf("Size of int is %d bytes\n", sizeof(int));
//	printf("Size of long int is %d bytes\n", sizeof(long int));
	return 0;
}

// Definitions
/*
Preprocessor: Works before compiler, adds header files. 
Linker: Combines object files into executable files. 
Source File: The human readable code files. 
Header File: Source files which only contain declarations. 
Object File: The compiled source files. 
*/

// Four Main Properties of Variables 
/*
Data Type: 
Name: 
Value: 
Scope: 
*/

// Data Types in C
/*
char: 8 bits (1 byte)
short int: 16 bit numbers
int: 32 bit numbers.
long int: 32 to 64 bit numbers.
long long int: 64 bit numbers.
float: 32 bit decimal numbers with 8 digits of precision.
double: 64 bit decimal numbers with 16 digits of precision.

C numbers can be signed or unsigned. 
Unsigned numbers can hold twice as many values, but cannot be negative.
*/

/*
In C we should always give a variable an initial value.

Static in C only means that we can only see a variable inside its module. 
This is not the same as Java - C is not an object oriented language.
*/
