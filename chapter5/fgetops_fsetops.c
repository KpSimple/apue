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
	FILE * pFile;
  	fpos_t position;

  	pFile = fopen ("myfile.txt","w");
  	fgetpos (pFile, &position);
  	fputs ("That is a sample",pFile);
  	fsetpos (pFile, &position);
  	fputs ("This",pFile);
  	fclose (pFile);
  	return 0;
}
