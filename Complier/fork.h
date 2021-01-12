#include <unistd.h>

int main()
{
	int var;
	pid_t pid;
	var = 88;
	
	int global = 0;
	pid = fork();
	if(0 == pid)
	{
		++global;
	}
	else if(
}