#include<stdio.h>
#include<string.h>
#include<stdbool.h>

typedef struct 
{
	int id;
	char firstName[255];
	char lastName[255];
} Student;



int main(int argCount, char** argStrings)
{
	printf("%s", "Hello World!");
	Student studentOne;
	Student* pntStudentOne = &studentOne;
}
