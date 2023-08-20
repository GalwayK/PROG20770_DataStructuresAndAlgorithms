#include "Assignment4_Student.h"
#include <string.h>
#include <stdlib.h>

// Initialize a Pointer to an Empty Student Structure
Student* initializeBlankStudent()
{
	Student* pntStudent = malloc(sizeof(Student));
	pntStudent -> pntStudentGrade = NULL;
	pntStudent -> pntStudentInformation = NULL; 
	strcpy(pntStudent -> txtStudentNumber, "");
	
	return pntStudent;
}

// Initialize a Pointer to a Detailed Student Structure
Student* initializeDetailedStudent(char* txtStudentNumber, char* txtFirstName, char* txtLastName, 
	int numAge, char* txtCourseCode, int numGradeOne, int numGradeTwo, int numGradeThree, int numGradeFour)
{
	Student* pntStudent = initializeBlankStudent();
	
	strcpy(pntStudent -> txtStudentNumber, txtStudentNumber);
	
	StudentInformation* pntStudentInformation = initializeDetailedStudentInformation(txtFirstName, txtLastName, numAge, txtCourseCode);
	pntStudent -> pntStudentInformation = pntStudentInformation; 
	
	StudentGrade* pntStudentGrade = initializeDetailedStudentGrade(numGradeOne, numGradeTwo, numGradeThree, numGradeFour);
	pntStudent -> pntStudentGrade = pntStudentGrade; 
	
	return pntStudent;
}

// Get the Grade of a Student
int getStudentGradeTotal(Student* pntStudent)
{
	return getGradeTotal(pntStudent -> pntStudentGrade);
}

// Get the Grade Average of a Student
double getStudentGradeAverage(Student* pntStudent)
{
	return getGradeAverage(pntStudent -> pntStudentGrade);
}

// Clear a Student of allocated memory
void clearStudent(Student* student)
{
	free(student -> pntStudentInformation);
	free(student -> pntStudentGrade);
}
