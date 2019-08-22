//CN Lab week 1, Q2

//by - Teja Juluru
//created on 31/7/19

//Program where client sends request to server to send current time
//Server sends current time and process ID of server
//Client side program
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORTNO 15000
#define BUFFER_LEN 256

int CreateClientSocket(char* ip_address) {
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

  return sockfd;
}

void PerfromClientTask(int sockfd) {
  printf("Requesting time from server\n");
  char* buffer = (char *)malloc(BUFFER_LEN*sizeof(char));

  //Print the time recieved from the server
  int bytes_transmitted = recv(sockfd,buffer,BUFFER_LEN*sizeof(char),0);
  printf("%s\n",buffer);

  //Print the PID of the server
  bytes_transmitted = recv(sockfd,buffer,BUFFER_LEN*sizeof(char),0);
  printf("PID of server recieved\n");
  printf("%s\n",buffer);

  free(buffer);
}

void TerminateSocket(int sockfd) {
  close(sockfd);
  exit(0);
}

int main(int argc, char const *argv[]) {
  char ip_address[] = "127.0.0.1";

  int sockfd = CreateClientSocket(ip_address);

  PerfromClientTask(sockfd);

  TerminateSocket(sockfd);
  return 0;
}
