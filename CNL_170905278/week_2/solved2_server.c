//CN Lab week 2, Solved exercise 1

//by - Teja Juluru
//Created on 1/8/19

//Program to handle multiple clients using select()
//Server side program
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/time.h>
#include<sys/ioctl.h>
#include<unistd.h>
#define PORTNO 15000
#define BUFFER_SIZE 256

int main(int argc, char const *argv[])
{
	int server_sockfd,client_sockfd;
	struct sockaddr_in server_addr,client_addr;
	int server_len,client_len;
	int result;
	fd_set readfs,testfs;

	server_sockfd = socket(AF_INET,SOCK_STREAM,0);
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_addr.sin_port = PORTNO;
	server_len = sizeof(server_addr);
	
	bind(server_sockfd,(struct sockaddr*)&server_addr,server_len);
	listen(server_sockfd,5);

	FD_ZERO(&readfs);
	FD_SET(server_sockfd,&readfs);

	while(1) {
		char ch;
		int fd,nread;
		testfs = readfs;
		printf("server waiting\n");
		result = select(FD_SETSIZE,&testfs,(fd_set *)0,(fd_set *)0,(struct timeval *)0);

		if(result < 1) {
			perror("server error");
			exit(1);
		}

		for(fd = 0;fd < FD_SETSIZE;fd++) {
			if(FD_ISSET(fd,&testfs)) {
				if(fd == server_sockfd) {
					client_len = sizeof(client_addr);
					client_sockfd = accept(server_sockfd,(struct sockaddr*)&client_addr ,&client_len);
					FD_SET(client_sockfd,&readfs);
					printf("adding client on fd %d\n,client_sockfd");
				}
				else {
					ioctl(fd,FIONREAD,&nread);
					if(nread == 0) {
						close(fd);
						FD_CLR(fd,&readfs);
						printf("removing client on fd %d\n",fd);
					}
					else {
						read(fd,&ch,1);
						sleep(5);
						printf("serving client on fd %d\n",fd);
						ch++;
						write(fd,&ch,1);
					}
				}
			}
		}
	}
	return 0;
}