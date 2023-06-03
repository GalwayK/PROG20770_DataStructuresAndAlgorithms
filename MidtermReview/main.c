#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#define ARR_LENGTH 10

static double* arrNumbers;
static int arrLength;

static int currentIndex = 0;

void create(void);

void fill();

void enlarge(void);

void dereferenceArray(void);

void print(void);

double globalDouble;
static long globalStaticNumber;

void reviewMidterm(void);

void reviewStringCompare(void);

void reviewOutputErrors(void);

void reviewMemoryAllocation(void);

void exerciseHandleDoubleArray(void);

int main(int argc, char** argv) 
{
	// reviewMidterm();
	// reviewStringCompare();
	//reviewOutputErrors();
	reviewMemoryAllocation();
	exerciseHandleDoubleArray();
	
	printf("Program complete!");
	return 0;
}

void reviewMidterm(void)
{
	puts("Reviewing for the midterm!");
	
	bool localBool;
	int arrNumbers[ARR_LENGTH];
	bool arrBoolean[ARR_LENGTH];
	static long localStaticNumber;
	
	printf("%lf\n", globalDouble);
	printf("%hd\n", localBool);
	printf("Local static: %ld\n", localStaticNumber);
	printf("Global static: %ld\n", globalStaticNumber);
	printf("Sizeof: %hd\n", sizeof(long long));
}

void reviewStringCompare(void)
{
	char str[] = "hey";
	int num = (strcmp(str, "z") >= 0 ? 42 : 22);
	printf("Num = %d, Cmp = %d\n", num, strcmp(str, "z"));
	printf("Num = %d, Cmp = %d\n", num, strcmp("z", "h"));
	
	printf("%hd = h, %hd = z\n", 'h', 'z');
}

void reviewOutputErrors(void)
{
	unsigned short unsignedNumber = 16000;
	long long longNumber;
	char* strMessage = "Data structures are cool.";
	
	printf("The number is %hu\n", unsignedNumber);
	
	char strInput[] = "Data structures are cool.";
	
	scanf("%25s", strInput);
	printf("%s", strInput);
	printf("%s", "hello");
}

void reviewMemoryAllocation(void)
{
	unsigned short* arrShorts = calloc(1000, sizeof(unsigned short));
	if (arrShorts == NULL)
	{
		printf("%s\n", "An error occured during allocation.");
	}
	else 
	{
		puts("Successfully allocated memory.");
	}
	
	unsigned short* arrNumbers = malloc(sizeof(unsigned short) * 1000);
	realloc(arrShorts, sizeof(unsigned short) * 500);
	realloc(arrNumbers, sizeof(unsigned short) * 500);
	
	if (arrShorts == NULL || arrNumbers == NULL)
	{
		printf("%s\n", "An error occured during reallocation.");
	}
	else 
	{
		puts("Successfully reallocated memory.");
	}
}

void exerciseHandleDoubleArray()
{
	create();
	enlarge();
	print();
	
	int numInput;
	int* pntInput = &numInput;
	printf("%s", "Please enter a number: ");
	scanf("%d", pntInput);
	
	fill(pntInput);
	print();
	
	dereferenceArray();
}

void create()
{
	arrNumbers = (double*)malloc(500 * sizeof(double));
	arrLength = 500;
	printf("Allocated memory to %p\n", arrNumbers);
}

void print()
{
	for (int i = 0; i < arrLength; i++)
	{
		printf("%d. %lf\n", i, arrNumbers[i]);
	}
}

void fill(int* pntNumber)
{
	for (int i = 0; i < arrLength; i++)
	{
		arrNumbers[i] = *pntNumber;
	}
}

void enlarge()
{
	realloc(arrNumbers, sizeof(double) * 1000);
	arrLength = 1000;
}

void dereferenceArray()
{
	printf("Freeing memory at %p!\n", arrNumbers);
	arrNumbers = arrNumbers - arrLength;
	arrNumbers = NULL;
}



