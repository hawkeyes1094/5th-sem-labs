//Algo Lab week 3, Q1

//By - Teja Juluru

//Sort set of integers using bubble sort and 
//analyze it's time efficiency
#include<stdio.h>
#include<stdlib.h>

int bubble_sort(int* arr,int len) {
	int opcount = 0;
	for (int i = 0; i < len; i++) {
		for(int j = 0;j < len - i - 1;j++) {
			int temp = 0;
			opcount++;
			if(arr[j] > arr[j+1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	return opcount;
}

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter the number of integers : ");
	scanf("%d",&n);
	int* arr = (int*)malloc(n*sizeof(int));
	printf("Enter the numbers : \n");
	for(int i = 0;i < n;i++) {
		scanf("%d",&arr[i]);
	}
	int opcount = bubble_sort(arr,n);
	printf("Sorted array is : \n");
	for(int i = 0;i < n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	printf("opcount = %d\n",opcount);
	return 0;
}