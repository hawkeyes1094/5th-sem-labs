#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>


int CreateServerSocket(char* ipaddress, int portno)//returns sockfd
{
	//create the struct
	struct sockaddr_in mysockstruct;

	//fill in the details
	mysockstruct.sin_family = AF_INET;
	mysockstruct.sin_addr.s_addr = inet_addr(ipaddress);
	mysockstruct.sin_port = htons(portno);

	//create socket
	int sockfd = socket(AF_INET,SOCK_STREAM,0);

	//bind the socket with the struct
	bind(sockfd,  (struct sockaddr*)  &mysockstruct ,sizeof(mysockstruct) );


	//return the file descriptor
	return sockfd;
}

void PerformServerTask(int newsockfd, int forkret)
{
	if(forkret==0)
	{
		//if you are the child, you can now read/write to the client on newsockfd

		
	char buf[256]; 
	memset(buf,'\0',256*sizeof(char));

	int n;

	n=read(newsockfd,buf,sizeof(buf));

	printf("Received: %s\n",buf);

	int startOfCurrentWord = 0, endOfCurrentWord = 0;

	
	char **words = (char**)malloc(100*sizeof(char*));//100 words

	for(int i=0;i<100;i++) words[i] = (char*)malloc(50*sizeof(char));//max word length = 50

	
	int wordsindex=-1;

	char temp[50];

	for(;;)
	{
		while(buf[endOfCurrentWord]!=' ') endOfCurrentWord++;

		int i;
		for(i=startOfCurrentWord;i!=endOfCurrentWord;i++)
		{
			temp[i-startOfCurrentWord]=buf[i];
		} temp[i]='\0';

		int flag = 0;//doesnt not exist

		for(int j=0;j<=wordsindex;j++)
		{
			if(!strcmp(temp,words[j]))
			{
				flag=1;//already exists
				break;
			}
		}

		if(!flag)
		{
			strcpy(words[++wordsindex],temp);
		}

		if(buf[endOfCurrentWord+1]=='\0')
			break;

		endOfCurrentWord++;
		startOfCurrentWord = endOfCurrentWord;
		memset(temp,'\0',sizeof(temp));
	}

	char ans[256];
	int k = -1;

	for(int i=0;i<=wordsindex;i++)
	{
		int j = 0;

		while(words[i][j]!='\0')
		{
			ans[++k]=words[i][j];
			j++;
		} ans[++k] = ' ';
	}

	ans[++k] = '\0';
	


	printf("Output: %s\n",ans);
	n=write(newsockfd,ans,sizeof(ans));

	exit(0);
	}
		//otherwise you must be the parent and your work for this client is finished
	else
	{
		close(newsockfd);
	}


}


int main()
{

	char ipaddress[] = "127.0.0.1";
	int portno = 10200;

	int sockfd = CreateServerSocket(ipaddress,portno);

	struct sockaddr_in clientsocket;

	int clientlength,newsockfd;

	listen(sockfd,5);
	while(1)
	{
		//accept the connection

		clientlength = sizeof(clientsocket);
		newsockfd = accept(sockfd,(struct sockaddr *)&clientsocket,&clientlength);

		PerformServerTask(newsockfd,fork());

		
	}

	return 0;
}