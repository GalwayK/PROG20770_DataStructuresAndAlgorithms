#include <stdio.h>
#include <string.h>

// Our version of the strlen C-library function
unsigned int myStrlen(const char* str)
{
    const char* ptr = str;
    int count = 0;
    while (*ptr != '\0') {
        count++;
        ptr++;
    }
    
    return count;
}

int main(int arg, char** argv) 
{
    char str[] = "how long am I?";
    int num = myStrlen(str);
    printf("%d\n", num);
}
     
