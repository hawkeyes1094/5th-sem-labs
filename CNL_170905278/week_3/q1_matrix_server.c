//CN Lab week 3, Q1

//By - Teja Juluru

//UDP client server program where client sends rows of matrix 
//and the server combines them together as a matrix

//server code
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
	char buf[256];
	struct sockaddr_in serveraddr,clientaddr;

	//create UDP socket
	sd = socket(AF_INET,SOCK_DGRAM,0);

	//construct the address
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serveraddr.sin_port = htons(10200);

	int result = bind(sd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	int len = sizeof(clientaddr);

	//get the number of rows and columns in the matrix
	int rows_cols[2] = {0,0};
	int bytes_transmitted = recvfrom(sd,rows_cols,sizeof(rows_cols),0,(struct sockaddr*)&clientaddr,&len);

	//create marix
	int** matrix = (int**)malloc(rows_cols[0]*sizeof(int*));
	for(int i = 0;i < rows_cols[0];i++)
		matrix[i] = (int*)malloc(rows_cols[1]*sizeof(int));

	//recieve the rows from the client
	for(int i = 0;i < rows_cols[0];i++)
		bytes_transmitted = recvfrom(sd,matrix[i],rows_cols[1]*sizeof(int),0,(struct sockaddr*)&clientaddr,&len);

	//print the matrix
	for(int i = 0;i < rows_cols[0];i++) {
		for(int j = 0;j < rows_cols[1];j++)
			printf("%d ",matrix[i][j]);
		printf("\n");
	}

	return 0;
}