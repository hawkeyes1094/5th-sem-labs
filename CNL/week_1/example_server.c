//Computer network lab week 1, Solved exercise

//by - Teja Juluru
//created on 25/07/19

//server code

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORTNO 10200

int main(int argc, char const *argv[])
{
	int sockfd,newsockfd,portno,clilen,n=1;
	struct sockaddr_in seraddr,cliaddr;
	int i,value;

	//create an unamed socket for the server
	sockfd = socket(AF_INET,SOCK_STREAM,0);

	//name the socket
	seraddr.sin_family = AF_INET;
	//Change the IP address dumbass
	seraddr.sin_addr.s_addr = inet_addr("127.0.0.1"); //MY PC IP addr
	seraddr.sin_port = htons(PORTNO);
	bind(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));

	//create a connection
	listen(sockfd,5);
	while(1) {
		char buf[256];
		printf("Server waiting");

		//accept a connection
		clilen = sizeof(clilen);
		newsockfd = accept(sockfd,(struct sockaddr *)&cliaddr,&clilen);

		//Read and write to client on client_sockfd ()
		n = read(newsockfd,buf,sizeof(buf));
		printf("\nMessage form client %s \n",buf);
		n = write(newsockfd,buf,sizeof(buf));
	}
	return 0;
}
