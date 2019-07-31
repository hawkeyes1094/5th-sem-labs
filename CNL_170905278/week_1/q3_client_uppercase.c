//CN Lab week 1, Q3

//by - Teja Juluru
//created on 31/7/19

//Program where Server prints client IP and ephemeral port number
// and returns the message back in uppercase until "QUIT" is typed.
//Client side program
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORTNO 15000
#define BUFFER_LEN 256

void TerminateSocket(int sockfd) {
  close(sockfd);
  exit(0);
}

int CreateClientSocket(char* ip_address) {
  printf("entered CreateClientSocket\n");
  struct sockaddr_in  address;
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = inet_addr(ip_address);
  address.sin_port = PORTNO;

  int sockfd = socket(AF_INET,SOCK_STREAM,0);

  int address_size = sizeof(address);
  int status = connect(sockfd,(struct sockaddr*)&address,address_size);
  if(status == -1) {
    printf("Error in connecting\n");
    exit(0);
  }

  printf("returning\n");
  return sockfd;
}

void PerfromClientTask(int sockfd) {
  printf("Entered PerfromClientTask\n");
  char* buffer = (char *)malloc(BUFFER_LEN*sizeof(char));

  printf("Enter message : ");
  scanf("%[^\n]s",buffer);

  //Exit condition
  // if(!strcmp("QUIT",buffer))
  //   TerminateSocket(sockfd);

  //Send the message to the server
  int bytes_transmitted = send(sockfd,buffer,BUFFER_LEN*sizeof(char),0);

  //Print the recieved message
  printf("Message returned back in uppercase : \n");
  bytes_transmitted = recv(sockfd,buffer,BUFFER_LEN*sizeof(char),0);
  printf("%s\n",buffer);

  free(buffer);
}

int main(int argc, char const *argv[]) {
  char ip_address[] = "127.0.0.1";

  int sockfd = CreateClientSocket(ip_address);

  while(1) {
    PerfromClientTask(sockfd);
  }
  TerminateSocket(sockfd);
  return 0;
}
