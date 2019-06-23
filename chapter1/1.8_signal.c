#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

#define MAXLINE 8196

void sig_int(int signo)
{
	printf("interrupt\n");
}

int main(void)
{
	char buf[MAXLINE];
	pid_t pid;
	int status;

	printf("process ID %d\n",getpid());

	if(signal(SIGINT,sig_int) == SIG_ERR)
		printf("signal_error");

	while (fgets(buf,MAXLINE,stdin) != NULL)
	{
		buf[strlen(buf)-1] = 0;
		if((pid = fork()) < 0)
			printf("fork error");
		else if (pid == 0)
		{
			//child			
			printf("child process ID %d\n",getpid());
			execlp(buf,buf,(char*)0);
			exit(127);
		}

		//parent
		if(pid = waitpid(pid,&status,0) < 0)
			printf("waitpid error");
	}

	return 0;	
}
