//OS Lab week 7, Q4

//By - Teja Juluru
//Created on - 13/10/19

//Producer consumer program in which producer writes 
//a set of words into the shared memory and the consumer
// reads the set of words from the shared memory.

//Consumer code
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#define STRINGSIZ 128
#define NO_OF_STRINGS 4

typedef struct{
	int count;
	char strings[NO_OF_STRINGS][STRINGSIZ];
}shared_str;


int main(int argc, char const *argv[])
{
	int shmid = shmget((key_t)1234,sizeof(shared_str),0666|IPC_CREAT);
	shared_str* shared_mem = shmat(shmid,(void*)0,0);
	if(shared_mem == (void*)-1) {
		printf("shmat() failed\n");
		exit(-1);
	}

	int msg_ptr = 0;
	while(1) {
		if(shared_mem->count == 0) {
			// sleep(1);
			continue;
		}
		char buf[STRINGSIZ];
		strcpy(buf,shared_mem->strings[msg_ptr]);
		if(strcmp(buf,"exit") == 0) {
			printf("Exit signal received. Exiting...\n");
			break;
		}
		printf("Message received : \n");
		printf("%s\n",buf);
		shared_mem->count -= 1;
		msg_ptr = (msg_ptr + 1)%NO_OF_STRINGS;
	}
	if(shmdt(shared_mem) == -1) {
		printf("shmdt() failed\n");
		exit(-1);
	}
	return 0;
}