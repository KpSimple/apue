#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    char buf[1024];
    ssize_t ret;

    if(open("symlink",O_RDWR) < 0)
    {
	    printf("open error\n");
	    return -1;
    }

    if(ret = readlink("symlink",buf,1024) < 0)
    {
	    printf("readlink error\n");
	    return -1;
    }

    printf("len:%d\n",ret);

    //buf[ret] = '\0';

    printf("readlink success\n");

    printf("buf:%s\n",buf);


    return 0;

}
