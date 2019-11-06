//OS Lab week 5, A1

//By - Teja Juluru
//Created on - 4/11/19

//Multithreaded program for matrix multiplication
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

typedef struct{
	int* row_m;
	int* col_q;
	int no_of_ele;
}structure;

//https://stackoverflow.com/questions/11428526/passing-a-matrix-in-a-function-c
//You learn something new everyday :)
void print_matrix(int m,int n,int matrix[m][n]) {
	for(int i = 0;i < m;i++) {
		for(int j = 0;j < n;j++)
			printf("%d ",matrix[i][j]);
		printf("\n");
	}
}

//Send the row and column pointers as params
void* pthread_func(void* param) {
	structure* str = (structure*)param;
	int result = 0;

	for(int i = 0;i < str->no_of_ele;i++) 
		result += str->row_m[i] * str->col_q[i];

	return (void*)result;

}

int main(int argc, char const *argv[])
{
	int m,n;
	printf("Enter no. of rows and colums for matrix 1 : \n");
	scanf("%d",&m);
	scanf("%d",&n);
	int matrix1[m][n];

	int p,q;
	printf("Enter no. of rows and colums for matrix 2 : \n");
	scanf("%d",&p);
	scanf("%d",&q);
	int matrix2[p][q];

	if(n != p) {
		printf("these matrices can't be multiplied\n");
		exit(-1);
	}

	printf("Enter matrix 1 : \n");
	for(int i = 0;i < m;i++) {
		for(int j = 0;j < n;j++)
			scanf("%d",&matrix1[i][j]);
	}

	printf("Enter matrix 2 : \n");
	for(int i = 0;i < p;i++) {
		for(int j = 0;j < q;j++)
			scanf("%d",&matrix2[i][j]);
	}


	//transpose of matrix 2
	int matrix2_t[q][p];
	for(int i = 0;i < p;i++) {
		for(int j = 0;j < q;j++)
			matrix2_t[j][i] = matrix2[i][j];
	}

	// printf("Transpose of matrix2 is : \n");
	// print_matrix(q,p,matrix2_t);

	int result[m][q];

	pthread_t thread[m][q];
	structure str[m][q];
	
	//Create a new thread for each element of the result
	for(int i = 0;i < m;i++) {
		for(int j = 0;j < q;j++) {
			str[i][j].row_m = matrix1[i];
			str[i][j].col_q = matrix2_t[j]; //
			str[i][j].no_of_ele = n;
			pthread_create(&thread[i][j],0,&pthread_func,(void*)&str[i][j]);
		}
	}

	//join the threads
	for(int i = 0;i < m;i++) {
		for(int j = 0;j < q;j++) {
			pthread_join(thread[i][j],(void**)&result[i][j]);
		}
	}

	printf("Resultant matrix is : \n");
	for(int i = 0;i < m;i++) {
		for(int j = 0;j < q;j++)
			printf("%d ",result[i][j]);
		printf("\n");
	}

	return 0;
}