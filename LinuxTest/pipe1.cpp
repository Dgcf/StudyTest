#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


#define DEF_PAGER	"/bin/more"
#define MAXLINE 64


int main()
{
	int n;
	int fd[2];
	pid_t pid;
	char *pager, *argv0;
	char line[MAXLINE];
	FILE *fp;

	if(argc != 2)
	{
		printf("Error\n");
	}
	if((fp = fopen(argv[1], "r")) == NULL)
	{
		printf("File Open error\n");
	}
	if(pipe(fd) < 0)
	{
		printf("pipe error\n");
	}
	else if(pid > 0)
	{
		close(fd[0]);
		while(fget(line, MAXLINE, fp) != NULL)
		{
			n = strlen(line);
			if(write(fd[1], line, n) != n)
			{
				printf("write error to pipe\n");
			}
		}
		if(ferror(fp))
		{
			printf("fgets error\n");
		}
	}
	else
	{
		close(fd[1]);
		if(fd[0] != STDIN_FILENO)
		{
			if(dup2(fd[0], STDIN_FILENO) != STDIN_FILENO)
			{
				printf("dup2 error to stdin\n");
			}
			close(fd[0]);
		}
	}
}
