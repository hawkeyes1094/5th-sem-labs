//OS Lab week 5, Q4

//By - Teja Juluru
//Created on - 3/9/19

//Program to find sum of even and odd numbers in an
// input array using two seperate threads
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void* odd_sum_func(void* param) {
	int* arr = (int*)param;
	int n = arr[0];
	int odd_sum = 0;

	for(int i = 1;i <= n;i++) {
		if(arr[i] % 2 == 1)
			odd_sum += arr[i];
	}

	return (void*)odd_sum;
}

void* even_sum_func(void* param) {
	int* arr = (int*)param;
	int n = arr[0];
	int even_sum = 0;

	for(int i = 1;i <= n;i++) {
		if(arr[i] % 2 == 0)
			even_sum += arr[i];
	}

	return (void*)even_sum;
}

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter number of elements in the array : ");
	scanf("%d",&n);

	int* arr = (int*)malloc((n+1)*sizeof(int));
	arr[0] = n;
	printf("Enter the elements : \n");
	for(int i = 0;i < n;i++)
		scanf("%d",&arr[i+1]);

	pthread_t odd_thread,even_thread;
	int odd_sum,even_sum;

	pthread_create(&odd_thread,0,&odd_sum_func,(void*)arr);
	pthread_create(&even_thread,0,&even_sum_func,(void*)arr);
	// pthread_create(&thread,0,&summation,(void*)arr);
	pthread_join(odd_thread,(void**)&odd_sum);
	pthread_join(even_thread,(void**)&even_sum);

	printf("Sum of odd numbers is  : %d\n",odd_sum);
	printf("Sum of even numbers is : %d\n",even_sum);
	return 0;
}