//Eval 2

//By - Teja Juluru
//Created on - 25/9/19

//SJF simulation
#include<stdio.h>

typedef struct{
	int pid;
	int arrival_time;
	int burst_time;
	int turnaround_time;
}process;

int main(int argc, char const *argv[])
{
	printf("Enter the no. of processes : ");
	int n;
	scanf("%d",&n);
	process p[10];
	for(int i = 0;i < n;i++) {
		printf("Enter arrival and burst time of %d : \n",i);
		scanf("%d",&(p[i].arrival_time));
		scanf("%d",&(p[i].burst_time));
		p[i].pid = i;
	}

	int processes_completed = 0;
	int burst_times[10];
	for(int i = 0;i < n;i++)
		burst_times[i] = p[i].burst_time;

	int t = 0;
	printf("\nGnatt chart : \n");
	printf("|");
	if(t < p[0].arrival_time) {
		for(int i = 0;i < p[0].arrival_time;i++)
			printf(" ");
	}

	t += p[0].arrival_time;
	while(processes_completed < n) {
		int cur_process;
		int least_time = 9999;
		for(int i = 0;i < n;i++) {
			if(p[i].arrival_time <= t && p[i].burst_time < least_time && p[i].burst_time > 0) {
				cur_process = p[i].pid;
				least_time = p[i].burst_time;
			}
		}

		printf("%d",cur_process+1);
		t++;
		p[cur_process].burst_time -= 1;
		if(p[cur_process].burst_time == 0) {
			processes_completed++;
			p[cur_process].turnaround_time = t - p[cur_process].arrival_time;
		}
		
	}
	printf("|\n");
	printf("Turnaround times = \n");
	for(int i = 0;i < n;i++) {
		printf("PID = %d, Turnaround time = %d\n",p[i].pid+1,p[i].turnaround_time);
	}
	return 0;
}
