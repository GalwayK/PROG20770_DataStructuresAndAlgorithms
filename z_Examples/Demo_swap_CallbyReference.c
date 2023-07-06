#include<stdio.h>  

void change(int *num)
 {    
    printf("\nBefore adding value inside function num=%d \n",*num);   
	 
    (*num) += 100; 
	   
    printf("\nAfter adding value inside function num=%d \n", *num);    
}    
  
int main()
 {    
    int x=100;    
    printf("\nBefore function call x=%d \n", x); 
	   
    change(&x);//passing reference in function 
	   
    printf("\nAfter function call x=%d \n", x);  
	  
return 0;  
}    

