//OS Lab week 6, Q2

//By - Teja Juluru
//Created on - 4/9/19

//Program to simulate Shortest remaining time first(SRTF) scheduling algorithm
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter the number of processes : ");
	scanf("%d",&n);

	/*
	+---------+--------------+--------------------------------+
	| Process | Arrival time | Burst time/Execution time left |
	+---------+--------------+--------------------------------+ */
	int** process_table = (int**)malloc(n*sizeof(int*));
	for(int i = 0;i < n;i++)
		process_table[i] = (int*)malloc(3*sizeof(int));

	printf("Enter the process info in order of arrival time\n");
	for(int i = 0;i < n;i++) {
		printf("Enter arrival time & burst time of process P%d\n",i+1);
		process_table[i][0] = i+1;
		scanf("%d",&process_table[i][1]);
		scanf("%d",&process_table[i][2]);
	}

	int* waiting_time = (int*)malloc(n*sizeof(int));
	for(int i = 0;i < n;i++) { //copy the burst times into the waiting times array
		waiting_time[i] = process_table[i][2];
	}

	int* process_mark = (int*)malloc(n*sizeof(int)); //flags to mark which processes are completed
	int processes_completed = 0; //no. of processes completed
	int time = 0;
	int current_pid = 0;

	//Before all processes arrive
	time += process_table[0][1]; //To consider the case : if the arrival time of P1 is > 0
	for(int i = 0;i < n -1;i++) {
		time += process_table[i+1][1] //add the arrival time of the next process to time
		
	}

	return 0;
}