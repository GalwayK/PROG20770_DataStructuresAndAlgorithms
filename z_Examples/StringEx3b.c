#include <stdio.h>
#include <string.h>

#define STR_SIZE 100

int main(int argc, char** argv) {
	
	// Input string from user
	char str[STR_SIZE] = "";
	printf("Please enter a string: ");
	scanf("%99[^\n]", str);
	
	// Build a new string
	char newStr[STR_SIZE];
	int len = strlen(str);
	int newIndex = 0;
	for (int index = 0; index < len; index+=2) {
	    newStr[newIndex++] = str[index];
	}
	
	// Add a null character
	newStr[newIndex] = '\0';
	
	// Print the result
	printf("%s\n", newStr);

}
