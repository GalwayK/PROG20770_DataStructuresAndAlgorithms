#define NUM_COURSES 4
#define NUM_GRADE_MIN 0
#define NUM_GRADE_MAX 100

// The StudentGrade struct is the main model for containing a Student's grades
typedef struct StudentGrade
{
	int numGrades[NUM_COURSES];
} StudentGrade; 

StudentGrade* initializeBlankStudentGrade();

StudentGrade* initializeDetailedStudentGrade(int numOne, int numTwo, int numThree, int numFour);

int getGradeTotal(StudentGrade* pntGrade);

double getGradeAverage(StudentGrade* pntGrade);

#undef NUM_COURSES
#undef NUM_GRADE_MIN
#undef NUM_GRADE_MAX
