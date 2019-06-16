#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent *dirp;
	
	if (argc !=2)
	{
		printf("the directory name is required\n");
		return 0;
	}

	if ((dp = opendir(argv[1])) == NULL)
		printf("can not open %s\n",argv[1]);

	while ((dirp = readdir(dp)) != NULL)
		printf("%s\n", dirp->d_name);

	closedir(dp);

	return 0;
}
