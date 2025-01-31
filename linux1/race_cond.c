#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
int shared=1;
void *fun1()
{
	int x;
	x=shared;
	printf("\nshared value = %d",x);
	x++;
	shared=x;
	printf("\nupdated shared value = %d",shared);
	pthread_exit(NULL);
}
void *fun2()
{
	int y;
	y=shared;
	printf("\nshared value = %d",y);
	y--;
	shared=y;
	printf("\nupdated shared value = %d",y);
	pthread_exit(NULL);
}
int main()
{
	pthread_t t1,t2;
	pthread_create(&t1,NULL,fun1,NULL);
	pthread_create(&t2,NULL,fun2,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("\nfinal shared value = %d",shared);
	return 0;
}
