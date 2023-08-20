#include<stdio.h>
#include<stdlib.h>

void mySwap(int* arrNumbers, int indexOne, int indexTwo);

void printArray(int* arrNumbers, int numLength);

void myShellSort(int* arrNumbers, int numLength);

void ShellSort(int* arrNumbers, int numLength);

int main(int argCount, char** argStrings)
{
	puts("Learning Shell sort!");
	int arrNumbers[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	int numLength = 9;
	
	printArray(arrNumbers, numLength);
	myShellSort(arrNumbers, numLength);
	printArray(arrNumbers, numLength);
}

void mySwap(int* arrNumbers, int indexOne, int indexTwo)
{
		int temp = arrNumbers[indexOne];
		arrNumbers[indexOne] = arrNumbers[indexTwo];
		arrNumbers[indexTwo] = temp;
}

void printArray(int* arrNumbers, int numLength)
{
	puts("Printing array!");
	for (int i = 0; i < numLength; i++)
	{
		printf("Index #%d: %d\n", i, arrNumbers[i]);
	}
}

void myShellSort(int* arrNumbers, int numLength)
{
	for (int increment = numLength / 2; increment > 0; increment /= 2)
	{
		for (int i = increment; i < numLength; i++)
		{
			int j = i;
			while(j + increment < numLength)
			{
				if (arrNumbers[j] > arrNumbers[j + increment])
				{
					mySwap(arrNumbers, j, j + increment);
					j -= increment;	
				}
				else 
				{
					j += increment;	
				}
			}
		}
	}
}

