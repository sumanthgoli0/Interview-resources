#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include<sys/ipc.h>
int main()
{
	int shmid;
	char *mssg;
	char b[50];
	shmid=shmget((key_t)123,1024,0666|IPC_CREAT);
	mssg=shmat(shmid,NULL,0);
	printf("enter data = ");
	scanf("%[^\n]s",b);
	strcpy(mssg,b);
	printf("sent data is %s\n",b);
	shmdt(mssg);
	return 0;
}
