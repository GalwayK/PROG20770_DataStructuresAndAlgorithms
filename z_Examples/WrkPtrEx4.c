#include <stdio.h>
#include <string.h>

int main(int arg, char** argv) 
{
    const int size = 5;
    int nums[] = {87, -5, 33, 2, -9};
    int* pos = nums;

    // Print the array contents using "pointer chasing"
    for (int i = 0; i < size; i++) {
        printf("%d\n", *pos);
        pos++;
    }
     
}
