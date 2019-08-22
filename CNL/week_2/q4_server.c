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
	seraddr.sin_port = htons(10400);

	bind(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));
	listen(sockfd,5);
	
	return sockfd; 
}

void performServerTask(int sockfd)
{
	int clilen;
	struct sockaddr_in cliaddr;
	int buf[3];
	
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
		 	int a = buf[0];
		 	int b = buf[1];
		 	char c = (char)buf[2];
		 	int res = 0 ;
		 	// printf("a is %d\n",a);
		 	// printf("b is %d\n",b);
		 	if(c=='+')
		 	{
		 		res = a+b ;
		 	}
		 	else if(c=='-')
		 	{
		 		res = a-b ;
		 	}
		 	else if(c=='*')
		 	{
		 		res = a*b ;
		 	}
		 	else
		 	{
		 		res=a/b ;
		 	}
		 	//printf("The result is %d \n",res); 
		 	int arr[1];
		 	arr[0]=res ;
		 	write(newsockfd,arr,sizeof(arr));
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