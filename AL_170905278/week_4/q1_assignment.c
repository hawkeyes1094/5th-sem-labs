//Algo Lab week 4, Q1

//By - Teja Juluru

//Program for assignment problem using brute-force
//Suppose there are n jobs and n workers, find the
// min cost of completeting all jobs
#include<stdio.h>
#include<stdlib.h>

unsigned long factorial(int x) {
	unsigned long ans = 1;
	for(int i = 1;i <= x;i++)
		ans = ans*i;
	return ans;
}

void swap(int* x,int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

//generate all possible permutations
void permute(int* arr,int l,int r,int** permutations,unsigned long* permute_count) {
	if(l == r) {
		//put the array into the permutations matrix
		for(int i = 0;i <= r;i++) {
			permutations[*permute_count][i] = arr[i];
		}
		*permute_count += 1;
	}
	else {
		for(int i = l;i <= r;i++) {
			swap(arr+l,arr+i);
			permute(arr,l+1,r,permutations,permute_count);
			swap(arr+l,arr+i);
		}
	}
}

/*
void print_matrix(int** matrix,int m,int n) {
	for(int i = 0;i < m;i++) {
		for(int j = 0;j < n;j++)
			printf("%d ",matrix[i][j]);
		printf("\n");
	}
}*/

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter no of jobs : ");
	scanf("%d",&n);

	//create cost matrix
	int** cost = (int**)malloc(n*sizeof(int*));
	for(int i =0;i < n;i++)
		cost[i] = (int*)malloc(n*sizeof(int));

	//Input the costs
	printf("Enter the costs : \n");
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++)
			scanf("%d",&cost[i][j]);
	}

	//create all possible permutations
	//declare the permutations matrix
	unsigned long no_of_permutations = factorial(n);
	int** permutations = (int**)malloc(no_of_permutations*sizeof(int*));
	for(unsigned long i = 0;i < no_of_permutations;i++)
		permutations[i] = (int*)malloc(n*sizeof(int));
	//
	//send the index matrix to generate the permutations
	int* arr = (int*)malloc(n*sizeof(int));
	for(int i = 0;i < n;i++)
		arr[i] = i;
	unsigned long permute_count = 0;
	permute(arr,0,n-1,permutations,&permute_count);
	//

	//create the total cost array to find the answer
	int* total_cost = (int*)malloc(no_of_permutations*sizeof(int));
	for(int i = 0;i < no_of_permutations;i++) {
		int temp = 0;
		for(int j = 0;j < n;j++) {
			temp += cost[j][permutations[i][j]];
		}
		total_cost[i] = temp;
	}

	//find the least cost and least cost index
	int least_total_cost = total_cost[0];
	int least_total_cost_index = 0;
	for(int i = 0;i < no_of_permutations;i++) {
		if(total_cost[i] < least_total_cost) {
			least_total_cost = total_cost[i];
			least_total_cost_index = i;
		}
	}

	//print the result
	printf("least total cost = %d\n",least_total_cost);
	printf("jobs to be assigned are : \n");
	for(int i = 0;i < n;i++) {
		printf("job %d -> person %d,cost = %d\n",i+1,permutations[least_total_cost_index][i]+1,cost[i][permutations[least_total_cost_index][i]]);
	}
	return 0;
}