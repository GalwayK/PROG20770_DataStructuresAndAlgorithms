#include <stdio.h>

// Structure to store information for one student
typedef struct {
	char name[50];
	int id;
	double GPA;
} Student;

void printStudent(Student st); 

int main(int argc, char** argv) {
        
    Student st;   // One instance of the structure
    
    // Input values for the structure fields
    printf("Please enter the name, ID, and GPA: ");
    scanf("%s", st.name);
    scanf("%d", &st.id);
    scanf("%lf", &st.GPA);
    
    printStudent(st);
    
    printf("GPA now is %f\n", st.GPA);
}

// Function to print the Student structure fields, passed by value 
void printStudent(Student st) 
{
    printf("The name, ID, and GPA are %s, %d, %lf\n", st.name, st.id, st.GPA);   
    
}

