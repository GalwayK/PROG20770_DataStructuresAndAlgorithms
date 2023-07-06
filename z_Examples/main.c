#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "charStack.h"

int main(int argc, char** argv)
{
    initStack();
    
    printf("Please enter a string: ");
    char str[MAXSTACK] = "";
    scanf("%s", str);
    
    int len = strlen(str);
    
    // Push all the characters in 'str'
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }  
    
    // Pop all characters and print them
    while(!isEmpty()) {
        printf("%c", pop());
    }
}
