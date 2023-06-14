#include<string.h>
#include<stdio.h>

void reverseString();

void altReverseString();

void altAltReverseString();

int main(int argCount, char** argStrings)
{
	char stringWord[] = "Hello world!";
	int wordLength = strlen(stringWord);
	printf("Reverse String with function 1: ");
	reverseString(stringWord, wordLength);
	printf("\nReversed String with function 2: ");
	altReverseString(stringWord);
	printf("\nReversed String with fixed function 2: ");
	altAltReverseString(stringWord);
}

void reverseString(char* stringWord, int wordLength)
{
	printf("%c", stringWord[wordLength - 1]);
	
	if (wordLength > 1)
	{
		reverseString(stringWord, wordLength - 1);
	}
}

void altReverseString(char* stringWord)
{
	if (*stringWord != '\0')
	{
		altReverseString(++stringWord);
		printf("%c", *stringWord);
		
	}
}

void altAltReverseString(char* stringWord)
{
	if (*stringWord != '\0')
	{
		altAltReverseString(stringWord + 1);
		printf("%c", *stringWord);
	}
}
