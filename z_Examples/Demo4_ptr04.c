#include<stdio.h>
int main()
{
  int i,  size=6;
  double numbers[]={90.4, 12.2,22.44, 36.7, 47.8, 56.99}; 
              //[0] [1] [2] [3] [4] [5]

  for(i = 0; i < size ; i++ )
      printf(" number[%d] = %lf  , at address %p   \n",i,numbers[i], &numbers[i]);

  printf("\n\n");

   return 0;
}

