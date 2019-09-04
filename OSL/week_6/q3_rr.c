//OS Lab week 6, Q3

//By - Teja Juluru
//Created on - 4/9/19

//Program to simulate Round Robin scheduling algorithm
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter the number of processes : ");
	scanf("%d",&n);

	int time_quantum;
	printf("Enter time quantum : ");
	scanf("%d",&time_quantum);

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
	int pid = 0;
	while(processes_completed < n) {
		if(time < process_table[pid][1]) { //if the time is less than arrival time
			//Infinite loop danger
			//If the 1st process' arrival time is > 0
			if(pid == 0 && process_table[pid][1] > 0) { // To prevent infinite loop
				time += process_table[pid][1];
			}
			pid = (pid + 1) % n;
			continue;
		}
		if(time_quantum < process_table[pid][2]) { //if the time quantum is < burst time of the process
			process_table[pid][2] -= time_quantum;
			time += time_quantum;
		}
		else{ //if the burst time of the process is <= time quantum
			time += process_table[pid][2];
			process_table[pid][2] = 0;
		}
		if(process_table[pid][2] == 0 && process_mark[pid] == 0) {
			process_mark[pid] = 1;
			processes_completed += 1;
			printf("Process P%d completed\n",pid+1);
			printf("Turnaround time of process P%d = %d\n",pid+1,(time - process_table[pid][1])); // Turnaround = completion time - arrival time
			waiting_time[pid] = (time - process_table[pid][1]) - waiting_time[pid]; //Waiting time = Turnaround time - Burst time
			printf("Waiting time of process P%d = %d\n\n",pid+1,waiting_time[pid]);
		}
		pid = (pid + 1) % n;
	}
	return 0;
}