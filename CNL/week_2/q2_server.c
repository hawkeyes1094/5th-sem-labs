#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>

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


void PerformServerTask(   fd_set readfds, int server_sockfd, struct sockaddr_in client_address)
{
	
		char buf[256];
		int fd,nread;

		fd_set testfds = readfds;

		printf("server waiting\n");

		int result = select(FD_SETSIZE,&testfds,(fd_set *)0,(fd_set *)0,(struct timeval *)0);
		//after thsi time, test result. if there has been an error the program exits.


		//once you know you've got activity, you can find which descriptor it's on by checking each in turn using FD_ISSET

		for(fd = 0; fd< FD_SETSIZE; fd++)
		{
			if(FD_ISSET(fd,&testfds))
			{
				//if the activity is on server_sockfd, it must be a request for a new connection, and you can add the associated client_sockfd to the descriptor set

				if(fd = server_sockfd)
				{
					int client_len = sizeof(client_address);

					int client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address,&client_len);
					
					FD_SET(client_sockfd,&readfds);

					printf("adding client on fd %d\n",client_sockfd );

				}

				//if it is not the server, it must be client activity. if close is received, the client has gone away, and you remove it from the descriptor set. otherwise, you "serve" the client as in the previous examples
				else
				{
					
					///printf("hel1");
					ioctl(fd,FIONREAD,&nread);
					//printf("hel2");

					if(nread == 0)
					{
						close(fd);
						FD_CLR(fd,&readfds);
						printf("removing client on fd %d\n",fd );
					}
					else
					{
						//read(fd,&ch,1);
						int n=read(fd,buf,sizeof(buf));

						sleep(5);
						printf("serving client on fd %d\n",fd);

						char chh[] = "temp string";
						
						write(fd,chh,strlen(chh));
					}
				}
			}
		}



}

int main()
{


	char ipaddress[] = "127.0.0.1";
	int portno = 10200;

	int server_sockfd = CreateServerSocket(ipaddress,portno);



	
	
	struct sockaddr_in client_address;
	int client_len,client_sockfd;

	int result;
	fd_set readfds, testfds;


	//create a connection queue and initialize readfds to handle input from server_sockfd

	

	FD_ZERO(&readfds);
	FD_SET(server_sockfd,&readfds);

	//now wait for clients and requests. because you have passed a null
	//pointer as the timeout parameter, no timeout will occur. the 
	//program will exit and report an error if select returns a
	//value less than 1


	listen(server_sockfd,5);
	while(1)
	{

		PerformServerTask(readfds, server_sockfd,client_address);

	}


	return 0;
}