#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<unistd.h>
struct buff
{
long	int i;
	char c[100];
};
int main()
{
	int msgid;
	struct buff s;
	msgid=msgget((key_t)124,0666);
	if(msgid==-1)
	{
		printf("msgget failed");
		return 1;
	}
	if(msgrcv(msgid,&s,sizeof(s),1,0)==-1)
	{
		printf("msgrcv failed");
		return 1;
	}
	printf("mssg recived %s",s.c);
	if(msgctl(msgid,IPC_RMID,NULL)==-1)
	{
		printf("msgctl failed");
		return 1;
	}
	return 0;
}
