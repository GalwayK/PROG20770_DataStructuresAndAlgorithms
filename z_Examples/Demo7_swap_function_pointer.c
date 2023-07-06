// C program to swap two variables using a  
// user defined swap() 

#include <stdio.h> 
  
// This function swaps values pointed by xp and yp 
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
int main() 
{ 
    int x, y; 
    printf("Enter Value of x = "); 
    scanf("%d", &x); 
    printf("\nEnter Value of y = "); 
    scanf("%d", &y); 
    swap(&x, &y); 
    printf("\nAfter Swapping:\n x = %d\n y = %d\n\n", x, y); 
    return 0; 
} 

