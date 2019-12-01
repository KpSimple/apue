#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char *argv[])
{

    if(open("link",O_RDWR) < 0)
    {
	    printf("open error\n");
	    return -1;
    }

    if(remove("link") < 0)
    {
	    printf("remove error\n");
	    return -1;
    }

    printf("remove success\n");

    sleep(2);

    printf("done\n");

    return 0;

}
