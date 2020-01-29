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
	char *ptr;
	size_t size;
	if(chdir("/tmp/v2ray") < 0)
	{
		printf("chdir failed\n");
	}
	ptr = malloc(1024);
	if(getcwd(ptr,1024)<0)
	{
		printf("getcwd failed\n");
	}

	printf("path:%s\n",ptr);

	return 0;

}
