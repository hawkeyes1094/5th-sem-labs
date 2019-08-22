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

int * createClientSocket()
{
	int result , sockfd;
	
	struct sockaddr_in address;
	sockfd = socket(AF_INET,SOCK_STREAM,0);

	address.sin_family = AF_INET ;
	address.sin_addr.s_addr = inet_addr("10.86.0.132");
	address.sin_port = htons(10400);

	result = connect(sockfd,(struct sockaddr *)&address , sizeof(address));
	int res[]={result,sockfd};
	int * ptr = res ;
	return ptr ;
}

void performClientTask(int sockfd)
{
	int ch[3];
	char c ;
	char newline ;
	printf("Enter first number\n");
	scanf("%d",&ch[0]);
	printf("Enter second number\n");
	scanf("%d",&ch[1]);
	scanf("%c",&newline);
	printf("Enter +,-,*,/");
	scanf("%c",&c);
	ch[2]=(int)(c);
	write(sockfd,ch,sizeof(ch));
	
	printf("Result of operation from server is \n");

	while(1)
	{
		
		int arr[1] ;
		read(sockfd,arr,sizeof(arr));
		printf("%d \n",arr[0]);
		bzero(ch,sizeof(ch));
		break;
	}
	terminateSocket(sockfd);
	
	
}

int main()
{
	
	while(1)
	{
		char c ;
		char nwline ;
		scanf("%c",&nwline);
		printf("c to continue or q to quit\n");
		scanf("%c",&c);
		if(c=='q')
		{
			exit(0);
		}
		int  * res = createClientSocket();
		int result = *(res);
		int sockfd = *(res+1);
		if(result==-1)
		{	
			perror("\nclient error\n");
			exit(1);
		}
		performClientTask(sockfd);
	}
	

}