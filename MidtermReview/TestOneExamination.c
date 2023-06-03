#include<stdio.h>
#include<stdlib.h>

void passArrayIntoFunction();

int main(int argCount, char** argStrings)
{
	int* arrNumbers = malloc(sizeof(int) * 3);
	*arrNumbers = 97;
	*(arrNumbers + 1) = 98;
	*(arrNumbers + 2) = 99;
	int lengthArray = 3;
	
	printf("Pointer value: %p Pointer address: %p\n", arrNumbers, &arrNumbers);
	printf("Index value: %d Index address: %p\n\n", *arrNumbers, &*arrNumbers);
	printf("(Index Address) %p == %p (Pointer Value)\n\n", &arrNumbers[0], 
		arrNumbers);
		
	printf("The value of the pointer is passed to the function.\nIt's value is "
		"%p of type, 'pointer-to-integer'.\n", arrNumbers);
		
	printf("\nThe pointer itself is not passed to the function: \n(Pointer "
		"Address) %p != ", &arrNumbers);
		
	passArrayIntoFunction(arrNumbers);
	free(arrNumbers);
}

void passArrayIntoFunction(int* arrNumbers)
{
	printf("%p (New Pointer Address)\nOnly the pointer's value is passed.\n", 
		&arrNumbers);
	
	// The value passed is of type, "pointer-to-integer," (call-by-value).
	printf("\nThe value passed to this function itself is: %p.\nIt is of type "
		"'pointer-to-integer' (pass by value).\n\n", arrNumbers);
	
	// Retrieving array contents with dereferencing (call-by-reference).
	puts("We can retrieve the array elements with dereferencing (pass by "
		"reference).");
		
	printf("Value 1 of the array: %d stored at address %p\n", *arrNumbers++,
		arrNumbers);
	printf("Value 2 of the array: %d stored at address %p\n", *arrNumbers++, 
		arrNumbers);
	printf("Value 3 of the array: %d stored at address %p\n", *arrNumbers, 
		arrNumbers);
}
