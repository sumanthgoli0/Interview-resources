#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
int b[50];
int count=0;
void *prod()
{
	int i;
	for(i=0;i<6;i++)
	{
		
		++count;
		while(count==5)
		{
			printf("\nbuffer is full ");
			sleep(1);
		}
		b[count]=i;
		

		printf("\nproducer item is %d",b[count]);

	}
	printf("\n");
	pthread_exit(NULL);
}
void *cons()
{
	int i;
	for(i=0;i<6;i++)
	{

		while(count==0)
		{
			printf("\nempty buffer");
			sleep(1);
		}
		--count;

		printf("\nconsumed item is %d",b[i]);
	}
	printf("\n");
	pthread_exit(NULL);
}
int main()
{
	pthread_t t1,t2;
	pthread_create(&t1,NULL,&prod,NULL);
	pthread_create(&t2,NULL,&cons,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	return 0;
}
