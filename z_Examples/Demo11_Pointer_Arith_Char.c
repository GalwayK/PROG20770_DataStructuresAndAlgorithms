#include<stdio.h>

int main()
{
     char	str[]= "Today is the	!";
     char*pos = str;
   
   while(*pos != '\0')
   {
      printf("%c \n",*pos); 
	  pos++;
   }
}

