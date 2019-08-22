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
	
	int n;

	if(forkret==0)
	{
		//if you are the child, you can now read/write to the client on newsockfd

		char buf[256];

		memset(buf,'\0',sizeof(buf));

		time_t curtime;
	    struct tm *loc_time;
	    //Getting current time of system
	    curtime = time(NULL);
	    // Converting current time to local time
	    loc_time = localtime (&curtime);
	    //printf("%s", asctime (loc_time));
	    strcpy(buf,asctime (loc_time));

	    n = write(newsockfd,buf,sizeof(buf));

	    pid_t server_pid = getpid();
	    
		sprintf(buf, "%d", server_pid);
		
		n=write(newsockfd,buf,sizeof(buf));
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