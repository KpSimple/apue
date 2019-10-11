#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

//#define FOLLOW 

int main(int argc, char *argv[])
{
    int i;
    struct stat buf;
    char *ptr;

    for(i=1;i<argc;i++)
    {
        printf("%s:",argv[i]);

#ifdef FOLLOW   
	if (fstatat(AT_FDCWD, argv[i], &buf, 0) < 0)
#else
       	if (fstatat(AT_FDCWD, argv[i], &buf, AT_SYMLINK_NOFOLLOW) < 0)
#endif
        {
            printf("fstatat error\n");
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
        else
            ptr = "unknow";
 
        printf("%s\n",ptr);
        
    }
    return 0;
}
