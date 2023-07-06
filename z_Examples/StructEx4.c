#include <stdio.h>

typedef struct {
	char first[21];
	char middle;
	char last[21];
} Name;

typedef struct {
	int day;
	int month;
	int year;
} Date;

// Structure to store information for one student
typedef struct {
	Name name;
	int id;
	double GPA;
	Date bDate;
} Student;



int main(int argc, char** argv) {

	Student st;   // One instance of the structure

	// Input values for the structure fields
	printf("Please enter the name (first middle last), ID, GPA, and year-month-day of the birthdate: ");

    scanf(" %s", st.name.first);
    scanf(" %c", &st.name.middle);	
    scanf(" %s", st.name.last);
	scanf(" %d", &st.id);
	scanf(" %lf", &st.GPA);
	scanf(" %d", &st.bDate.day);
	scanf(" %d", &st.bDate.month);
	scanf(" %d", &st.bDate.year);

	printf("The name, ID, GPA, and birth date are %s %c %s, %d, %lf, %d/%d/%d\n", st.name.first, st.name.middle, st.name.last,
           st.id, st.GPA, st.bDate.day, st.bDate.month, st.bDate.year);
}


