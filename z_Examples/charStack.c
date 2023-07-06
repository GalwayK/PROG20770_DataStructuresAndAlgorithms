#include <stdio.h>
#include <stdbool.h>
#include "charStack.h"

typedef struct {
    int top;          // Top of stack
    char ST[MAXSTACK]; // Array containing stack data
} Stack;

static Stack S;  // Variable S has source-file scope 

void initStack(void) {
    S.top = -1;
}

bool isEmpty(void) {
    return (S.top == -1);
}

void push(char num) {
    if (S.top == MAXSTACK - 1) {
        printf("Stack Overflow\n");  // Stack is full
    } 
    else {
        ++S.top;            // Update top index
        S.ST[S.top] = num;  // Put 'num' on the stack
    }
}

char pop(void) {
    if (isEmpty()) {
        return ROGUEVALUE; // Special value indicates error
    } 
    else {
        char result = S.ST[S.top];  // Get item
        --S.top;           // Update top index
        return result;     // Return item
    }
} 


