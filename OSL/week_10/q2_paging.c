//OS Lab week 10, Q2

//By - Teja Juluru
//Created on - 9/10/19

//C program to simulate memory mapping
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main(int argc, char const *argv[])
{
	int pg_sz;
	printf("Enter page size : \n");
	scanf("%d",&pg_sz);

	int no_of_pgs;
	printf("Enter no. of pages : \n");
	scanf("%d",&no_of_pgs);

	int no_of_frms;
	printf("Enter no. of frames : \n");
	scanf("%d",&no_of_frms);

	if(no_of_frms < no_of_pgs) {
		printf("Error. no of frames < no of pages\n");
		exit(-1);
	}

	srand((unsigned int)getpid());
	int* flag_arr = (int*)malloc(no_of_frms*sizeof(int));

	return 0;
}