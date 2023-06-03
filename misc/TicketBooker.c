#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define SIZE 10

void bookFirstClass();

void bookEconomy();

int checkFirst();

int checkEco();

bool isPlaneFull();

int main(void)
{
	int numEcoSeat;
	int numFirstClassSeat;
    int seats[SIZE];
    int type;

    do 
    {
		printf("Please type 1 for first class or 2 for economy. Type -1 to end "
			"the program...\n");
			
	    scanf("%d", &type);
        if (type == 1)
        {
            bookFirstClass(seats);
        }
        else if (type == 2)
        {
            bookEconomy(seats);
        }
        else 
        {
        	puts("Invalid entry...\n");
		}
    } while (type != -1 && isPlaneFull(seats));
   
   	puts("All seats full, departing...");
}

void bookFirstClass(int* seats, int* pntType)
{
	int numFirstClassSeat = checkFirst(seats);
	
	if (numFirstClassSeat != -1)
	{
		printf("Booked seat number %d...\n", numFirstClassSeat);
		seats[numFirstClassSeat] = 1;
	}
	else 
	{
		int numEconomySeat = checkEco(seats);
		if (numEconomySeat != -1)
		{
			short ticketChoice;
			printf("%s", "First Class is full, would you like to change your "
				"seat to economy? 1 for yes: ");
			scanf("%hd", &ticketChoice);
			
			switch (ticketChoice)
			{
				case 1: 
				printf("Booked seat number %d\n", numEconomySeat);
					seats[numEconomySeat] = 1;
					break;
				default: 
					printf("Flight leaves in three hours...\n");
					break;
			}
		}
	}
}

void bookEconomy(int* seats, int* pntType)
{
	int numEcoSeat = checkEco(seats);
	
	if (numEcoSeat != -1)
	{
		printf("Booked seat number %d...\n", numEcoSeat);
		seats[numEcoSeat] = 1;
	}
	else
	{
		int numFirstClassSeat = checkFirst(seats);
		if (numFirstClassSeat != -1)
		{
			short ticketChoice;
		
			printf("%s", "Economy class is full, would you like to change your "
				"seat to First Class?: 1 for yes: ");	
			scanf("%hd", &ticketChoice);
			
			switch (ticketChoice)
			{
				case 1: 
					printf("Booked seat number %d...\n");
					seats[numFirstClassSeat] = 1;
					break;
				default: 
					puts("Flight leaves in three hours...");
					break;
			}
		}
	}
}

int checkFirst(int seats[])
{
    for (int i = 0; i < 5; i++)
    {
        if (seats[i] != 1)
        {
            return i;
        }
    }
    return -1;
}

int checkEco(int seats[])
{
    for (int i = 5; i < 10; i++)
    {
        if (seats[i] != 1)
        {
            return i;
        }
    }
    return -1;
}

bool isPlaneFull(int* seats)
{
	return !(checkFirst(seats) == -1 && checkEco(seats) == -1);
}
