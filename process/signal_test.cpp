#include <stdio.h>
#include <signal.h>
#include <unistd.h>

static void sig_usr(int);

int main(void)
{
	if(signal(SIGUSR1, sig_usr) == SIG_ERR)
	{
	    printf("sigusr1 sig_err\n");
	}
	if(signal(SIGUSR2, sig_usr) == SIG_ERR)
	{
	    printf("sigusr2 sig_err\n");
	}
	for(;;)
		pause();
}

static void sig_usr(int signo)
{
    if(signo == SIGUSR1)
	{
	    printf("received sigusr1\n");
	}
	else if(signo == SIGUSR2)
	{
	    printf("received sigusr2\n");
	}
	else
	{
	    printf("received signal %d\n", signo);
	}
}