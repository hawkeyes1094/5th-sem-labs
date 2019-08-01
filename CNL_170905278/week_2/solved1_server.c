//CN Lab week 2, Solved exercise 1

//by - Teja Juluru
//Created on 1/8/19

//A simple TCP concurrent echo server and client program
//Server side porgram
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORTNO 15000
#define BUFFER_SIZE 256

int main(int argc, char const *argv[])
{
	int sockfd,newsockfd,client_len;
	struct sockaddr_in server_addr,client_addr;
	char* buffer = (char*)malloc(BUFFER_SIZE*sizeof(char));

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_addr.sin_port = PORTNO;

	sockfd = socket(AF_INET,SOCK_STREAM,0);
	bind(sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr));

	listen(sockfd,5);
	while(1) {
		client_len = sizeof(client_addr);
		newsockfd = accept(sockfd,(struct sockaddr*)&client_addr,&client_len);

		int bytes_transmitted = 0;
		if(fork() == 0) {
			bytes_transmitted = recv(newsockfd,buffer,BUFFER_SIZE*sizeof(buffer),0);
			printf("Message recieved : %s\n",buffer);
			bytes_transmitted = send(newsockfd,buffer,BUFFER_SIZE*sizeof(buffer),0);
			close(newsockfd);
			exit(0);
		}
		else {
			close(newsockfd);
		}
	}
	return 0;
}