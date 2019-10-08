//Practice lab 7

//By - Teja Juluru
//Created on - 24/9/19

//Pipes

//Unnecessary complicated shit but okay
//This code is stupid, and DOESN'T WORK PROPERLY. Don't judge pls.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char const *argv[])
{
	int pipefd[2];
	pid_t child_pid;

	pipe(pipefd);
	child_pid = fork();
	if(child_pid == 0) { //Child process
		close(pipefd[1]); //close unused write end
		char msg_len[5];
		read(pipefd[0],msg_len,strlen(msg_len));
		printf("Child process, message length = %d\n",atoi(msg_len));
		char* buffer = (char*)malloc(atoi(msg_len)*sizeof(char));
		read(pipefd[0],buffer,atoi(msg_len));
		printf("Message recieved = %s\n",buffer);
		close(pipefd[0]);
		exit(0);
	}
	else { //Parent process
		close(pipefd[0]); //close unused read end
		char* message = "Message";
		char msg_len[5];
		sprintf(msg_len,"%d",strlen(message)); //get the length of the message in string format
		printf("Parent process, message length = %s\n",msg_len);
		write(pipefd[1],msg_len,strlen(msg_len)); //write the length of the message
		write(pipefd[1],message,strlen(message));
		close(pipefd[1]);
		wait();
		exit(0);
	}
	return 0;
}