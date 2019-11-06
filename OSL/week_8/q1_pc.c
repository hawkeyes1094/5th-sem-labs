//OS Lab week 8, Q1

//By - Teja Juluru
//Created on - 18/9/19

//Producer-consumer
//Producer produces 10 more items than what consumer has consumed
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

int buf[15],f,r;
sem_t mutex,full,empty;
// full = empty = 0;

void* produce(void* param) {
	int i,val1,val2;
	printf("Producer created\n");
	for(i = 0;i < 100;i++) {
		sem_wait(&empty);
		sem_wait(&mutex);
		printf("produced item is %d\n",i);
		buf[r] = i;
		r = (r+1)%15;
		sem_getvalue(&full,&val1);
		sem_getvalue(&empty,&val2);
		printf("P -> item = %d, full = %d, empty = %d\n\n",i,val1,val2);
		// sleep(1);
		sem_post(&mutex);
		sem_post(&full);
		// sleep(1);
		// printf("full %ld\n",full);
	}
}

void* consume(void* param) {
	int item,i,val1,val2;
	printf("Consumer created\n");
	for(i = 0;i < 100;i++) {
		sem_wait(&full);
		sem_wait(&mutex);
		item = buf[f];
		f = (f+1)%15;
		printf("Consumed item is %d\n",item);
		sem_getvalue(&full,&val1);
		sem_getvalue(&empty,&val2);
		printf("C -> item = %d, full = %d, empty = %d\n\n",item,val1,val2);
		// sleep(1);
		sem_post(&mutex);
		sem_post(&empty);
		// sleep(1);
		// printf("empty %ld\n",empty);
	}
}

int main(int argc, char const *argv[])
{
	pthread_t thread1,thread2;
	sem_init(&mutex,0,1);
	sem_init(&full,0,5);
	sem_init(&empty,0,15);

	pthread_create(&thread1,0,produce,0);
	pthread_create(&thread2,0,consume,0);
	pthread_join(thread1,0);
	pthread_join(thread2,0);
	return 0;
}