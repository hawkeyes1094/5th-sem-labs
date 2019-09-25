//OS Lab week 9, Q1

//By - Teja Juluru
//Creatd on - 25/9/19

//Banker's algorithm for deadlock avoidance
#include<stdio.h>
#include<stdlib.h>

int CompareVectors(int* a,int* b,int len) { //Check if vector a <= vector b
	for(int i = 0;i < len;i++) {
		if(a[i] > b[i])
			return 0;
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	int n,m;
	printf("Enter the no. of processes : ");
	scanf("%d",&n);
	printf("Enter the no. of resource types : ");
	scanf("%d",&m);

	//Required data structures
	int* available = (int*)malloc(m*sizeof(int));

	int** max = (int**)malloc(n*sizeof(int*));
	for(int i = 0;i < n;i++)
		max[i] = (int*)malloc(m*sizeof(int));

	int** allocation = (int**)malloc(n*sizeof(int*));
	for(int i = 0;i < n;i++)
		allocation[i] = (int*)malloc(m*sizeof(int));

	int** need = (int**)malloc(n*sizeof(int*));
	for(int i = 0;i < n;i++)
		need[i] = (int*)malloc(m*sizeof(int));

	printf("Enter the allocation matrix : \n");
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++)
			scanf("%d",&allocation[i][j]);
	}

	printf("Enter the max matrix : \n");
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			scanf("%d",&max[i][j]);
			need[i][j] = max[i][j] - allocation[i][j];
		}
	}

	printf("Enter the available vector : \n");
	for(int i = 0;i < m;i++)
		scanf("%d",&available[i]);

	printf("\nNeed matrix = \n");
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++)
			printf("%d ",need[i][j]);
		printf("\n");
	}

	//Safety algorithm
	int* work = (int*)malloc(m*sizeof(int));
	int* finish = (int*)malloc(n*sizeof(int));

	//work = available
	for(int i = 0;i < m;i++)
		work[i] = available[i];

	while(1) {
		int i;
		for(i = 0;i < n;i++) {
			if(!finish[i] && CompareVectors(need[i],work,m)) {
				break;
			}
		}
		if(i == n)
			break;
		//work = work + allocation
		for(int j = 0;j < m;j++)
			work[j] += allocation[i][j];

		finish[i] = 1;
	}

	int safe_state = 1;
	for(int i = 0;i < n;i++) {
		if(finish[i] != 1) {
			safe_state = 0;
			break;
		}
	}

	if(safe_state == 1)
		printf("\nSystem in safe state\n");
	else
		printf("\nSystem in unsafe state\n");
	
	int request_id = 0;
	int* request = (int*)malloc(m*sizeof(int));
	while(1) {
		printf("Enter the process number which requests (-1 to end): ");
		scanf("%d",&request_id);
		if(request_id < 0)
			break;
		printf("Enter the request vector of process %d\n",request_id);
		for(int i = 0;i < m;i++)
			scanf("%d",&request[i]);

		if(!CompareVectors(request,need[request_id],m)) {
			printf("\nERROR. Process exceeded max claim\n");
			exit(-1);
		}

		if(CompareVectors(request,available,m)) {
			//availabe = available - request[request_id]
			for(int i = 0;i < m;i++)
				available[i] -= request[i];
			//allocation[request_id] = allocation[request_id] + request
			for(int i = 0;i < m;i++)
				allocation[request_id][i] += request[i];
			//need[request_id] = need[request_id] - request
			for(int i = 0;i < m;i++)
				need[request_id][i] -= request[i];
			printf("Request granted immediately\n");

			printf("Updated tables are : \n");
			printf("Allocation table : \n");
			for(int i = 0;i < n;i++) {
				for(int j = 0;j < m;j++)
					printf("%d ",allocation[i][j]);
				printf("\n");
			}
			printf("need table : \n");
			for(int i = 0;i < n;i++) {
				for(int j = 0;j < m;j++)
					printf("%d ",need[i][j]);
				printf("\n");
			}
			printf("Available vector : \n");
			for(int i = 0;i < m;i++)
				printf("%d ",available[i]);
			printf("\n");
			
		}
		else{
			printf("Process %d must wait\n",request_id);
		}
	}
	return 0;
}