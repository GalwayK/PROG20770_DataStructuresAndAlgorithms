#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    // Input a string from the user
    char str[100] = "";
    int i;
    printf("Please enter a string: ");
    scanf("%99[^\n]", str);
    
    // Print every second char
    int len = strlen(str);
    for( i = 0; i < len; i += 2) {
        printf("%c", str[i]);
    }
    
    printf("\n");
}
