#include <stdio.h>

// Structure to store information for one student
struct student {
	char name[50];
	int id;
	double GPA;
};


int main(int argc, char** argv) {
    struct student st;   // One instance of the structure
    
    // Input values for the structure fields
    printf("Please enter the name, ID, and GPA: ");
    scanf("%s", st.name);
    scanf("%d", &st.id);
    scanf("%lf", &st.GPA);
    
    printf("The name, ID, and GPA are %s, %d, %lf\n", st.name, st.id, st.GPA);
}


