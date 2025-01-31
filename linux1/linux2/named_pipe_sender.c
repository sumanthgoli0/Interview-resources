#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/ipc.h>
int main()
{
	char b[50];
	int fd;
	fd=mkfifo("fifo",0666|IPC_CREAT);
	if(fd==-1)
	{
		printf("file not created");
		return 0;
	}
//	printf("file created\n");
	int i=open("fifo",O_WRONLY);
	if(i==-1)
	{
		printf("open failed");
		return 0;
	}
	write(i,"hello",5);
	printf("data sent \n");
}
