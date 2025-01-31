#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<unistd.h>
struct buff
{
	long int i;
	char c[100];
};
int main()
{
	int msgid;
	struct buff s;
	msgid=msgget((key_t)124,0666|IPC_CREAT);
	if(msgid==-1)
	{
		printf("msgget failed");
		return 1;
	}
	s.i=1;
	//printf("enter message = ");
	strcpy(s.c,"hello world");
	if(msgsnd(msgid,&s,sizeof(s),1)==-1)
	{
		printf("msgsnd failed");
		return 1;
	}
	printf("message sent %s",s.c);
	return 0;
}

