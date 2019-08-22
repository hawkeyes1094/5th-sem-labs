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
	address.sin_port = htons(10201);

	result = connect(sockfd,(struct sockaddr *)&address , sizeof(address));
	int res[]={result,sockfd};
	int * ptr = res ;
	return ptr ;
}

void performClientTask(int sockfd)
{
	int noe = 0 ;
	printf("How many numbers ?\n");
		scanf("%d",&noe);
		int ch[256];

	printf("Enter the numbers\n");
	for(int j=0;j<=noe-1;j++)
	{
		scanf("%d",&ch[j]);
	}
	ch[noe]=-1 ;
	write(sockfd,ch,256);
	printf("Sorted array back from server is \n");

	while(1)
	{
		
		read(sockfd,ch,sizeof(ch));
		for(int i=0;i<=noe-1;i++)
		{
			printf("%d ",ch[i]);
		}
		printf("\n");
		int id ;
		read(sockfd,id,sizeof(id));
		printf("The process id is %d\n",id);
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
		{	//printf("In");
			perror("\nclient error\n");
			exit(1);
		}
		performClientTask(sockfd);
	}
	

}