#include <stdio.h>
#include <string.h>

// Structure to store information for one student
typedef struct {
	char name[50];
	int id;
	double GPA;
} Student;

void printStudent(Student st); 

int main(int argc, char** argv) {
        
    const int size = 3;
    Student st[size];   // An array of students (Student structures)
    
    // Input values for the structure fields (first student)
    printf("Please enter the name, ID, and GPA: ");
    scanf("%s", st[0].name);
    scanf("%d", &st[0].id);
    scanf("%lf", &st[0].GPA);
    
    // Initialize 2nd and 3rd students from hard-coded values
    strcpy(st[1].name, "John Lennon");
    st[1].id = 36532428;
    st[1].GPA = 3.5;
    
    strcpy(st[2].name, "Ringo Starr");
    st[2].id = 36532832;
    st[2].GPA = 3.1;
        
    // Print info for all 3 students
    for (int i = 0; i < size; i++) {
        printStudent(st[i]);
    }
    
}

// Function to print the info for one student, passed by value 
void printStudent(Student st) 
{
    printf("The name, ID, and GPA are %s, %d, %lf\n", st.name, st.id, st.GPA);       
}

