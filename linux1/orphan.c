#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	pid_t p;
	p=fork();
	if(p==0)
	{
		sleep(1);
		printf("\nchild prpcess is created");

		printf("\nchild pid %d",getpid());
		printf("\nparent pid %d",getppid());
	}
	else
	{
		printf("\nparent process is created ");
		printf("\nparent pid is %d",getpid());
		printf("\nparent parent'spid is %d",getppid());
	}
	return 0;

}
