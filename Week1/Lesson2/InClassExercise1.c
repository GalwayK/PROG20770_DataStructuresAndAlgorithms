#include<stdio.h>
#include<stdbool.h>

void funcDeclareVariables()
{
	int intSum = 1;
	printf("%d\n", intSum);
	
	bool isCorrect = false;
	printf("%b\n", isCorrect);
	
	char grade = 'A';
	printf("%c\n", grade);
	
	short int age = 25;
	printf("%d\n", age);
	
	
	short shoAge = 25;
	printf("%d\n", shoAge);
	
	double dblRadius = 100.0;
	printf("%lf\n", dblRadius);
	
	float floAverage = 12.5F;
	printf("%f\n", floAverage);
	
	unsigned int intRegisterSP = 1;
	printf("%u\n", intRegisterSP);
	
	unsigned char chaByte = 'A';
	printf("%c\n", chaByte);
	
	long int intBigNum = 9999999999999;
	printf("%ld\n");
	
	long lngBigNum = 888888888888888;
	printf("%ld\n", lngBigNum);
	
	long long int intReallyBigNum = 1;
	printf("%lld\n", intReallyBigNum);
	
	signed int intJustAnInt = 2;
	printf("%d", intJustAnInt);
	
}

int main(int argCount, char** argStrings)
{
	printf("This is a lesson about variables!");
	
	funcDeclareVariables();
}
