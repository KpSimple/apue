#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc, char *argv[])
{
    int fd,i;
    struct stat buf;
    char *ptr;

    for(i=1;i<argc;i++)
    {
        printf("%s:",argv[i]);
        if(fd = open(argv[i],O_RDWR) < 0)
        {
            printf("open error\n");
            continue;
        }
    
        if(fstat(fd,&buf) < 0)
        {
            printf("fstat error\n");
            continue;
        }

        if(S_ISLNK(buf.st_mode))
            ptr = "symbol link";
        else if(S_ISREG(buf.st_mode))
            ptr = "regular";
        else if(S_ISDIR(buf.st_mode))
            ptr = "directory";
        else if(S_ISCHR(buf.st_mode))
            ptr = "character special";
 
        printf("%s\n",ptr);
        
        close(fd);       
    }
    return 0;
}
