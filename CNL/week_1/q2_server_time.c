//CN Lab week 1, Q2

//by - Teja Juluru
//created on 31/7/19

//Program where client sends request to server to send current time
//Server sends current time and process ID of server
//Server side program
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<time.h>
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

  //current_time has time stored in integer format
  time_t current_time = time(NULL);
  struct tm *local_time = localtime(&current_time);
  //asctime() returns time in string format
  strcpy(buffer,asctime(local_time));

  //Send the time to client
  int bytes_transmitted = send(newsockfd,buffer,BUFFER_LEN*sizeof(char),0);

  //Send the PID of the server to the client
  pid_t server_pid = getpid();
  sprintf(buffer,"%d",server_pid);
  bytes_transmitted = send(newsockfd,buffer,BUFFER_LEN*sizeof(char),0);

  free(buffer);
}

int main(int argc, char const *argv[]) {
  char ip_address [] = "127.0.0.1" ;

  int sockfd = CreateServerSocket(ip_address);

  struct sockaddr_in client_addr;
  int newsockfd,client_len;

  while(1) {
    //listen for a connection
    listen(sockfd,5);
    printf("Server waiting\n");
    client_len = sizeof(client_addr);

    //accept a connection
    newsockfd = accept(sockfd,(struct sockaddr*)&client_addr,&client_len);

    PerfromServerTask(newsockfd);
  }
  return 0;
}
