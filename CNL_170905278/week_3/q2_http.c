//CN Lab 3, Q2

//By - Teja Juluru

//Write a client program to send a manually crafted a HTTP request packet
// and display all fields recieved in HTTP response at client side
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(int argc, char const *argv[])
{
	int sd;
	struct sockaddr_in server_addr;
	char buffer[1024000];

	//create a socket
	sd = socket(AF_INET,SOCK_STREAM,0);

	//craft the HTTP packet
	char* http_packet = "GET / HTTP/1.1\r\nHost: example.com\r\nAccept: text/html\r\n\r\n";

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("93.184.216.34");
	server_addr.sin_port = htons(80);

	//connect to the server
	int status = connect(sd,(struct sockaddr*)&server_addr,sizeof(server_addr));
	if(status < 0) {
		printf("Error in connecting\n");
		exit(1);
	}

	//send the HTTP packet
	int bytes_transmitted = send(sd,http_packet,strlen(http_packet),0);
	if(bytes_transmitted < 0) {
		printf("Error in sending the packet\n");
		exit(1);
	}
	printf("Packet sent\n");

	//recieve the response from the server
	bytes_transmitted = recv(sd,buffer,1024000,0);
	if(bytes_transmitted < 0) {
		printf("Error in recieving the data\n");
		exit(1);
	}
	printf("bytes recieved = %d\n%s\n",bytes_transmitted,buffer);
	
	return 0;
}