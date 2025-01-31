#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
sem_t p,c;
int count=0;
char b[10];
void *prod()
{
	int i=0;
	char ch='A';
	while(1)
	{
		sem_wait(&p);
	while(count==5);
	b[i]=ch;
	i=(i+1)%5;
	ch++;
	if(i==0)
	{
		ch='A';
		printf("\nproducer produced item %s\n",b);
	}
	count++;
	sem_post(&c);
	}
	pthread_exit(NULL);
}
void *cons()
{
	int j=0;
	char s[5];
	while(1)
	{
		sem_wait(&c);
		while(count==0);
		s[j]=b[j];
		j=(j+1)%5;
		if(j==0)
		{
			printf("consumed item = %s\n",s);
		}
		count--;
		sem_post(&p);
	}
	pthread_exit(NULL);
}
int main()
{
	sem_init(&p,0,1);
	sem_init(&c,0,0);
	pthread_t t1,t2;
	pthread_create(&t1,NULL,prod,NULL);
	pthread_create(&t2,NULL,cons,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	sem_destroy(&p);
	sem_destroy(&c);
	pthread_exit(NULL);
	return 0;
}
