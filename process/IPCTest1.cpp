#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>

using namespace std;

void charatatime(char *str)
{
	char *ptr;
	int c;
	
	setbuf(stdout, NULL);
	for(ptr = str; (c=*ptr++) != 0;)
	{
		putc(c, stdout);
	}
}

int main()
{
	pid_t pid = fork();
	if(pid < 0)
	{
		cout << "fork fail" << endl;
	}
	else if(pid == 0)
	{
		charatatime("output from child\n");
	}
	else
	{
		charatatime("output from parent\n");
	}
	
	exit(0);
}

