#include <stdio.h>
#include <string.h>

int main(int arg, char** argv) 
{
	printf("Please enter a string: ");
	char str[256];
	scanf("%s", str);

    // Initialize pointers
	char* pos = str;
	char* last = str + strlen(str) - 1;
	
	// Print the string forwards and backwards at the same time using "pointer chasing"
	while (*pos != '\0') {
		printf("%c %c\n", *pos, *last);
		pos++;
		last--;
	}

}
