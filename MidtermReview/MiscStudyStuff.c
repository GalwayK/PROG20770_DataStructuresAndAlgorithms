#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdbool.h>

int main(int argCounts, char** argStrings)
{
	int numValue = 2;
	int* pntValue = &numValue;
	void* pntVoid = pntValue;
	
	int* newPnt;
	
	newPnt = pntVoid;
	printf("%d\n", *newPnt);
	
	puts("Testing Random Things!");
}
