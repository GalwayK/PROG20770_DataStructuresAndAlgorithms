#include "Assignment4_StudentInformation.h"
#include <string.h>
#include <stdlib.h>

// Initialize a pointer to a Blank Student Information
StudentInformation* initializeBlankStudentInformation()
{
	StudentInformation* pntStudentInformation = malloc(sizeof(StudentInformation));
	strcpy(pntStudentInformation -> txtFirstName, "");
	strcpy(pntStudentInformation -> txtLastName, "");
	pntStudentInformation -> numAge = 0; 
	strcpy(pntStudentInformation -> txtCourseCode, "");
	
	return pntStudentInformation;
 } 

// Initialize a pointer to a Blank Student Information
StudentInformation* initializeDetailedStudentInformation(char* txtFirstName, char* txtLastName, int numAge, char* txtCourseCode)
{
	StudentInformation* pntStudentInformation = initializeBlankStudentInformation();
	
	strcpy(pntStudentInformation -> txtFirstName, txtFirstName);
	strcpy(pntStudentInformation -> txtLastName, txtLastName);
	pntStudentInformation -> numAge = numAge;
	strcpy(pntStudentInformation -> txtCourseCode, txtCourseCode);
	
	return pntStudentInformation;
}
