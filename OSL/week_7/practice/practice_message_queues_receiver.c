//Practice lab 7

//By - Teja Juluru
//Created on - 24/9/19

//Message queues
//Receiver program
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
	long msg_recv_type = 0;
	int msgid = msgget((key_t)1234,0666|IPC_CREAT);
	if(msgid == -1) {
		printf("Error in creating message queue\n");
		exit(-1);
	}

	while(running) {
		if(msgrcv(msgid,(void*)&message,MSGSIZ,msg_recv_type,0) == -1) {
			printf("msgrcv failed\n");
			exit(-1);
		}
		printf("Message received = %s\n",message.msg);
		if(strncmp(message.msg,"quit",4) == 0) { //Check if "quit" is typed
			printf("quit signal received\n");
			running = 0;
		}
	}

	if(msgctl(msgid,IPC_RMID,0) == -1) {
		printf("Error in deleting the message queue\n");
		exit(-1);
	}
	return 0;
}