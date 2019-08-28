//OS Lab week 5, Q2

//By - Teja Juluru
//Created on - 28/8/19

//Multithreaded program to generate
// primes between two limits

//Not working

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>

void* generate_primes(void* param) {
	int m = ((int*)param)[0];
	int n = ((int*)param)[1];
	int* primes = (int*)malloc(100*sizeof(int));
	int prime_count = 0;

	//generate primes
	for(int i = m;i <= n;i++) {
		int root = sqrt(i);
		int j;
		for(j = 2;j <= root;j++) {
			if(i % j == 0)
				break;
		}
		if(j == root+1) {
			primes[prime_count+1] = 1;
			prime_count++;
		}
	}
	primes[0] = prime_count;
	return (void*)primes;
}

int main(int argc, char const *argv[])
{
	int m,n;
	printf("Enter lower limit : ");
	scanf("%d",&m);
	printf("Enter upper limit : ");
	scanf("%d",&n);
	int arr[2] = {m,n};
	int* primes;

	pthread_t thread;
	pthread_create(&thread,0,&generate_primes,(void*)arr);
	pthread_join(thread,(void**)primes);

	int prime_count = primes[0];
	for(int i = 1;i <= prime_count;i++) {
		printf("%d ",primes[i]);
	}
	printf("\n");

	return 0;
}