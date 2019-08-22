//CN Lab week 1, A1

//By - Teja Juluru
//Created on 18/8/19
//Illustrate the encryption and decryption of TCP
// messages by adding 4 to the AsCII value of each alphabet
//Server side program
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORTNO 15000
#define BUFFER_LEN 256

int CreateServerSocket(char* ip_address) {
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(ip_address);
  server_addr.sin_port = PORTNO;

  int sockfd = socket(AF_INET,SOCK_STREAM,0);

  bind(sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr));

  return sockfd;
}

void PerfromServerTask(int newsockfd) {
  char* buffer = (char*)malloc(BUFFER_LEN*sizeof(char));

  //read from client and print
  int bytes_transmitted = recv(newsockfd,buffer,BUFFER_LEN*sizeof(char),0);
  printf("Message from client in encrypted form : \n%s\n",buffer);

  for()

  //write the message back to the client
  bytes_transmitted = send(newsockfd,buffer,BUFFER_LEN*sizeof(char),0);

  free(buffer);
}

int main(int argc, char const *argv[])
{
  char ip_address [] = "127.0.0.1" ;

  int sockfd = CreateServerSocket(ip_address);

  struct sockaddr_in client_addr;
  int newsockfd,client_len;

  listen(sockfd,5);

  while(1) {
  	printf("Server waiting\n");
    client_len = sizeof(client_addr);

    //accept a connection
    newsockfd = accept(sockfd,(struct sockaddr*)&client_addr,&client_len);

    PerfromServerTask(newsockfd);
  }
  return 0;
}