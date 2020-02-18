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
	FILE *file = fopen("/tmp/test_file","wt+");
	if(file == NULL)
	{
		printf("fopen failed");
		return 0;
	}
	char str[]="this is test file";
	size_t ret = fwrite(str,1,sizeof(str),file);
	
	if(ret != sizeof(str))
	{
		printf("fwrite failed\n");
	}

	fseek(file,0,SEEK_SET);

	char buf[MAXLINE];

	ret = fread(buf,1,sizeof(str),file);

	printf("fread ret:%d\n",ret);
	if(ret > 0 )
		printf("buf:%s\n",buf);

	return 0;
}
