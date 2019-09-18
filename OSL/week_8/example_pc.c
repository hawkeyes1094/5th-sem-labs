//OS Lab week 8, Example 4

//By - Teja Juluru
//Created on - 18/9/19

//Producer-consumer example using semaphores
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

int buf[5],f,r;
sem_t mutex,full,empty;

void* produce(void* param) {
	int i,val1,val2;
	printf("Producer created\n");
	for(i = 0;i < 5;i++) {
		sem_wait(&empty);
		sem_wait(&mutex);
		printf("produced item is %d\n",i);
		buf[(++r)%5] = i;
		// sleep(1);
		sem_getvalue(&full,&val1);
		sem_getvalue(&empty,&val2);
		printf("P -> item = %d, full = %d, empty = %d\n",i,val1,val2);
		sem_post(&mutex);
		sem_post(&full);
		printf("full %ld\n",full);
	}
}

void* consume(void* param) {
	int item,i,val1,val2;
	printf("Consumer created\n");
	for(i = 0;i < 5;i++) {
		sem_wait(&full);
		sem_wait(&mutex);
		item = buf[f];
		f = (f+1)%5;
		printf("Consumed item is %d\n",item);
		// sleep(1);
		sem_getvalue(&full,&val1);
		sem_getvalue(&empty,&val2);
		printf("C -> item = %d, full = %d, empty = %d\n",item,val1,val2);
		sem_post(&mutex);
		sem_post(&empty);
		printf("empty %ld\n",empty);
	}
}

int main(int argc, char const *argv[])
{
	pthread_t thread1,thread2;
	sem_init(&mutex,0,1);
	sem_init(&full,0,0);
	sem_init(&empty,0,5);

	pthread_create(&thread1,0,produce,0);
	pthread_create(&thread2,0,consume,0);
	pthread_join(thread1,0);
	pthread_join(thread2,0);
	return 0;
}