//Algo Lab week 2, additional 1

//By - Teja Juluru
//Created on - 2/8/19

//Program for compuing floor(sqrt(n))
#include<stdio.h>
#include<stdlib.h>

int sqrt_floor(int n) {
	int i = 1;
	while(i*i <= n)
		i++;
	i--;
	return i;
}

int main(int argc, char const *argv[])
{
	printf("Enter n : \n");
	int n;
	scanf("%d",&n);
	printf("floor of sqrt(n) is : %d\n",sqrt_floor(n));
	return 0;
}