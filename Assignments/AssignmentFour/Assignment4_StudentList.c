#include "Assignment4_StudentList.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
	This is the main file for the structures which contained the Student models. 
	Students are stored in a Binary Tree with sorted-insertions. 
	When sorting, an array of pointers to all Student is created, then sorted.
*/

// Initialize a Pointer to an empty Student Tree
StudentTree* initializeBlankStudentTree()
{
	StudentTree* pntStudentTree = malloc(sizeof(StudentTree));
	
	(*pntStudentTree).pntRoot = NULL; 
	(*pntStudentTree).numNodes = 0; 
	
	return pntStudentTree;
}

// Populate an allocated array of Student for sorting purposes
void populateStudentArrayInOrder(StudentNode* pntStudentNode, StudentArray* pntStudentArray, int* pntIndex)
{
	if (pntStudentNode == NULL)
	{
		return;
	}
	
	populateStudentArrayInOrder(pntStudentNode -> pntLeftNode, pntStudentArray, pntIndex);
	pntStudentArray -> pntArray[(*pntIndex)] = getStudentFromStudentNode(pntStudentNode);
	*pntIndex += 1;
	populateStudentArrayInOrder(pntStudentNode -> pntRightNode, pntStudentArray, pntIndex);
}

// Get Grade for an index of a Student Array
float getGradeFromArray(StudentArray* studentArray, int index)
{
	return getStudentGradeAverage(getStudentFromArray(studentArray, index));
}

// Get Age for an index of a Student Array
int getAgeFromArray(StudentArray* studentArray, int index)
{
	Student* student = getStudentFromArray(studentArray, index);
	StudentInformation* info = student -> pntStudentInformation;
	int numAge = info -> numAge;
	return numAge;
}

// Sort Student Array with Inertion Sort
void sortStudentArrayByGrade(StudentArray* studentArray)
{
	int numSwaps = 0; 
	printf("Sorting Array of length %d with Insertion Sort...\n", studentArray -> numCount);
	for (int i = 1; i < studentArray -> numCount; i++)
	{
		int temp = i;
		while (temp > 0)
		{
			if (getGradeFromArray(studentArray, temp) < getGradeFromArray(studentArray, temp - 1))
			{
				puts("Swapping...");
				numSwaps += 1;
				swapStudentsInArray(studentArray, temp, temp - 1);
			}	
			else 
			{
				break;
			}
			temp--;
		}
	}
	printf("Array sorted with %d swaps!\n", numSwaps);
}

// Sort Student Array by Quick Sort
void sortStudentArrayByAge(StudentArray* studentArray, int lowIndex, int highIndex, int* pntSwapCount)
{
	if (lowIndex >= highIndex)
	{
		return;
	}
	int splitIndex = lowIndex; 
	int pivotIndex = highIndex; 
	for (int i = lowIndex; i < highIndex; i++)
	{
		if (getAgeFromArray(studentArray, i) < getAgeFromArray(studentArray, pivotIndex))
		{
			puts("Swapping...");
			swapStudentsInArray(studentArray, i, splitIndex);
			splitIndex++;
			*pntSwapCount += 1;
		}
	}
	swapStudentsInArray(studentArray, pivotIndex, splitIndex);
	*pntSwapCount += 1;
	
	sortStudentArrayByAge(studentArray, lowIndex, splitIndex - 1, pntSwapCount);
	sortStudentArrayByAge(studentArray, splitIndex + 1, highIndex, pntSwapCount);
}

// Create an allocated array of students for easy sorting
StudentArray* createStudentArray(int numCount)
{
	StudentArray* studentArray = malloc(sizeof(StudentArray));
	studentArray -> numCount = numCount; 
	studentArray -> pntArray = calloc(numCount, sizeof(Student));
	
	return studentArray; 
}

// Get Student from index of a Student Array 
Student* getStudentFromArray(StudentArray* studentArray, int numIndex)
{
	return (Student*)studentArray -> pntArray[numIndex];
}

// Swap the place of two students in a Student Array 
void swapStudentsInArray(StudentArray* studentArray, int indexOne, int indexTwo)
{
	Student* temp = getStudentFromArray(studentArray, indexOne);
	
	studentArray -> pntArray[indexOne] = studentArray -> pntArray[indexTwo];
	studentArray -> pntArray[indexTwo] = temp;
}

// Create a Student Arrayy sized to hold entire contents of Student Tree
StudentArray* getStudentArray(StudentTree* pntStudentTree)
{
	StudentArray* studentArray = createStudentArray(pntStudentTree -> numNodes);
	
	int numIndex = 0; 
	populateStudentArrayInOrder(pntStudentTree -> pntRoot, studentArray, &numIndex);
	
	return studentArray;
}

// Innitialize a Pointer to an empty Student Node 
StudentNode* initializeBlankStudentNode()
{
	StudentNode* pntStudentNode = malloc(sizeof(StudentNode));
	pntStudentNode -> pntRightNode = NULL; 
	pntStudentNode -> pntLeftNode = NULL;
	pntStudentNode -> pntData = NULL;
	
	return pntStudentNode; 
}

// Initialize a Pointer to an existing Student Node
StudentNode* initializeExistingStudentNode(Student* pntStudent)
{
	StudentNode* pntStudentNode = initializeBlankStudentNode();
	
	pntStudentNode -> pntData = pntStudent;
	return pntStudentNode;
}

// Initialize a Pointer to a Student node with provided fields
StudentNode* initializeDetailedStudentNode(char* txtStudentNumber, char* txtFirstName, char* txtLastName, 
	int numAge, char* txtCourseCode, int numGradeOne, int numGradeTwo, int numGradeThree, int numGradeFour)
{
	StudentNode* pntStudentNode = initializeBlankStudentNode(); 
	Student* pntStudent = initializeDetailedStudent(txtStudentNumber, txtFirstName, 
		txtLastName, numAge, txtCourseCode, numGradeOne, numGradeTwo, numGradeThree, numGradeFour);
	pntStudentNode -> pntData = pntStudent;
	
	return pntStudentNode; 
}

// Retrieve the Student from Student Node by casting from void pointer
Student* getStudentFromStudentNode(StudentNode* pntStudentNode)
{
	return (Student*)pntStudentNode -> pntData;
}

// Add Student to Student Node subtree
int addStudentToStudentNode(StudentNode** pntStudentNode, Student* pntStudent)
{
	if (*pntStudentNode == NULL) 
	{
		*pntStudentNode = initializeExistingStudentNode(pntStudent);
	}
	else 
	{
		StudentNode* studentNode = *pntStudentNode; 
		
		int studentComparison = strcmp(getStudentFromStudentNode(studentNode) -> txtStudentNumber, pntStudent -> txtStudentNumber);
		if (studentComparison > 0)
		{
			addStudentToStudentNode(&studentNode -> pntLeftNode, pntStudent);
		} 
		else if (studentComparison < 0)
		{
			addStudentToStudentNode(&studentNode -> pntRightNode, pntStudent);
		}
		else 
		{
			puts("ERROR: Duplicate Student Number");
			return -1;
		}
	}
	return 0;
}

// Add Student to Student Tree through node subtrees
int  addStudentToStudentTree(StudentTree* pntStudentTree, char* txtStudentNumber, char* txtFirstName, char* txtLastName, 
	int numAge, char* txtCourseCode, int numGradeOne, int numGradeTwo, int numGradeThree, int numGradeFour)
{
	Student* pntStudent = initializeDetailedStudent(txtStudentNumber, txtFirstName, txtLastName, numAge, 
		txtCourseCode, numGradeOne, numGradeTwo, numGradeThree, numGradeFour);
	StudentNode* pntCurrentNode = pntStudentTree -> pntRoot; 

	int result = addStudentToStudentNode(&pntStudentTree -> pntRoot, pntStudent);

	if (result == 0)
	{
		pntStudentTree -> numNodes += 1;
	}
	return result;
}

// Retrieve a Student from Student Node by with binary search for student number 
Student* searchNodeForStudent(StudentNode* pntStudentNode, char* txtSearchNumber, int* pntCount)
{
	*pntCount += 1;
	if (pntStudentNode == NULL)
	{
		return NULL;
	}
	else
	{
		Student* student = getStudentFromStudentNode(pntStudentNode);
		if ( strcmp(student -> txtStudentNumber, txtSearchNumber) == 0)
		{
			return student;
		}
		else if (strcmp(student -> txtStudentNumber, txtSearchNumber) < 0)
		{
			return searchNodeForStudent(pntStudentNode -> pntRightNode, txtSearchNumber, pntCount);
		}
		else 
		{
			return searchNodeForStudent(pntStudentNode -> pntLeftNode, txtSearchNumber, pntCount);
		}
	}
}

// Retrieve a Student from Student Node with binary search for student number 
Student* searchForStudentByStudentNumber(StudentTree* pntStudentTree, char* txtSearchNumber, int* pntCount)
{
	return searchNodeForStudent(pntStudentTree -> pntRoot, txtSearchNumber, pntCount);
}

// Free all memory contained within Node
void clearStudentNode(StudentNode* studentNode)
{
	if (studentNode == NULL)
	{
		return; 
	}
	
	clearStudentNode(studentNode -> pntLeftNode);
	clearStudentNode(studentNode -> pntRightNode);
	clearStudent(getStudentFromStudentNode(studentNode));
	free(studentNode);
	return;
}

// Clear all memory contained within Tree
void clearStudentTree(StudentTree* studentTree)
{
	clearStudentNode(studentTree -> pntRoot);
	free(studentTree);
	return;
}
