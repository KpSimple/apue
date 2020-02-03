#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/time.h>
#include <utime.h>

#define MAXLINE 1024

int main(int argc, char *argv[])
{
    FILE * pFile=NULL; 
    long size; 
    pFile = fopen ("myfile.txt","rb"); 
    if (pFile==NULL) 
	printf("Error opening file"); 
    else
    { 
    	fseek (pFile, 0, SEEK_END);
     	size=ftell (pFile); 
     	fclose (pFile);
     	pFile=NULL;
      	printf ("Size of myfile.txt is: %ld bytes.\n",size); 
    } 

    return 0; 
}
