#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>

struct packet{
	pid_t server_pid;
	char response[100];
};

int main(int argc, char const *argv[])
{
	int sockfd;
	struct sockaddr_in address;
	
	sockfd = socket(AF_INET,SOCK_STREAM,0);

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("172.16.49.26");
	address.sin_port = htons(9999);

	int result = connect(sockfd,(struct sockaddr*)&address,sizeof(address));

	char c = 'F';

	struct packet server_response;

	int bytes_transmitted = send(sockfd,&c,sizeof(c),0);
	bytes_transmitted = recv(sockfd,&server_response,sizeof(server_response),0);

	printf("Server PID is %d\n",server_response.server_pid);
	printf("Server message is %s\n",server_response.response);

	close(sockfd);
	return 0;
}
