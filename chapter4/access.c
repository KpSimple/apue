#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
	printf("argc error :%d",argc);
        return;
    }

    for(int i=1;i<argc;i++)
    {
        if(access(argv[i],R_OK)==0)
   	    printf("access ok\n");
        else
	    printf("access fail\n");


        if(open(argv[i],O_RDONLY)>=0)
	    printf("open success\n");
        else
	    printf("open fail\n");
    }
    return 0;
}
