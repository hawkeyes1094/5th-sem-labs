//OS Lab week 5, example 1

//By - Teja Juluru
//Created on - 28/8/19

//Example program to create a new thread
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void* thread_code(void* param) {
	printf("In thread code\n");
}

int main(int argc, char const *argv[])
{
	pthread_t thread;
	int return_val;
	return_val = pthread_create(&thread,0,&thread_code,0);
	if(return_val != 0) {
		printf("Error in creating thread %d\n",return_val);
		exit(-1);
	}
	sleep(1);
	printf("In main thread\n");
	return 0;
}