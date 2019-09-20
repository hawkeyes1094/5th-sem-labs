//Algo Lab week 8, Example 1

//By - Teja Juluru
//Created on - 20/9/19

//Bottom up heap construction from an array
// NOT WORKING
#include<stdio.h>
#include<stdlib.h>

void heapify(int arr[],int n) {
	int i,k,v,heapify,j;
	for(int i = (n/2);i >= 1;i--) {
		k = i;
		v = arr[k];
		heapify = 0;
		while(heapify == 0 && 2*k <= n) {
			j = 2*k;
			if(j < n) {
				if(arr[j] < arr[j+1])
					j = j+1;
			}
			if(v >= arr[j])
				heapify = 1;
			else {
				arr[k] = arr[j];
				k = j;
			}
		}
		arr[k] = v;
	}
	return;
}

int main(int argc, char const *argv[])
{
	int n = 1;
	// printf("Enter the no. of elements : ");
	// scanf("%d",&n);
	// int* arr = (int*)malloc((n+1)*sizeof(int));
	int arr[20];
	int ch = 1;
	printf("Enter the elements : \n");
	scanf("%d",&ch);
	while(ch!=0)
	{
		arr[n]=ch;
		heapify(arr,n++);
		scanf("%d",&ch);
	}
	printf("The heap created is : \n");
	for(int i = 1;i < n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}