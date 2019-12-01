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
    int             i, fd;
    struct stat     statbuf;
    struct utimbuf     timebuf;
    struct timeval time;

    gettimeofday(&time,NULL);
 
    for (i=1; i<argc; i++)
    {
         printf("argv[%d] = %s\n", i, argv[i]);
         if (stat(argv[i], &statbuf) < 0){//fetch current times
             printf("%s: stat error\n", argv[1]);
             continue;
         }

	 printf("st_atime:%d,st_mtime:%d\n",statbuf.st_atime,statbuf.st_mtime);
 
         if ((fd = open(argv[1], O_RDWR|O_TRUNC)) < 0){
             printf("%s: open error\n", argv[1]);
             continue;
         }
 
         close(fd);
         timebuf.actime = time.tv_sec;
         timebuf.modtime = time.tv_sec;
         if (utime(argv[i], &timebuf) < 0){
             // retset time
             printf("%s: utime error\n", argv[i]);
             continue;
         }
    }
    
    return 0;

}
