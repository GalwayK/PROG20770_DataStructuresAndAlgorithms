#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#define NUM_STUDENTS 5

static char* months[] = {"January", "February", "March", "April", "May", "June", 
	"July", "August", "September", "October", "November", "December"};
static int numStudents = 0;

typedef struct 
{
	char* firstName;
	char middleName[21];
	char* lastName;
} FullName;

typedef struct 
{
	int day;
	int month;
	int year;
} Date;

typedef struct 
{
	FullName fullName;
	Date enrollmentDate;
	Date graduationDate;
	int studentId;
	double dblGPA;
} Student;

Student* createStudent();

void createCard();

void printStudent(Student* pntStudent);

void updateStudent(Student* pntStudent);

void CharToLower(char* pntChar);


int main(int argCount, char** argStrings)
{
	Student* arrStudents[NUM_STUDENTS];
	
	for (int i = 0; i < NUM_STUDENTS; i++)
	{
		printf("Enter student %d details below!\n", i + 1);
		arrStudents[i] = createStudent();
	}
	
	while (true)
	{
		puts("");
		for (int i = 0; i < NUM_STUDENTS; i++)
		{
			printf("Student %d: ", i + 1);
			
			printStudent(arrStudents[i]);
			puts("");
		}
		
		fflush(stdin);
		char checkContinue;
		printf("%s", "Do you want to update either of the students (y/Y): ");
		scanf("%c", &checkContinue);
		CharToLower(&checkContinue);
		
		if (checkContinue  == 'y')
		{
			fflush(stdin);
			int numIndex;
			printf("%s", "Please enter the student ID of the student you would "
				"you like to update: ");
			int numEffected = scanf("%d", &numIndex);
			printf("Affected %d variables\n", numEffected);
			if (numEffected = 1 && numIndex <= numStudents && numIndex >= 1)
			{
				updateStudent(arrStudents[numIndex - 1]);	
			}
			else 
			{
				puts("Error, please enter the ID of a student in the system.");
				continue;
			}
		}
		else 
		{
			break;
		}
	}
	
	puts("Thank you for using this student management system!");
	for (int i = 0; i < NUM_STUDENTS; i++)
	{
		printf("\nFreeing %p\n", arrStudents[i]);
		free(arrStudents[i] -> fullName.firstName);
		free(arrStudents[i] -> fullName.lastName);
		free(arrStudents[i]);
	}
}

void printStudent(Student* pntStudent)
{
	printf("%s %s!\n", 
		pntStudent -> fullName.firstName, 
		pntStudent -> fullName.lastName);
		
	printf("Student Name: %s %s\nStudent ID: %d\nStudent GPA %.2lf\nEnrollment Date: %d %s %d\n", 
		pntStudent -> fullName.firstName, 
		pntStudent -> fullName.lastName, 
		pntStudent -> studentId, 
		pntStudent -> dblGPA,
		pntStudent -> enrollmentDate.day,
		months[pntStudent -> enrollmentDate.month],
		pntStudent -> enrollmentDate.year);
}

Student* createStudent()
{
	Student varStudent;
	
	char strInput[255];
	
	printf("%s", "Please enter the student's first name: ");	
	scanf("%s", strInput);
	varStudent.fullName.firstName = malloc(sizeof(char) * (strlen(strInput) + 1));
	strcpy(varStudent.fullName.firstName, strInput);
	printf("You have entered: %s\n", varStudent.fullName.firstName);
	
	printf("%s", "Please enter the student's last name: ");
	scanf("%s", strInput);
	varStudent.fullName.lastName = malloc(sizeof(char) * (strlen(strInput) + 1));
	strcpy(varStudent.fullName.lastName, strInput);
	printf("You have entered: %s\n", varStudent.fullName.lastName);
	
	varStudent.studentId = numStudents++ + 1;
	printf("%s", "Please enter the student's GPA: ");
	scanf("%lf", &varStudent.dblGPA);
	
	time_t currentTime = time(NULL);
	struct tm enrollmentTime = *localtime(&currentTime);
	varStudent.enrollmentDate.day = enrollmentTime.tm_mday;
	varStudent.enrollmentDate.month = enrollmentTime.tm_mon;
	varStudent.enrollmentDate.year = enrollmentTime.tm_year + 1900;
	
	Student* pntStudent = malloc(sizeof(Student));
	*pntStudent = varStudent;
		
	return pntStudent;
}

void updateStudent(Student* pntStudent)
{
	char strFirstName[255];
	char strLastName[255];
	int studentId;
	double dblGPA;
	
	printf("%s", "Please enter the student's first name: ");	
	scanf("%s", strFirstName);
	strcpy(pntStudent -> fullName.firstName, strFirstName);
	
	printf("%s", "Please enter the student's last name: ");
	scanf("%s", strLastName);
	strcpy(pntStudent -> fullName.lastName, strLastName);
	
	printf("%s", "Please enter the student's GPA: ");
	scanf("%lf", &dblGPA);
	pntStudent -> dblGPA = dblGPA;
	
	printf("Updated student #%d", pntStudent -> studentId);
}

void CharToLower(char* pntChar)
{
	if (*pntChar > 65 && *pntChar < 91)
	{
		*pntChar += 32;
	}
}
