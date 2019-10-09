//OS Lab week 10, Q1

//By - Teja Juluru
//Created on - 9/10/19

//Simulate first-fit, best-fit, worst-fit strategies
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
	int m; //No of memory partitions
	printf("Enter number of memory partitions : \n");
	scanf("%d",&m);
	int* mem_arr = (int*)malloc(m*sizeof(int));
	printf("Enter the sizes of memory partitions : \n");
	for(int i = 0;i < m;i++) {
		scanf("%d",&mem_arr[i]);
	}

	int n; //No of processes
	printf("Enter no. of processes : \n");
	scanf("%d",&n);
	int* p_arr = (int*)malloc(n*sizeof(int));
	printf("Enter memory sizes of the processes : \n");
	for(int i = 0;i < n;i++) {
		scanf("%d",&p_arr[i]);
	}

	
	//First-fit
	printf("\n--------------------------------------------------------------\n");
	printf("First-fit\n\n");
	int* first_fit = (int*)malloc(m*sizeof(int));
	for(int i = 0;i < m;i++)
		first_fit[i] = mem_arr[i];

	int first_fit_internal_frag = 0;
	for(int i = 0;i < n;i++) { //loop over each process
		int j;
		for(j = 0;j < m;j++) { //loop over partitions
			if(p_arr[i] <= first_fit[j]) {
				printf("process %d of size %d placed in %d\n",i,p_arr[i],first_fit[j]);
				first_fit_internal_frag += first_fit[j] - p_arr[i];
				first_fit[j] = 0;
				break;
			}
		}
		if(j == m) {
			printf("process %d could not be allocated memory\n",i);
		}
	}
	printf("Total internal fragmentation = %d\n",first_fit_internal_frag);
	printf("--------------------------------------------------------------\n");

	
	//Best-fit
	printf("\n--------------------------------------------------------------\n");
	printf("Best-fit\n\n");
	int* best_fit = (int*)malloc(m*sizeof(int));
	for(int i = 0;i < m;i++) {
		best_fit[i] = mem_arr[i];
	}

	int best_fit_internal_frag = 0;
	for(int i = 0;i < n;i++) { //loop over each process
		int best_fit_size = 99999;
		int best_fit_size_index = m;
		for(int j = 0;j < m;j++) { //loop over partitons
			if(p_arr[i] <= best_fit[j] && best_fit[j] < best_fit_size) {
				best_fit_size = best_fit[j];
				best_fit_size_index = j;
			}
		}
		if(best_fit_size_index == m) {
			printf("process %d could not be allocated memory\n",i);
			continue;
		}
		printf("process %d of size %d placed in %d\n",i,p_arr[i],best_fit_size);
		best_fit_internal_frag += best_fit_size - p_arr[i];
		best_fit[best_fit_size_index] = 0;
	}
	printf("Total internal fragmentation = %d\n",best_fit_internal_frag);
	printf("--------------------------------------------------------------\n");

	
	//Worst-fit
	printf("\n--------------------------------------------------------------\n");
	printf("Worst-fit\n");
	int* worst_fit = (int*)malloc(m*sizeof(int));
	for(int i = 0;i < m;i++) {
		worst_fit[i] = mem_arr[i];
	}

	int worst_fit_internal_frag = 0;
	for(int i = 0;i < n;i++) {
		int worst_fit_size = 0;
		int worst_fit_size_index = -1;
		for(int j = 0;j < m;j++) {
			if(p_arr[i] <= worst_fit[j] && worst_fit[j] > worst_fit_size) {
				worst_fit_size = worst_fit[j];
				worst_fit_size_index = j;
			}
		}
		if(worst_fit_size_index == -1) {
			printf("process %d could not be allocated memory\n",i);
			continue;	
		}
		printf("process %d of size %d placed in %d\n",i,p_arr[i],worst_fit_size);
		worst_fit_internal_frag += worst_fit_size - p_arr[i];
		worst_fit[worst_fit_size_index] = 0;
	}
	printf("Total internal fragmentation = %d\n",worst_fit_internal_frag);
	printf("--------------------------------------------------------------\n");
	return 0;
}