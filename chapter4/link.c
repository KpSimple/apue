#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int ret;
    
    ret = link("/home/code/apue/chapter4/main.c","/home/code/apue/chapter4/link");

    if(ret == 0)
    {
	    printf("link success\n");
    }
    else
    {
	    printf("link failed\n");
    }

    return 0;

}
