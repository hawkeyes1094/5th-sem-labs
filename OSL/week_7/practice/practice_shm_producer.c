//Practice lab 7

//By - Teja Juluru
//Created on - 24/9/19

//Shared memory
//Producer process
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/shm.h>
#define MSGSIZE 256

struct shm_str{
	int written;
	char message[MSGSIZE];
};

int main(int argc, char const *argv[])
{
	int running = 1;
	// void* shared_memory;
	struct shm_str* shared_message;
	int shmid = shmget((key_t)1234,sizeof(struct shm_str),0666|IPC_CREAT);
	if(shmid == -1) {
		printf("Error in creating shared memory\n");
		exit(-1);
	}
	shared_message = (struct shm_str*)shmat(shmid,NULL,0);
	if(shared_message == (struct shm_str*)-1) {
		printf("shmat failed\n");
		exit(-1);
	}
	printf("Memory attached at %p\n",shared_message);
	while(running) {
		while(shared_message->written == 1) {
			sleep(1);
			printf("Waiting for the client\n");
		}
		printf("Enter some text : \n");
		fgets(shared_message->message,MSGSIZE,stdin);
		shared_message->written = 1;
		if(strncmp(shared_message->message,"quit",4) == 0) {
			printf("quit message received\n");
			running = 0;
		}
	}
	if(shmdt((void*)shared_message) == -1) {
		printf("shmdt failed\n");
		exit(-1);
	}
	return 0;
}