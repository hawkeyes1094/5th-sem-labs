//Practice lab 7

//By - Teja Juluru
//Created on - 24/9/19

//Message queues
//Sender program
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#define MSGSIZ 256

struct msg_str{
	long int msg_type;
	char msg[MSGSIZ];
};

int main(int argc, char const *argv[])
{
	int running = 1;
	struct msg_str message;
	int msgid = msgget((key_t)1234,0666|IPC_CREAT);
	if(msgid == -1) {
		printf("Error in creating message queue\n");
		exit(-1);
	}

	while(running) {
		printf("Enter the message : \n");
		fgets(message.msg,MSGSIZ,stdin);
		message.msg_type = 1;
		if(msgsnd(msgid,(void*)&message,MSGSIZ,0) == -1) {
			printf("Error in msgsnd\n");
			exit(-1);
		}
		printf("Message sent\n");
		if(strncmp(message.msg,"quit",4) == 0) {
			printf("quit signal received\n");
			running = 0;
		}
	}
	return 0;
}