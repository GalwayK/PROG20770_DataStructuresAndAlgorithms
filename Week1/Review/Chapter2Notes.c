#include<stdio.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>

int main(int argCount, char** argStrings)
{
	// Puts to print string with new line.
	puts("This is basically a printline function.");
	
	// Printf to print string with no new line.
	printf("%s", "This is basically a print function!");
	puts("Ooops, no newline!");
}

// Chapter 2 (2.1 to 2.5)
/*
// Headers 

Include statements are directives to the C preprocessor. They tell the 
preprocessor to include the header files for the compiler. When the linker runs,
it finds the library functions and inserts them into the fuction calls. The 
linker is what finds these functions through the header files, and it will 
produce an error if it is unable to locate them. 

We should never write a printf function call if we have no arguments to pass
into it. Instead, we should use the puts function. Puts is essentially the same 
as the printline() function in C derived languages. We can also just use printf
with an argument string if we do not want a newline.
*/
