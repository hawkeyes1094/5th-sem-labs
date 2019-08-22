#include <stdio.h>  
#include <string.h>   //strlen  
#include <stdlib.h>  
#include <errno.h>  
#include <unistd.h>   //close  
#include <arpa/inet.h>    //close  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros  
#include<time.h>

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

void ServerTask(char buf[])
{
    
    time_t curtime;
    struct tm *loc_time;
    //Getting current time of system
    curtime = time(NULL);
    // Converting current time to local time
    loc_time = localtime (&curtime);
    //printf("%s", asctime (loc_time));
    strcpy(buf,asctime (loc_time));
    
}
     
int main(int argc , char *argv[])   
{   
    int master_socket , addrlen , new_socket , client_socket[30] ,  max_clients = 30 , activity, i , valread , sd;   
    int max_sd;   
    struct sockaddr_in address;   
         
    char buffer[1025];  //data buffer of 1K  
         
    //set of socket descriptors  
    fd_set readfds;     
     
    //initialise all client_socket[] to 0 so not checked  
    for (i = 0; i < max_clients; i++)   
    {   
        client_socket[i] = 0;   
    }   

    char ipaddress[] = "127.0.0.1";
    int portno = 10200;
    master_socket = CreateServerSocket(ipaddress,portno);
         
    //try to specify maximum of 3 pending connections for the master socket  
    listen(master_socket, 3);
         
    //accept the incoming connection  
    addrlen = sizeof(address);      
         
    while(1)   
    {   
        //clear the socket set  
        FD_ZERO(&readfds);   
     
        //add master socket to set  
        FD_SET(master_socket, &readfds);   
        max_sd = master_socket;   
             
        //add child sockets to set  
        for ( i = 0 ; i < max_clients ; i++)   
        {   
            //socket descriptor  
            sd = client_socket[i];   
                 
            //if valid socket descriptor then add to read list  
            if(sd > 0)   
                FD_SET( sd , &readfds);   
                 
            //highest file descriptor number, need it for the select function  
            if(sd > max_sd)   
                max_sd = sd;   
        }   
     
        //wait for an activity on one of the sockets , timeout is NULL ,  
        //so wait indefinitely  
        activity = select( max_sd + 1 , &readfds , NULL , NULL , NULL);   
             
        //If something happened on the master socket ,  
        //then its an incoming connection  
        if (FD_ISSET(master_socket, &readfds))   
        {   
            new_socket = accept(master_socket,  (struct sockaddr *)&address, (socklen_t*)&addrlen);   

            char buf[256];
            ServerTask(buf);

            
            send(new_socket, buf, strlen(buf), 0);
                 
            puts("Date and Time sent successfully");   
                 
            //add new socket to array of sockets  
            for (i = 0; i < max_clients; i++)   
            {   
                //if position is empty  
                if( client_socket[i] == 0 )   
                {   
                    client_socket[i] = new_socket;                            
                    break;   
                }   
            }   
        }
   
    }   
         
    return 0;   
} 