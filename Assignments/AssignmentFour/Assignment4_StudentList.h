#include "Assignment4_Student.h"
#include <stdlib.h>

// Type Generic Binary Node used to contain generic data
typedef struct BinaryNode
{
	struct BinaryNode* pntLeftNode; 
	struct BinaryNode* pntRightNode;
	void* pntData;
} BinaryNode;

// Type Generic Binary Tree used to contain generic data
typedef struct BinaryTree
{
	int numNodes;
	BinaryNode* pntRoot;
} BinaryTree;

// Type Generic Array used to contain generic data
typedef struct Array
{
	int numCount;
	void** pntArray; 
} Array; 

// Alias for Binary Tree with Student operations
typedef BinaryTree StudentTree;

// Alias for Binary Node with Student operations
typedef BinaryNode StudentNode;

// Alias for Generic Array with Student Operations
typedef Array StudentArray;

void populateStudentArrayInOrder(StudentNode* pntStudentNode, StudentArray* pntStudentArray, int* pntIndex);

StudentArray* createStudentArray(int numCount);

Student* getStudentFromArray(StudentArray* studentArray, int numIndex);

StudentArray* getStudentArray(StudentTree* pntStudentTree);

void swapStudentsInArray(StudentArray* studentArray, int indexOne, int indexTwo);

float getGradeFromArray(StudentArray* studentArray, int index);

int getAgeFromArray(StudentArray* studentArray, int index);

void sortStudentArrayByGrade(StudentArray* studentArray);

void sortStudentArrayByAge(StudentArray* studentArray, int lowIndex, int highIndex, int* pntSwapCount);

Student* searchForStudentByStudentNumber(StudentTree* pntStudentTree, char* txtSearchNumber, int* pntCount);

StudentTree* initializeBlankStudentTree();

StudentNode* initializeBlankStudentNode();

StudentNode* initializeExistingStudentNode(Student* pntStudent);

StudentNode* initializeDetailedStudentNode(char* txtStudentNumber, char* txtFirstName, char* txtLastName, 
	int numAge, char* txtCourseCode, int numGradeOne, int numGradeTwo, int numGradeThree, int numGradeFour);
Student* getStudentFromStudentNode(StudentNode* pntStudentNode);

int addStudentToStudentNode(StudentNode** pntStudentNode, Student* pntStudent);

void clearStudentNode(StudentNode* studentNode);

void clearStudentTree(StudentTree* studentTree);

int addStudentToStudentTree(StudentTree* pntStudentTree, char* txtStudentNumber, char* txtFirstName, char* txtLastName, 
	int numAge, char* txtCourseCode, int numGradeOne, int numGradeTwo, int numGradeThree, int numGradeFour);
