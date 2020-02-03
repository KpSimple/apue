#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/time.h>
#include <utime.h>

int main(int argc, char *argv[])
{
	int c;
/*
	while((c = fgetc(stdin)) != EOF)
		if(fputc(c,stdout) == EOF)
			printf("output error");
*/
	while((c = getc(stdin)) != EOF)
		if(putc(c,stdout) == EOF)
			printf("output error");

	if(ferror(stdin))
		printf("input error");
}
