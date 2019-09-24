#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
    char pathname[256] = "/home";
    int  fd = open(pathname, O_RDONLY);
    long val;
    val = sysconf(_SC_ARG_MAX);
    printf("argument max :%d\n",val);
    val = pathconf(".",_PC_NAME_MAX);
    printf("name max :%d\n",val);
    val = fpathconf(fd,_PC_PATH_MAX);
    printf("path max :%d\n",val);
}
