#include <stdio.h>

int main(void)
{
	int i = 2;
	int j = 4;
	int k;

	{	// Open brace starts a new scope
		int i = 3;
		k = 7;

		printf("i = %d, j = %d, k = %d\n", i, j, k);
	}

	printf("i = %d, j = %d\n", i, j);

	//Un-comment the printf that’s commented out and try  compiling

	 printf("k=%d\n", k);  

	return 0;
}
