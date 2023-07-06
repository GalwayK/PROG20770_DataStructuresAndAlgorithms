#include <stdio.h>

int main()
{
  int numbers[]={10,20,30,40,50,60};


  fprintf(stdout,"All 4 syntax notations give the same result\n");
  fprintf(stdout,"numbers[3]: %d\n", numbers[3]); 
  fprintf(stdout,"*(numbers+3)%d\n", *(numbers+3)); 
  fprintf(stdout,"*(3+numbers)%d\n", *(3+numbers)); 
  fprintf(stdout,"3[numbers]: %d\n", 3[numbers]); 
  4[numbers]=3000;
  fprintf(stdout,"The new value of numbers[4]: %d\n", numbers[4]); 
  
     return 0;
  }

