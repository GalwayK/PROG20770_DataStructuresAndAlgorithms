#include <stdio.h>
#include <string.h>

typedef struct {
	int day;
	int month;
	int year;
} Date;

typedef struct {
	char first[21];
	char middle;
	char last[21];
} Name;


typedef struct {
	Name name;
	int id;
	double GPA;
	Date bDate;   // The student's birth date
} Student;

void printStudent(const Student* st); 

const int size = 3;

int main(int argc, char** argv) 
{

	// Declare an array of 'Student' structures (careful, uninitialized)
	Student st[size];

	// Input info into the struct and then print it out
	printf("Please enter name, ID, GPA then birth day, month, year: ");
	scanf(" %s", st[0].name.first);
	scanf(" %c", &st[0].name.middle);
	scanf(" %s", st[0].name.last);
	scanf(" %d", &st[0].id);
	scanf(" %lf", &st[0].GPA);
	scanf(" %d", &st[0].bDate.day);
	scanf(" %d", &st[0].bDate.month);
	scanf(" %d", &st[0].bDate.year);
	
	// Initialize other students from hard-coded values
	strcpy(st[1].name.first, "Ringo");
	st[1].name.middle = 'X';
	strcpy(st[1].name.last, "Starr");
    st[1].id = 765438787;
    st[1].GPA = 2.7;
    st[1].bDate.day = 1;
    st[1].bDate.month = 1;
    st[1].bDate.year = 1940;

	strcpy(st[2].name.first, "Paul");
	st[2].name.middle = 'Y';
	strcpy(st[2].name.last, "McCartney");
    st[2].id = 765434344;
    st[2].GPA = 3.7;
    st[2].bDate.day = 2;
    st[2].bDate.month = 3;
    st[2].bDate.year = 1941;

    // Print info for all 3 students
    for (int i = 0; i < size; i++) {
        printStudent(&st[i]);
    }
}

// Print the information for one student 'st'. 
// The parameter 'st' uses call-by-reference -- it is a pointer to Student.
void printStudent(const Student* st) 
{
	printf("%s %c %s, %d, %f\n", st->name.first, st->name.middle, st->name.last, st->id, st->GPA);
	printf("Birth date: %d/%d/%d\n", st->bDate.day, st->bDate.month, st->bDate.year);
	
}
