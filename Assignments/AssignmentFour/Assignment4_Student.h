#include "Assignment4_StudentInformation.h"
#include "Assignment4_StudentGrade.h"
#define LENGTH_STUDENT_NUM 10

// The Student Struct is the main model for containing Student data
typedef struct Student 
{
	char txtStudentNumber[LENGTH_STUDENT_NUM];
	StudentGrade* pntStudentGrade;
	StudentInformation* pntStudentInformation;
} Student;

Student* initializeBlankStudent();

Student* initializeDetailedStudent(char* txtStudentNumber, char* txtFirstName, char* txtLastName, 
	int numAge, char* txtCourseCode, int numGradeOne, int numGradeTwo, int numGradeThree, int numGradeFour);

int getStudentGradeTotal(Student* pntStudent);

double getStudentGradeAverage(Student* pntStudent);

void clearStudent(Student* student);

#undef LENGTH_STUDENT_NUM
