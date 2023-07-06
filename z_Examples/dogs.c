#include <stdio.h>
#include <stdbool.h>   // So we can use 'true'
#include "dogs.h"

int main(int argc, char** argv)
{
    float weight = 0;
    int count = 0;

    while (true)   // Loop until 'break'
    {
        // Prompt for input and read the weight
        printf("Enter the weight of dog %d in kg: ", ++count);
        int parseCount = scanf("%f", &weight);
        if (parseCount != 1) {
            printf("Incorrect input, please try again\n");
            fflush(stdin);
            continue;
        }
        
        if (weight == 0)
            break;  // Quit if weight is 0

        bark(count, weight);
        printf("\n");         // Leave a blank line
    }
    
    return 0;
}

// Prints the sound a dog might make.
// 'dogNum' is the dog number, 'dogWeight' is weight in pounds
void bark(int dogNum, float dogWeight)
{
    if (dogWeight < 10) {
        printf("Dog #%d says Yip! Yip!\n", dogNum);
    }
    else if (dogWeight < 50) {
        printf("Dog #%d says Ruff! Ruff!\n", dogNum);
    }
    else {
        printf("Dog #%d says Woof! Woof!\n", dogNum);
    }
}


