#include<stdio.h>
#include<stdlib.h>

void swap(int* x,int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void permute(int* arr,int n,unsigned long* permute_count,int** permutations,int l,int r) {
	// printf("entered permute()\n");
	if(l == r) {
		// printf("entered if \n");
		for(int i = 0;i < n;i++) {
			permutations[*permute_count][i] = arr[i];
		}
		*permute_count += 1;
	}
	else {
		for(int i = l;i <= r;i++) {
			swap(arr+l,arr+i);
			permute(arr,n,permute_count,permutations,l+1,r);
			swap(arr+l,arr+i);
		}
	}
}

unsigned long factorial(int n) {
	int i = 1;
	unsigned long result = 1;
	for(i = 1;i <= n;i++)
		result *= i;
	return result;
}

int main(int argc, char const *argv[]) {
	printf("enter no of items : \n");
	int n;
	scanf("%d",&n);
	int* values = (int*)malloc(n*sizeof(int));
	int* weight = (int*)malloc(n*sizeof(int));

	printf("enter values : \n");
	for(int i = 0;i < n;i++) {
		scanf("%d",&values[i]);
	}
	printf("enter weight : \n");
	for(int i = 0;i < n;i++) {
		scanf("%d",&weight[i]);
	}

	printf("enter max capacity : \n");
	int max_capacity;
	scanf("%d",&max_capacity);

	unsigned long permute_count = factorial(n);
	int** permutations = (int**)malloc(permute_count*sizeof(int*));
	for(unsigned long i = 0;i < permute_count;i++)
		permutations[i] = (int*)malloc(n*sizeof(int));

	int* index_arr = (int*)malloc(n*sizeof(int));
	for(int i = 0;i < n;i++)
		index_arr[i] = i;
 
 	unsigned long temp = 0;
	permute(weight,n,&temp,permutations,0,n-1);

	for(int i = 0;i < permute_count;i++) {
		for(int j = 0;j < n;j++)
			printf("%d ",permutations[i][j]);
		printf("\n");
	}



	return 0;
}