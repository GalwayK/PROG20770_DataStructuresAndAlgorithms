#include <stdio.h>
#include <stdbool.h>

#define MAXSTACK 100
#define ROGUEVALUE -2147483648 

typedef struct {
    int top;          // Top of stack
    int ST[MAXSTACK]; // Array containing stack data
} Stack;

static Stack S;  // Variable S has source-file scope 

void initStack(void) {
    S.top = -1;
}

bool isEmpty(void) {
    return (S.top == -1);
}

void push(int num) {
    if (S.top == MAXSTACK - 1) {
        printf("Stack Overflow\n");  // Stack is full
    } else {
        ++S.top;            // Update top index
        S.ST[S.top] = num;  // Put 'num' on the stack
    }
}

int pop(void) {
    if (isEmpty()) {
        return ROGUEVALUE; // Special value indicates error
    } else {
        int result = S.ST[S.top];  // Get item
        --S.top;           // Update top index
        return result;     // Return item
    }
} 

int main(int argc, char** argv)
{
    initStack();
    
    // Push some numbers on the stack
    push(36);
    push(15);
    push(52);
    push(23);
    
    // Pop and print all the items until the stack is empty
    while(!isEmpty()) {
        int num = pop();
        printf("%d\n", num);
    }
      
}
