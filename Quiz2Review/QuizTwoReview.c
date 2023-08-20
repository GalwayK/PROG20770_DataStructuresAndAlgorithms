#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define CARDS_LENGTH 10

struct card 
{
	char face[10];
	char suit[10];
} varCard, *pntCard, *arrCards[CARDS_LENGTH];

struct card* createCard();

void updateCard(struct card* pntCard);

void printCard(struct card* pntCard);

void printCards();

int main(int argCount, char** argStrings)
{
	printCards();
}

struct card* createCard()
{
	struct card* pntCard = (struct card*)malloc(sizeof(struct card));
	struct card varCard;
	*pntCard = varCard;
	return pntCard;
}

void updateCard(struct card* pntCard)
{
	puts("Updating card!");
	strcpy(pntCard -> face, "Jack");
	strcpy(pntCard -> suit, "Blades");
}

void printCards()
{
	updateCard(&varCard);
	printCard(&varCard);
	
	pntCard = createCard();
	updateCard(pntCard);
	printCard(pntCard);
	
	for (int i = 0; i < CARDS_LENGTH; i++)
	{
		printf("On card %d\n", i);
		arrCards[i] = createCard();
		updateCard(arrCards[i]);
		printCard(arrCards[i]);
		free(arrCards[i]);
	}
	
	free(pntCard);
	
	puts("Application Complete!");
}

void printCard(struct card* pntCard)
{
	puts("Printing card!");
	printf("The card is %s of %s!\n", pntCard -> face, pntCard -> suit);
}

