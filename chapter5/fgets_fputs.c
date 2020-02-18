#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/time.h>
#include <utime.h>

#define MAXLINE 1024

int main(int argc, char *argv[])
{
	char buf[MAXLINE];
	while(fgets(buf,MAXLINE,stdin) != NULL)
		if(fputs(buf,stdout) == EOF)
			printf("output error");

	return 0;
}
