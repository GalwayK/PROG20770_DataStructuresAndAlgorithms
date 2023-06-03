#include<stdio.h>

int main(int argCount, char** argStrings)
{
	int* pntA = (int*)8;
	
	printf("%p\n", pntA);
	printf("%d\n", *pntA);
}
