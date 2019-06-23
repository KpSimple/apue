#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int fd;

	if(fd = open("/dev/dsp",O_WRONLY)<0)
	{
		printf("error = %d\n",errno);
		char *msg = strerror(errno);
		printf("Msg:%s\n",msg);
	}
	errno = ENOENT;
	perror(argv[0]);
	exit(0);	
}
