#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int res,n;
	char b[20];
	res=open("fifo",O_RDONLY);
	n=read(res,b,sizeof(b));
	printf("data received %s\n",b);
	return 0;
}
