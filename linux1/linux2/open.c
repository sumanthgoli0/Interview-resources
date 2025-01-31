#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
	char b[50];
	int n,fd;
	int i=read(0,b,sizeof(b)-1);
	fd=open("f.txt",O_RDWR|O_CREAT,0666);
	/*n=read(0,b,10);
	write(1,b,n);*/
	n=write(fd,b,i);
	n=read(fd,b,i);
	write(1,b,n);
	close(fd);
	return 0;
}
