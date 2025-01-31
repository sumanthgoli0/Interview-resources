#include<stdio.h>
#include<unistd.h>
int main()
{
	int fd[2];
	char b[50]="hello world";
	pid_t p;
	pipe(fd);
	p=fork();
	if(p>0)
	{
		write(fd[1],b,sizeof(b));
		printf("passing data to child \n");
	}
	else
	{
		printf("child received data =\n");
		int n=read(fd[0],b,sizeof(b));
		write(1,b,n);
	}
}
