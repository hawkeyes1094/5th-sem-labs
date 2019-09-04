//OS Lab week 6, Q1

//By - Teja Juluru
//Created on - 4/9/19

//Program to simulate FCFS scheduling algorithm
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter the number of processes : ");
	scanf("%d",&n);

	/*
	+---------+--------------+------------+----------+
	| Process | Arrival time | Burst time | Priority |
	+---------+--------------+------------+----------+ */
	int** process_table = (int**)malloc(n*sizeof(int*));
	for(int i = 0;i < n;i++)
		process_table[i] = (int*)malloc(4*sizeof(int));

	printf("Enter the process info in order of arrival time\n");
	for(int i = 0;i < n;i++) {
		printf("Enter arrival time, burst time & priority of process P%d\n",i+1);
		process_table[i][0] = i+1;
		scanf("%d",&process_table[i][1]);
		scanf("%d",&process_table[i][2]);
		scanf("%d",&process_table[i][3]);
	}

	/*
	For FCFS scheduling
	Turnaround time = Completion time - Arrival time
	Waiting time = Turnaround time - Burst time
	*/
	int time = 0;
	int waiting_time = 0;
	int turnaround = 0;
	for(int i = 0;i < n;i++) {
		time += process_table[i][2]; //add burst time
		turnaround = time - process_table[i][1]; //subtract arrival time
		waiting_time = turnaround - process_table[i][2]; //subtract burst time
		printf("Process = %d, Turnaround = %d, Waiting time = %d\n",i+1,turnaround,waiting_time);
	}

	return 0;
}