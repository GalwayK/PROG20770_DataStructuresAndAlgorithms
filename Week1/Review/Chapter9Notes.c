#include<stdio.h>
#include<limits.h>
#include<math.h>

int main(int argC, char** argV)
{
	puts("Chapter 3 Review");
	printf("The max value for an integer is %d.\n", INT_MAX);
	printf("The min value for an integer is %d.\n", INT_MIN);
	printf("Overflow: %d\n", INT_MAX + 1);
	printf("Underflow: %d\n", INT_MIN - 1);
	
	int intZero;
	printf("%s", "Enter the denominator: ");
	scanf("%d", &intZero);
	
	int intDenominator = 10;
	if (intZero == 0)
	{
		printf("%s", "You cannot divide by zero!\n");
	}
	else 
	{
		printf("%.2lf\n", (double)intDenominator / intZero);
	}
	
	printf("%f", pow((double)20, 3));
	
	// Always make sure to purge leftover entries from the standard input.
	fflush(stdin);
	
	// We should use unsigned integers for integers that cannot be negative.
	unsigned int intCounter = 0;
	while (intCounter < 3)
	{
		printf("%d\n", intCounter++);
	}
}

// Chapter 3: Control Statements
/*
In the 1960s programming was done with goto statements, which were difficult to 
work with and produced a large number of errors. In response, control structures
were designed and implemented. All programs can be written with three control 
structures: sequence structure, selection structure, and repetition structure. 

Sequence Structure: 1. Programs run lines one after the other in sequence. 

Selection Structure: 1. If, 2. else if, and 3. else. 

Repetition Structure: 1. while, 2. do while, and 3. for. 

All C programs can be completed with these seven basic structures. 

In condition checking, any expression equal to 0 is false, and any expression 
not equal to 0 is true. Hence, 1 - 1 is false, while 0 + 1 is true. 

When printing a floating point number, we can add $%.2 f to display only two 
decmal places. The value will be rounded to the correct decimal place.

In industrial strength applications, you should check to ensure that integer 
overflow is not possible in an application. If they do overflow, they will 
flow back around to the minimum (or maximum) possible value. We should also 
ensure that it is not possible to divide by zero. 
*/
