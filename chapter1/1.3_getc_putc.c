#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int c;

	while ( (c = getc(stdin)) != EOF )
	{
		if (putc(c,stdout) == EOF)
		{	
			printf("output error");
		}
	}

	return 0;	
}
