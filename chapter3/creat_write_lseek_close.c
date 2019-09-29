#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(int argc, char *argv[])
{
    int fd;
    if((fd = creat("file.hole",FILE_MODE)) < 0)
        printf("create error");

    if(write(fd,buf1,10)!=10)
        printf("buf1 write error");

    if(lseek(fd,16384,SEEK_SET) == -1)
        printf("lseek error");

    if(write(fd,buf2,10)!= 10)
        printf("buf2 write error");

    if(close(fd) == -1)
        printf("close  error");
    
    return 0;

}
