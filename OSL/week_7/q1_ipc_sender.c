//OS Lab week 7, Q1

//By - Teja Juluru
//Created on - 8/10/19

//Process A sends a number to process B.
//Process B checks wether the number is a palindrome or not.
//Implement this IPC using message queue.
//Sender code
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msg_struct{
	long int msg_type;
	int msg;
};

int main(int argc, char const *argv[])
{
	struct msg_struct message;
	int msgid;
	msgid = msgget((key_t)1234,0666|IPC_CREAT);
	if(msgid == -1) {
		printf("Error in creating message queue\n");
		exit(-1);
	}
	int msg;
	while(1) {
		printf("Enter a number to send (-1 to exit) : ");
		scanf("%d",&msg);
		message.msg_type = 1;
		message.msg = msg;
		if(msgsnd(msgid,(void *)&message,sizeof(int),0) == -1) {
			printf("Error is sending message\n");
			exit(-1);
		}
		if(msg < 0) {
			printf("Exiting\n");
			break;
		}
	}
	return 0;
}