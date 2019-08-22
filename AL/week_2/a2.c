//Algo Lab week 2, additional 2

//By - Teja Juluru
//Created on - 2/8/19

//Tower of Hanoi using recursion
#include<stdio.h>
#include<stdlib.h>

void TowerOfHanoi(int n,char from,char to,char aux) {
	if(n == 1) {
		printf("Move disc 1 from %c rod to %c rod\n",from,to);
		return;
	}
	TowerOfHanoi(n-1,from,aux,to);
	printf("Move disc %d from %c rod to %c rod\n",n,from,to);
	TowerOfHanoi(n-1,aux,to,from);
}

int main(int argc, char const *argv[])
{
	printf("Enter the number of discs : ");
	int n;
	scanf("%d",&n);
	TowerOfHanoi(n,'A','B','C');
	return 0;
}