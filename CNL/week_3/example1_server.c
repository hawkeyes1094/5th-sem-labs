//CN Lab week 3, example 1

//By - Teja Juluru

//A simple UDP echo client server program
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

	int m = recvfrom(sd,buf,sizeof(buf),0,(struct sockaddr*)&clientaddr,&len);

	printf("The server recieved : ");
	puts(buf);

	m = sendto(sd,buf,sizeof(buf),0,(struct sockaddr*)&clientaddr,len);

	return 0;
}