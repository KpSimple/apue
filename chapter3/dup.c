#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define BUFFSIZE 8192
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int main(int argc, char *argv[])
{
    int fd,fd2,n;
//    if(fd = open("text.txt",O_CREAT | O_RDWR | O_TRUNC,S_IRUSR | S_IWUSR) < 0)
    if(fd = creat("text.txt",FILE_MODE))
        printf("open error");

    fd2 = dup(fd);
    if(fd2 < 0)
    {
         printf("dup error");
         return;
    }

    char buf[BUFFSIZE];

    while((n = read(STDIN_FILENO,buf,BUFFSIZE)) > 0)
        if(write(fd2,buf,n) != n)
            printf("write error");

    if(n < 0)
        printf("read error");
    
    return 0;

}
