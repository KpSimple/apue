#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>

int main(int argc, char *argv[])
{
    uid_t uid;
    struct passwd *pwd;
    char *endptr;
 
    if(argc != 3)
    {
	 printf("argc :%d",argc);
	 return -1;
    }    
    //äString is decimal
    uid = strtol(argv[1],&endptr,10);

    if(*endptr != '\0')
    {
	 pwd = getpwnam(argv[1]);
	 if(pwd == NULL)
         {
             printf("pwd get error");
	     return -1;
	 }
	 uid = pwd->pw_uid;
    }

    if(chown(argv[2],uid,-1)  == -1)
    {
	 printf("chown error");
	 return -1;
    }

    return 0;
}
