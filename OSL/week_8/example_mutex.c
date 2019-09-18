//OS Lab week 8, Example 2

//By - Teja Juluru
//Created on - 18/9/19

//Mutex lock example
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_mutex_t mutex;
volatile int counter = 0;

void* count(void* param) {
	for(int i = 0;i < 100;i++) {
		pthread_mutex_lock(&mutex);
		counter++;
		printf("Counter = %d, pthread ID = %ld\n",counter,pthread_self());
		pthread_mutex_unlock(&mutex);
	}
}

int main(int argc, char const *argv[])
{
	pthread_t thread1,thread2;

	pthread_mutex_init(&mutex,0);
	pthread_create(&thread1,0,count,0);
	pthread_create(&thread2,0,count,0);
	pthread_join(thread1,0);
	pthread_join(thread2,0);
	pthread_mutex_destroy(&mutex);
	return 0;
}