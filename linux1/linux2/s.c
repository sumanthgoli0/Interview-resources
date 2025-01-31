#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<fcntl.h>
#include<string.h>
int main()
{
	char *mssg;
	int shmid;
	shmid=shmget((key_t)123,1024,0666|IPC_CREAT);
	if(shmid==-1)
	{
		printf("shmid failed");
		return 0;
	}
	mssg=shmat(shmid,NULL,0);
	if(mssg==(char *)-1)

	{
		printf("shmat failed");
		return 0;
	}
	char b[]="kavitha";
	strcpy(mssg,b);
	printf("message sent %s ",b);
	shmdt(mssg);
	return 0;

}
