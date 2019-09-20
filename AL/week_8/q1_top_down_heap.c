//Algo Lab week 8, Q1

//By - Teja Juluru
//Created on - 20/9/19

//Create a heap using top down approach
#include<stdio.h>
#include<stdlib.h>

int max(int a,int b) {
	return(a > b ? a : b);
}

void top_down(int arr[],int n) {
	int i = 0;
	int cur_node = 0;
	int left_child = 0,right_child = 0;
	int  flag = 1;
	while(flag != 0) {
		flag = 0;
		while(i < (n/2)) {
			// if(i == 0)
			// 	flag = 0;
			// else
			// 	flag = 1;

			// printf("i = %d\n",i);
			cur_node = arr[i];
			if((2*i)+1 < n)
				left_child = arr[(2*i) + 1];
			else
				left_child = -1;
			if((2*i)+2 < n)
				right_child = arr[(2*i) + 2];
			else
				right_child = -1;

			int max_child = max(left_child,right_child);

			//Check if the current node has to be replaced with the left child
			if(cur_node < max_child && max_child == left_child) {
				printf("current node < left child,%d %d\n",cur_node,left_child);
				int temp = arr[i];
				arr[i] = arr[(2*i) + 1];
				arr[(2*i) + 1] = temp;
				flag = 1;
			}
			//Check if the current node has to be replaced with the right child
			else if(cur_node < max_child && max_child == right_child) {
				printf("Current node < right child,%d %d\n",cur_node,right_child);
				int temp = arr[i];
				arr[i] = arr[(2*i) + 2];
				arr[(2*i) + 2] = temp;
				flag = 1;
			}
			else {

			}

			i = (i +1);
			printf("i = %d,flag = %d\n\n",i,flag);
		}
	}
}

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter the no. of elements : ");
	scanf("%d",&n);
	int* arr = (int*)malloc(n*sizeof(int));
	printf("Enter the elements : \n");
	for(int i = 0;i < n;i++) {
		scanf("%d",&arr[i]);
		top_down(arr,i+1);
	}

	top_down(arr,n);
	printf("After top down : \n");
	for(int i = 0;i < n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}