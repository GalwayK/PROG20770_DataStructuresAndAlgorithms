#include<stdio.h>
#include<stdbool.h>

int main()
{
   // Input  characters  ("commands")  until  the  user  enters  'q'
	printf("Enter character \n");
	while(true){
	  char  ch;

	  scanf("%c", &ch);

	  switch(ch){
		case 'a':
		printf("Executing  command  'a'\n"); 
		break;

		case 'b':
		printf("Executing  command  'b'\n");
 		break;

		case 'q':
		printf("Executing  command  'quit'\n"); 
		goto  quit;
		break;     //  Note:  This  statement  is  never  reached
	  }
	}
  quit:
  printf("Program  terminating\n"); 
  return  0;
}


