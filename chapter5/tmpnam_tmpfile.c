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
	char name[MAXLINE];
	char str[MAXLINE];
	FILE *fp;
	printf("%s\n",tmpnam(NULL));	
	
	tmpnam(name);
	printf("%s\n",name);

	if( (fp = tmpfile()) == NULL)
		printf("tmpfile error");

	fputs("this is test file\n",fp);
	rewind(fp);
	if(fgets(str,sizeof(str),fp) == NULL)
		printf("fgets error");
	fputs(str,stdout);
  
	return 0;
}
