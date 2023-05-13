#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>

int generateRandomNumber(int intMin, int intMax)
{
	int intRandom = 0;
	if (intMin > intMax)
	{
		int intTemp = intMin;
		intMin = intMax;
		intMax = intTemp;
	}
	
	srand(time(NULL));
	intRandom = (rand() % (intMax - intMin)) + intMin;
	return intRandom;
}

void guessNumberGame()
{
	int intMax = 10;
	int intMin = 1;
	int intGuess = 0;
	int intAnswer = generateRandomNumber(intMin, intMax);
	
	printf("Guess a number between 1 and 10: ");
	scanf("%d", &intGuess);
	if (intGuess == intAnswer)
	{
		printf("Correct!\n");
	}
	else 
	{
		if (intGuess > intAnswer)
		{
			printf("Too high!\n");
		}
		else 
		{
			printf("Too low!\n");
		}
		guessNumberGame();
	}	
}

void runGuessNumberGame()
{
	puts("Welcome to the number guessing game!");
	guessNumberGame();
	char chaPlayAgain = 'n';
	printf("Would you like to play again?: ");
	
	// C's input buffer functions like Java's.
	fflush(stdin);
	scanf("%c", &chaPlayAgain);
	if (tolower(chaPlayAgain) == 'y')
	{
		runGuessNumberGame();
	}
	else 
	{
		printf("Thanks for playing!");
	}
}

// Main function
int main(int argCount, char** argStrings)
{
	puts("Hello world!");
	runGuessNumberGame();
}
