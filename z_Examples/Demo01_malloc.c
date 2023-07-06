#include<stdio.h> 
#include<stdlib.h> 
  
int main() 
{ 
    int* ptr; 
    int size, i; 
  
    // Get the number of elements for the array 
    size = 7; 
    printf("Enter number of elements: %d\n", size); 
  
    // Dynamically allocate memory using malloc() 
    ptr = (int*)malloc(size * sizeof(int)); 
  
    // Check if the memory has been successfully 
    // allocated by malloc or not 
    if(ptr == NULL) { 
        printf("\nMemory not allocated.\n"); 
        exit(0); 
    } 
    else { 
  
        // Memory has been successfully allocated 
        printf("\nMemory successfully allocated using malloc.\n"); 
  
        // Get the elements of the array 
        for(i = 0; i < size; ++i) { 
            ptr[i] = i + 1; 
        } 
  
        // Print the elements of the array 
        printf("\nThe elements of the array are: "); 
        for (i = 0; i < size; ++i) { 
            printf("%d, ", ptr[i]); 
        } 
    } 
  
    printf("\n\n");
	return 0; 
} 

