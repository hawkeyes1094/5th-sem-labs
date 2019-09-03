//Algo Lab week 6, Q3

//By - Teja Juluru
//Created on - 30/8/19

//Merge sort
#include<stdio.h>
#include<stdlib.h>

void Merge(int arr[],int l,int m,int r) {
	int* temp_arr = (int*)malloc((r-l+1)*sizeof(int));
	int i = l;
	int j = m+1;
	int k = 0;

	// for(int k = 0;k < (r-l+1);k++) {
	// 	if(i > m) {
	// 		temp_arr[k] = arr[j];
	// 		// k++;
	// 		j++;
	// 	}
	// 	else if(j > l) {
	// 		temp_arr[k] = arr[i];
	// 		// k++;
	// 		i++;
	// 	}
	// 	else if(arr[i] < arr[j]) {
	// 		temp_arr[k] = arr[i];
	// 		// k++;
	// 		i++;
	// 	}
	// 	else {
	// 		temp_arr[k] = arr[j];
	// 		// k++;
	// 		j++;
	// 	}
	// }

	while(i <= m && j <= r) {
		if(arr[i] < arr[j]) {
			temp_arr[k] = arr[i];
			i++;
		}
		else {
			temp_arr[k] = arr[j];
			j++;
		}
		k++;
	}

	while(i <= m) {
		temp_arr[k] = arr[i];
		i++;
		k++;
	}

	while(j <= r) {
		temp_arr[k] = arr[j];
		j++;
		k++;
	}

	for(int p = 0;p < (r-l+1);p++) {
		arr[l+p] = temp_arr[p];
	}
}

void MergeSort(int arr[],int l,int r) {
	if(l < r) {
		int m = (l+r)/2;

		MergeSort(arr,l,m);
		MergeSort(arr,m+1,r);
		Merge(arr,l,m,r);
	}
}

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter number of elements : ");
	scanf("%d",&n);

	int* arr = (int*)malloc(n*sizeof(int));

	printf("Enter the elements : \n");
	for(int i = 0;i < n;i++)
		scanf("%d",&arr[i]);

	MergeSort(arr,0,n-1);
	printf("After applying merge sort : \n");
	for(int i = 0;i < n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}