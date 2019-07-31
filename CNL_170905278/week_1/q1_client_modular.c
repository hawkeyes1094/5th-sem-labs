//CN Lab week 1, Q1

//by - Teja Juluru
//created on 31/7/19

//TCP client server porgram using modular programming techniques
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
  //read and write via socket
  char* buffer = (char *)malloc(BUFFER_LEN*sizeof(char));
  char* ch = (char *)malloc(BUFFER_LEN*sizeof(char));

  printf("Enter message : ");
  scanf("%[^\n]s",buffer);

  int bytes_transmitted = 0;
  bytes_transmitted = send(sockfd,buffer,BUFFER_LEN*sizeof(char),0);

  bytes_transmitted = recv(sockfd,ch,BUFFER_LEN*sizeof(char),0);
  printf("String sent back from server is : ");
  printf("%s\n",ch);

  free(buffer);
  free(ch);
}

void TerminateSocket(int sockfd) {
  close(sockfd);
  exit(0);
}

int main(int argc, char const *argv[]) {
  char ip_address[] = "127.0.0.1";

  int sockfd = CreateClientSocket(ip_address);

  while (1) {
    PerfromClientTask(sockfd);
  }
  return 0;
}
