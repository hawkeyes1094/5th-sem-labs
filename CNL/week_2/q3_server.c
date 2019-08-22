#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

void terminateSocket(int sockfd)
{
	close(sockfd);
}

int createServerSocket()
{
	int sockfd;
	
	struct sockaddr_in seraddr;
	sockfd = socket(AF_INET,SOCK_STREAM,0);

	seraddr.sin_family = AF_INET ;
	seraddr.sin_addr.s_addr = inet_addr("10.86.0.132");
	seraddr.sin_port = htons(10201);

	bind(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));
	listen(sockfd,5);
	
	return sockfd; 
}

void performServerTask(int sockfd)
{
	int clilen;
	struct sockaddr_in cliaddr;
	int buf[256];
	int newsockfd;
	while(1)
	{
		memset(buf,'\0',256);
		
		printf("Server waiting\n");
		clilen = sizeof(clilen);
		 newsockfd = accept(sockfd,(struct sockaddr *)&cliaddr,&clilen);
		 if(fork()==0)
		 {
		 	
		 	read(newsockfd,buf,sizeof(buf));
		 	int x = 0 ;
		 	for(x=0;x<=255;x++)
		 	{
		 		if(buf[x]==-1)
		 		{
		 			break ;
		 		}
		 	}
		 	int end = x-1 ;
		 	for(int i=0;i<=end-1;i++)
		 	{
		 		for(int j=0;j<=end-1-i;j++)
		 		{
		 			if(buf[j]>buf[j+1])
		 			{
		 				int temp = buf[j];
		 				buf[j] = buf[j+1];
		 				buf[j+1]=temp ;
		 			}
		 		}
		 	}
		 	int processid = getpid();

		 	write(newsockfd,buf,sizeof(buf));
		 	write(newsockfd,processid,sizeof(processid));
		 	terminateSocket(newsockfd);
			exit(0);
		 }
		 else
		 {
		 	terminateSocket(newsockfd);
		 }
	}
	terminateSocket(sockfd);
}

int main()
{
	int sockfd = createServerSocket();
	performServerTask(sockfd);
}