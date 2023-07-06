#include<stdio.h>

	//  To  guarantee  a  parameter  will  never  be  changed  use  const
	double  ave(const  int  arr[],  int  len)  
	{
	      int  index, total  =  0;
		  for(index= 0;  index<len;  index++)  {
		      total  +=  arr[index];    //  Add  up  all  the  numbers
          }
        return  (double)total/len;    //  Calculate  the  average
	}
	
	
   int main() 
	{
  	  int  index;
	  int numbers[]={29,5,-7,101,-555};  //  Initialize  array int  len  =  5;
	
  	  //  Call  function  to calculate  the  average  and  print  it 
  	  printf("The  average is  %f\n",  ave(numbers,len));
	
    for(index=0;  index<len;  index++) 
	 {
		printf("%d  ",  numbers[index]);  //  Print  out  all  the
		
	 }
	 return 0;
	}

