//OS Lab week 5, example 2

//By - Teja Juluru
//Created on - 28/8/19

//Example program to illustrate join
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void* pthread_code(void* param) {
	printf("In thread code\n");
}

int main(int argc, char const *argv[])
{
	pthread_t thread;
	pthread_create(&thread,0,&pthread_code,0);
	// sleep(1);
	printf("In main thread\n");
	pthread_join(thread,0);
	return 0;
}