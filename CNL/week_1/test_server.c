//A properly functioning program
//Can be used as a template for other lab programs

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORTNO 15000
#define BUFFER_LEN 256

int main(int argc, char const *argv[]) {

  //create a new socket and bind
  int sockfd = socket(AF_INET,SOCK_STREAM,0);
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  server_addr.sin_port = htons(PORTNO);
  bind(sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr));

  //listen and accept a connection
  struct sockaddr_in client_addr;
  int newsockfd,client_len;

  while(1) {
    //listen for a connection
    listen(sockfd,5);
    printf("Server waiting\n");
    client_len = sizeof(client_addr);

    //accept a connection
    newsockfd = accept(sockfd,(struct sockaddr*)&client_addr,&client_len);

    char* buffer = (char*)malloc(BUFFER_LEN*sizeof(char));

    //read from client and print
    int bytes_transmitted = recv(newsockfd,buffer,BUFFER_LEN*sizeof(char),0);
    printf("Message from client is : %s\n",buffer);
    printf("Message length is %d\n",strlen(buffer));
    printf("Bytes recieved from client is %d\n",bytes_transmitted);

    //write the message back to the client
    bytes_transmitted = send(newsockfd,buffer,BUFFER_LEN*sizeof(char),0);
    printf("Bytes sent to the client is : %d\n",bytes_transmitted);

    free(buffer);
  }
  return 0;
}
