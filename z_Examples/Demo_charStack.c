#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define MAXSTACK 100
#define ROGUEVALUE '\0'

//#include "charStack.h"


typedef struct {
    int top;          // Top of stack
    char ST[MAXSTACK]; // Array containing stack data
} Stack;

static Stack S;  // Variable S has source-file scope 

void initStack() {
    S.top = -1;
}

bool isEmpty() {
    return (S.top == -1);
}

void push(char num) {
    if(S.top == MAXSTACK - 1) {
        printf("Stack Overflow\n");  // Stack is full
    } 
    else {
        ++S.top;            // Update top index
        S.ST[S.top] = num;  // Put 'num' on the stack
    }
}

char pop() {
    if(isEmpty()) {
        return ROGUEVALUE; // Special value indicates error
    } 
    else {
        char result = S.ST[S.top];  // Get item
        --S.top;           // Update top index
        return result;     // Return item
    }
} 


int main()
{
    initStack();
	char str[MAXSTACK]="";
    int i, len;
	
    printf("Please enter a string: ");
    
    scanf("%s", str);
    
    len=strlen(str);
    
    // Push all the characters in 'str'
    for(i=0; i<len; i++)
	{
        push(str[i]);
    }  
    
    /*Pop all characters and print them */
    while(!isEmpty())
	{
        printf("%c", pop());
    }
}

