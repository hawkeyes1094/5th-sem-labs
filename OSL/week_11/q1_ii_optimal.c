//Complete this

//OS Lab week 11, Q1, ii

//By - Teja Juluru
//Created on - 16/10/19

//Simulate optimal page replacement algorithm
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
	printf("Optimal algorithm\n");
	int n;
	printf("Enter no. of pages : \n");
	scanf("%d",&n);
	int pages[n];

	//Initialize them to -1
	for(int i = 0;i < n;i++)
		pages[i] = -1;

	int page_request[100];
	printf("Enter the page requests (-1 to end) : \n");
	int i= 0,x = 0;
	while(1) {
		scanf("%d",&x);
		if(x < 0)
			break;
		page_request[i] = x;
		i++;
	}
	int no_of_requests = i;

	int head = 0;
	int hits = 0,faults = 0;

	//optimal
	for(int i = 0;i < no_of_requests;i++) {
		
		int optimal_table[n][2];
		for(int j = 0;j < n;j++) {
			optimal_table[i][0] = pages[i];
			optimal_table[i][1] = n;
		}
		for(int j = i;j < )
	}
	return 0;
}