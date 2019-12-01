#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int fd;
    
    char str[]="this is a test file";
    if((fd = creat("test",S_IRUSR | S_IWUSR)) < 0)
    {
	 printf("create fail\n");
         return -1;
    }

    printf("fd:%d\n",fd);
    //printf("size of str :%d",sizeof(str));
    int w_len = write(fd,str,sizeof(str));
    if(w_len < 0)
    {
	    printf("write fial\n");
	    return -1;
    }

    int t_len = ftruncate(fd,10);

    if(t_len == -1)
    {
	    printf("truncate fial\n");
	    return -1;
    }
    close(fd);

    fd = open("test",O_RDWR); 
    printf("fd:%d\n",fd);
    char buf[20];
    int r_len = read(fd,buf,20);
    if(r_len < 0)
    {
	    printf("read fail errno:%d\n",errno);
	    return -1;
    }
    printf("buf:%s\n",buf);
  
    return 0;

}
