//CN Lab week 2, Solved exercise 1

//by - Teja Juluru
//Created on 1/8/19

//A simple TCP concurrent echo server and client program
//Client side porgram
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORTNO 15000
#define BUFFER_LEN 256

int main(int argc, char const *argv[])
{
	char* buffer = (char *)malloc(BUFFER_LEN*sizeof(char));
	char* ch = (char *)malloc(BUFFER_LEN*sizeof(char));
	int sockfd;
	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = PORTNO;

	
	int address_size = sizeof(address);
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	int status = connect(sockfd,(struct sockaddr*)&address,address_size);
  	if(status == -1) {
    	printf("Error in connecting\n");
    	exit(0);
  	}
	printf("Enter message : ");
	scanf("%[^\n]s",buffer);

	int bytes_transmitted = 0;
	bytes_transmitted = send(sockfd,buffer,BUFFER_LEN*sizeof(char),0);

	bytes_transmitted = recv(sockfd,ch,BUFFER_LEN*sizeof(char),0);
	printf("String sent back from server is : ");
	printf("%s\n",ch);
	free(buffer);
	free(ch);
	return 0;
}