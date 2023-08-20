#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Assignment4_StudentList.h"

// Global Options and Count for displaying to user

static int numOptions = 7;

static char* arrOptions[] = {"Add a Student",
	"Update a Student",
	"Print Student Tree In Order",
	"Display Students by Grade Percent",
	"Display Students by Student Age", 
	"Search for Student by Student Number", 
	"Quit Application"};

// Global Template Variables to hold temporary data from input

static char txtStudentNumber[255];
static char txtFirstName[255];
static char txtLastName[255];
static char txtCourseCode[255];
static int numAge;
static int gradeOne;
static int gradeTwo; 
static int gradeThree; 
static int gradeFour;

// Get Valid Integer Input 
void getIntInput(int* pntInput, char* txtPrompt)
{
	printf("%s: ", txtPrompt);
	int numInputs = 0; 
	
	fflush(stdin);
	numInputs = scanf("%d", pntInput);
	
	if (numInputs == 0 || *pntInput < 0)
	{
		puts("Error: Please enter an integer...");
		getIntInput(pntInput, txtPrompt);
	}
}

// Get String Input
void getStringInput(char* pntInput, char* txtPrompt)
{
	printf("%s: ", txtPrompt);
	int numInputs = 0; 
	
	fflush(stdin);
	numInputs = scanf("%s", pntInput);
	
	if (numInputs == 0)
	{
		puts("Error: Please enter a string...");
		getStringInput(pntInput, txtPrompt);
	}
}

// Print Line Header throughout application
void printHeader()
{
	puts("\n========================\n");
}

// Print all options to user
void printOptions()
{
	puts("Please select an option: \n");
	
	for (int i = 0; i < numOptions; i++)
	{
		printf("%d. %s\n", i + 1, arrOptions[i]);
	}
}

// Print all Fields for Student
void printStudent(Student* pntStudent)
{
	puts("\nPrinting Student!");
	printf("\tStudent Number: %s\n", pntStudent -> txtStudentNumber);
	
	puts("Printing Information...");
	StudentInformation* pntInformation = pntStudent -> pntStudentInformation;
	printf("\tCourse Code: %s\n", pntInformation -> txtCourseCode);
	printf("\tFirst Name: %s\n", pntInformation -> txtFirstName);
	printf("\tLast Name: %s\n", pntInformation -> txtLastName);
	printf("\tStudent Age: %d\n", pntInformation -> numAge);
	
	
	puts("Printing Grades...");
	StudentGrade* pntGrade = pntStudent -> pntStudentGrade; 
	printf("\tGrade One: %d\n", pntGrade -> numGrades[0]);
	printf("\tGrade Two: %d\n", pntGrade -> numGrades[1]);
	printf("\tGrade Three: %d\n", pntGrade -> numGrades[2]);
	printf("\tGrade Four: %d\n", pntGrade -> numGrades[3]);
	printf("\tGrade Total: %d\n", getStudentGradeTotal(pntStudent));
	printf("\tGrade Average: %g\n", getStudentGradeAverage(pntStudent));

}

// Print Student Node retrieved from Student Binary Tree
void printStudentNode(StudentNode* pntStudentNode, int* pntOrder, int numDepth)
{
	printf("\nLocated Student #%d at tree depth %d\n", (*pntOrder)++, numDepth);
	Student* pntStudent = getStudentFromStudentNode(pntStudentNode);
	printStudent(pntStudent);
}

// Print In Order Traveral of Student Binary Node
void printStudentNodeInOrder(StudentNode* pntStudentNode, int* pntOrder, int numDepth)
{
	if (pntStudentNode == NULL)
	{
		return; 
	}
	else 
	{
		printStudentNodeInOrder(pntStudentNode -> pntLeftNode, pntOrder, numDepth + 1);
		printStudentNode(pntStudentNode, pntOrder, numDepth);
		printStudentNodeInOrder(pntStudentNode -> pntRightNode, pntOrder, numDepth + 1);
	}
}

// Print In Order Traversal of Student Binary Tree 
void printStudentTreeInOrder(StudentTree* pntStudentTree)
{
	int numDepth = 1; 
	int numOrder = 1; 
	printStudentNodeInOrder(pntStudentTree -> pntRoot, &numOrder, numDepth);
}

// Add a Student to Student Binary Tree
void addStudent(StudentTree* pntStudentTree)
{
	int intStudentNumber;
	getIntInput(&intStudentNumber, "Please enter the student number");
	snprintf(txtStudentNumber, 255, "%d", intStudentNumber);
	
	getStringInput(txtCourseCode, "Please enter the student's course code");
	getStringInput(txtFirstName, "Please enter the student's first name");
	getStringInput(txtLastName, "Please enter the student's last name");
	
	getIntInput(&numAge, "Please enter the student's age");
	getIntInput(&gradeOne, "Please enter grade one");
	getIntInput(&gradeTwo, "Please enter grade two");
	getIntInput(&gradeThree, "Please enter grade three");
	getIntInput(&gradeFour, "Please enter grade four");
	
	Student* pntStudent = initializeDetailedStudent(txtStudentNumber, 
	txtFirstName, txtLastName, numAge, txtCourseCode, gradeOne, gradeTwo, gradeThree, gradeFour);

	int result = addStudentToStudentTree(pntStudentTree, txtStudentNumber, txtFirstName, txtLastName, numAge, txtCourseCode, gradeOne, gradeTwo, gradeThree, gradeFour);
	if (result == 0)
	{
		puts("Student successfully added!");
	}
	else 
	{
		puts("Error, student not added. You may be out of memory or attempting to add a duplicate student number!");
	}

}

// Update a Student after searching for them in the binary tree
void updateStudent(StudentTree* pntStudentTree)
{
	int searchNumber;
	getIntInput(&searchNumber, "Please enter student number to search");
	snprintf(txtStudentNumber, 255, "%d", searchNumber);
	
	int searchDepth = 0;
	
	Student* searchStudent = searchForStudentByStudentNumber(pntStudentTree, txtStudentNumber, &searchDepth);
	
	printf("Found student at depth %d\n", searchDepth);
	
	if (searchStudent == NULL)
	{
		printf("Error, student not found!");
	}
	else 
	{
		puts("Please enter updated student information...");
		getStringInput(txtCourseCode, "Please enter the student's course code");
		getStringInput(txtFirstName, "Please enter the student's first name");
		getStringInput(txtLastName, "Please enter the student's last name");
		
		getIntInput(&numAge, "Please enter the student's age");
		getIntInput(&gradeOne, "Please enter grade one");
		getIntInput(&gradeTwo, "Please enter grade two");
		getIntInput(&gradeThree, "Please enter grade three");
		getIntInput(&gradeFour, "Please enter grade four");
		
		StudentInformation* studentInfo = searchStudent -> pntStudentInformation; 
		
		strcpy(studentInfo -> txtCourseCode, txtCourseCode);
		strcpy(studentInfo -> txtFirstName, txtFirstName);
		strcpy(studentInfo -> txtLastName, txtLastName);
		studentInfo -> numAge = numAge;
		
		StudentGrade* studentGrade = searchStudent -> pntStudentGrade;
		
		studentGrade -> numGrades[0] = gradeOne; 
		studentGrade -> numGrades[1] = gradeTwo;
		studentGrade -> numGrades[2] = gradeThree;
		studentGrade -> numGrades[3] = gradeFour; 
		puts("Student updated!");
	}
}

// Print Allocated Array of Students
void printStudentArray(StudentArray* studentArray)
{
	for (int i = 0; i < studentArray -> numCount; i++)
	{
		printStudent(getStudentFromArray(studentArray, i));
	}
}

// Create, sort, and print an Allocated Array of Students by Grade
void sortStudentsByGradeAverage(StudentTree* pntStudentTree)
{
	StudentArray* studentArray = getStudentArray(pntStudentTree);
	sortStudentArrayByGrade(studentArray);
	printStudentArray(studentArray);
}

// Create, sort, and print an Allocated Array of Students by Age
void sortStudentsByAge(StudentTree* pntStudentTree)
{
	StudentArray* studentArray = getStudentArray(pntStudentTree);
	int swapCount = 0; 
	printf("Sorting array of length %d with Quick Sort...\n", studentArray -> numCount);
	sortStudentArrayByAge(studentArray, 0, studentArray -> numCount - 1, &swapCount);
	printf("Array sorted after %d swaps!\n", swapCount);
	printStudentArray(studentArray);
}

// Search for Student in Student Binary Tree by Student Number
void searchByStudentNumber(StudentTree* pntStudentTree)
{
	int searchNumber; 
	getIntInput(&searchNumber, "Please enter student number to search");
	
	snprintf(txtStudentNumber, 255, "%d", searchNumber);
	int searchDepth = 0; 
	Student* searchStudent = searchForStudentByStudentNumber(pntStudentTree, txtStudentNumber, &searchDepth);
	
	printf("Search completed at depth %d\n", searchDepth);
	
	if (searchStudent == NULL)
	{
		printf("Error, student not found!");
	}
	else 
	{
		puts("Found student!");
		printStudent(searchStudent);
	}
}

// Recursively Clear Tree of Memory after application has finished
void clearTreeMemory(StudentTree* pntStudentTree)
{
	puts("Clearing memory...");
	clearStudentTree(pntStudentTree);
	puts("Memory cleared!");
}


// Main Function for running application
int main(int argCount, char** argStrings) 
{
	StudentTree* pntStudentTree = initializeBlankStudentTree();
	puts("Welcome to the Student Database Tracking Application by Kyle Galway");
	
	bool isApplicationActive = true;
	int numInputSelection = -1;
	
	while (isApplicationActive)
	{
		printHeader();
		printOptions();
		getIntInput(&numInputSelection, "Please select an option");
		printHeader();
		switch (numInputSelection)
		{
			case 1: 
				puts("Adding student...");
				addStudent(pntStudentTree);
				break;
			case 2: 
				puts("Updating student...");
				updateStudent(pntStudentTree);
				break;
			case 3: 
				puts("Printing Student Tree In Order");
				printStudentTreeInOrder(pntStudentTree);
				break;
			case 4: 
				puts("Displaying Students by Grade Percent...");
				sortStudentsByGradeAverage(pntStudentTree);
				break;
			case 5: 
				puts("Displaying Students by Age...");
				sortStudentsByAge(pntStudentTree);
				break; 
			case 6: 
				puts("Searching for Student by Student Number...");
				searchByStudentNumber(pntStudentTree);
				break; 
			case 7: 
				puts("Quitting application...");
				clearTreeMemory(pntStudentTree);
				isApplicationActive = false; 
				break;
			default: 
				puts("Please enter a valid option...");
				break;
		}
	}
	puts("Thank you for using this application!\nI am glad to have learned Data Structures this semester!");
	
	return 0;
}
