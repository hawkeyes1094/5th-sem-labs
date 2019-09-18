//OS Lab week 8, Example 1

//By - Teja Juluru
//Created on - 18/9/19

//Program to simulate race condition
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int counter = 0;

void* thread_func(void* param) {
	int thread_id = (int*)param;
	for(int i = 0;i < 5;i++) {
		printf("thread ID  = %d\n",thread_id);
		counter++;
		printf("counter = %d\n",counter);
	}
}

int main(int argc, char const *argv[])
{
	pthread_t thread1,thread2;

	pthread_create(&thread1,0,thread_func,(void*)1);
	pthread_create(&thread2,0,thread_func,(void*)2);
	pthread_join(thread1,0);
	pthread_join(thread2,0);

	return 0;
}