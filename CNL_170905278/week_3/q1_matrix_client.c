//CN Lab week 3, Q1

//By - Teja Juluru

//UDP client server program where client sends rows of matrix 
//and the server combines them together as a matrix

//client code
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(int argc, char const *argv[])
{
	int sd;
	struct sockaddr_in address;
	sd = socket(AF_INET,SOCK_DGRAM,0);

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(10200);

	//rows_cols[0] contains the number of rows
	//rows_cols[1] contains the number of columns
	int rows_cols[2];
	printf("Enter the number of rows : ");
	scanf("%d",&rows_cols[0]);
	printf("Enter the number of columns : ");
	scanf("%d",&rows_cols[1]);

	//send the no of rows and columns to the server
	int len = sizeof(address);
	int bytes_transmitted = sendto(sd,rows_cols,sizeof(rows_cols),0,(struct sockaddr*)&address,len);

	//declare an array and input elements into it
	int* array = (int*)malloc(rows_cols[1]*sizeof(int));
	for(int i = 0;i < rows_cols[0];i++) {
		printf("Enter the elements of row %d\n",i+1);
		
		//reset the array
		memset(array,0,rows_cols[1]);

		for(int j = 0;j < rows_cols[1];j++)
			scanf("%d",&array[j]);

		//send the array to the server
		bytes_transmitted = sendto(sd,array,rows_cols[1]*sizeof(int),0,(struct sockaddr*)&address,len);
	}

	return 0;
}