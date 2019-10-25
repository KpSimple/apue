#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    umask(0);
    if(creat("foo",S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP)<0)
	    printf("creat foo error");
    umask(S_IRGRP | S_IWGRP);
    if(creat("bar",S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP)<0)
	    printf("creat bar error");

    return 0;
}
