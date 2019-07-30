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

  //create a new socket and name
  int sockfd = socket(AF_INET,SOCK_STREAM,0);
  struct sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = inet_addr("127.0.0.1");
  address.sin_port = htons(PORTNO);
  //

  //connect to the server
  int address_size = sizeof(address);
  int status = connect(sockfd,(struct sockaddr*)&address,address_size);
  if(status == -1) {
    printf("Error in conecting\n");
    exit(0);
  }

  //read and write via socket
  char* buffer = (char *)malloc(BUFFER_LEN*sizeof(char));
  char* ch = (char *)malloc(BUFFER_LEN*sizeof(char));
  printf("Enter message : ");
  scanf("%[^\n]s",buffer);
  printf("Message length is : %d\n",strlen(buffer));

  int bytes_transmitted = 0;
  bytes_transmitted = send(sockfd,buffer,BUFFER_LEN*sizeof(char),0);
  printf("Bytes sent = %d\n",bytes_transmitted);

  bytes_transmitted = recv(sockfd,ch,BUFFER_LEN*sizeof(char),0);
  printf("bytes recieved from server = %d\n",bytes_transmitted);
  printf("String sent back from server is : ");
  printf("%s\n",ch);
  printf("Length of message sent back is %d\n",strlen(ch));

  free(buffer);
  free(ch);
  return 0;
}
