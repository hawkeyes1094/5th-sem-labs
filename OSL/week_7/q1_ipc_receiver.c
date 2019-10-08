//OS Lab week 7, Q1

//By - Teja Juluru
//Created on - 8/10/19

//Process A sends a number to process B.
//Process B checks wether the number is a palindrome or not.
//Implement this IPC using message queue.
//Receiver code
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

int reverse(int x) {
	int y = 0;
	while(x > 0) {
		y *= 10;
		y += x % 10;
		x /= 10;
	}
	return y;
}

int main(int argc, char const *argv[])
{
	struct msg_struct message;
	int msgid;
	msgid = msgget((key_t)1234,0666|IPC_CREAT);
	if(msgid == -1) {
		printf("Error in creating message queue\n");
		exit(-1);
	}
	int msg_to_rcv = 0; //First message in queue is read
	while(1) {
		if(msgrcv(msgid,(void*)&message,sizeof(int),msg_to_rcv,0) == -1) {
			printf("Error in receiving messages\n");
			exit(-1);
		}
		if(message.msg < 0) {
			printf("Exit signal recieved = %d\n",message.msg);
			if(msgctl(msgid,IPC_RMID,0) == -1) {
				printf("Error in deleting the message queue\n");
				exit(-1);
			}
			break;
		}
		printf("Number received = %d\n",message.msg);
		if(message.msg == reverse(message.msg))
			printf("Number received is a palindrome\n");
		else
			printf("Number received is not a palindrome\n");
	}
	return 0;
}