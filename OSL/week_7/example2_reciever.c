//OS Lab week 7, Example 2

//By - Teja Juluru
//Created on - 11/9/19

//Example message queues program
//reciever program
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<errno.h>

struct my_msg_st{
	long int my_msg_tyoe;
	char some_text[BUFSIZ];
};

int main(int argc, char const *argv[])
{
	int running = 1;
	int msgid;
	struct my_msg_st some_data;
	long int msg_to_recieve = 0;

	msgid = msgget((key_t)1234,0666 | IPC_CREAT);
	if(msgid == -1) {
		fprintf(stderr,"msgget failed with error : %d\n",errno);
		exit(EXIT_FAILURE);
	}

	while(running) {
		if(msgrcv(msgid,(void*)&some_data,BUFSIZ,msg_to_recieve,0) == -1) {
			fprintf(stderr,"msgrcv failed with error : %d\n",errno);
			exit(EXIT_FAILURE);
		}
		printf("You wrote : %s\n",some_data.some_text);
		if(strncmp(some_data.some_text,"end",3) == 0) {
			running = 0;
		}
	}
	if(msgctl(msgid,IPC_RMID,0) == -1) {
		fprintf(stderr,"msgctl(IPC_RMID) failed\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
	return 0;
}