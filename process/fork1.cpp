#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
using namespace std;

int main()
{
	pid_t pid = fork();
	if(0 == pid)
	{
		// 子进程，开始执行
		cout << "sub process, pid is:" << endl;
		sleep(5);
		cout << "end of subprocess" << endl;
	}
	else
	{
		cout << "pid != 0, sleep 5 s" << endl;
		//sleep(15);
		
		if(wait(&pid))
		{
			cout << "wait pid: " << pid << endl;
		}
	}
	
	
	
}