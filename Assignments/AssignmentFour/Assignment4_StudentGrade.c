#include "Assignment4_StudentGrade.h"
#include <stdlib.h>
#include <stdio.h>

// Initialize a Pointer to a Blank Student Grade
StudentGrade* initializeBlankStudentGrade()
{
	StudentGrade* pntStudentGrade = malloc(sizeof(StudentGrade));
	
	for (int i = 0; i < 4; i++)
	{
		(*pntStudentGrade).numGrades[i] = 0;
	}
	
	return pntStudentGrade;
}

// Initialize a Pointer to a Detailed Student Grade 
StudentGrade* initializeDetailedStudentGrade(int numOne, int numTwo, int numThree, int numFour)
{
	StudentGrade* pntStudentGrade = initializeBlankStudentGrade();
	
	int arrGrades[] = {numOne, numTwo, numThree, numFour};
	
	for (int i = 0; i < 4; i++)
	{
		(*pntStudentGrade).numGrades[i] = arrGrades[i];
	}
	
	return pntStudentGrade;
}

// Get the Total Grade of a Student Grade
int getGradeTotal(StudentGrade* pntGrade)
{
	int gradeTotal = 0; 
	for (int i = 0; i < 4; i++)
	{
		gradeTotal += pntGrade -> numGrades[i];
	}
	return gradeTotal;
}

// Get the Average Grade of a Student Grade 
double getGradeAverage(StudentGrade* pntGrade)
{
	double gradeTotal = getGradeTotal(pntGrade);
	return gradeTotal / 4.0;
}
