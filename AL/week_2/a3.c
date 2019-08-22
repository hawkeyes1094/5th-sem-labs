//Algo Lab week 2, additional 1

//By - Teja Juluru
//Created on - 2/8/19

//Compute the nth fibonacci number using recursion
#include<stdio.h>
#include<stdlib.h>

int fibo(int n) {
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	else
		return (fibo(n-1) + fibo(n-2));
}

int main(int argc, char const *argv[])
{
	printf("Enter n : ");
	int n;
	scanf("%d",&n);
	printf("nth fibo number = %d\n",fibo(n));
	return 0;
}