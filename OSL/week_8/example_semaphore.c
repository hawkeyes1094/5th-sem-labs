//OS Lab week 8, Example 3

//By - Teja Juluru
//Created on - 18/9/19

//Semaphore example
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

sem_t semaphore;

void* func1(void* param) {
	printf("Thread 1\n");
	sem_post(&semaphore);
}

void* func2(void* param) {
	sem_wait(&semaphore);
	printf("Thread 2\n");
}

int main(int argc, char const *argv[])
{
	pthread_t thread1,thread2;
	sem_init(&semaphore,0,1);
	pthread_create(&thread1,0,func1,0);
	pthread_create(&thread2,0,func2,0);
	pthread_join(thread1,0);
	pthread_join(thread2,0);
	sem_destroy(&semaphore);
	return 0;
}