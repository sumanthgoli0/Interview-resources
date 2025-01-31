#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
pthread_mutex_t mutex;
void *even()
{
	for(int i=1;i<=10;i++)
	{
		pthread_mutex_lock(&mutex);
		if(i%2==0)
		{
			printf("even = %d\n",i);
		}
		pthread_mutex_unlock(&mutex);
	}
}
void *odd()
{
	for(int i=0;i<=10;i++)
	{
		pthread_mutex_lock(&mutex);
		if(i%2!=0)
		{
			printf("odd = %d\n",i);
		}
		pthread_mutex_unlock(&mutex);
	}
}
int main()
{
	pthread_t t1,t2;
	pthread_create(&t1,NULL,even,NULL);
	pthread_create(&t2,NULL,odd,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_exit(NULL);
	pthread_mutex_destroy(&mutex);
	return 0;
}
