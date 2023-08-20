#define LENGTH_STUDENT_NAME 255
#define LENGTH_COURSE_CODE 6

// The Student Information is the main model for containing misc Student data
typedef struct StudentInformation
{
	char txtFirstName[255];
	char txtLastName[255];
	
	int numAge;
	char txtCourseCode[6];

} StudentInformation;

StudentInformation* initializeBlankStudentInformation(void);

StudentInformation* initializeDetailedStudentInformation(char* txtFirstName, char* txtLastName, int numAge, char* txtCourseCode);

#undef LENGTH_STUDENT_NAME 
#undef LENGTH_COURSE_CODE
