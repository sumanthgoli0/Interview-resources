#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int n,f;
	char b[50];
	read(f,b,10);
	write(1,b,10);
}
