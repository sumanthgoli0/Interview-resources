#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
	char b[10];
	read(0,b,10);
	write(1,b,10);
	int n;
	n=write(1,"hello",5);
	printf("\nvalue of n is %d",n);
	return 0;
}
