//Algo Lab week 6, Q2

//By - Teja Juluru
//Created on - 30/8/19

//Quick sort
#include<stdio.h>
#include<stdlib.h>

int opcount = 0;

void swap(int* a,int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int arr[],int low,int high) {
	int pivot = arr[high];
	int i = low -1;

	for(int j = low;j < high;j++) {
		if(arr[j] < pivot) {
			i++;
			swap(&arr[i],&arr[j]);
			opcount++;
		}
	}
	swap(&arr[i+1],&arr[high]);
	return(i+1);
}

void QuickSort(int arr[],int low,int high) {
	if(low < high) {
		int p = Partition(arr,low,high);
		QuickSort(arr,low,p-1);
		QuickSort(arr,p+1,high);
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

	QuickSort(arr,0,n-1);
	printf("After applying quick sort : \n");
	for(int i = 0;i < n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	printf("opcount = %d\n",opcount);
	return 0;
}