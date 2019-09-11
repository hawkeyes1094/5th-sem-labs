//OS Lab week 7, Example 1

//By - Teja Juluru
//Created on - 11/9/19

//Example pipes program
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<assert.h>
#include<sys/wait.h>
#define MSG_SIZE 256
int main(int argc, char const *argv[])
{
	// int pfd[2];
	// pid_t child_pid;
	// char message[MSG_SIZE];
	// strcpy(message,"Example pipes program");
	// printf("message length = %ld\n",strlen(message));

	// if(pipe(pfd) == -1) {
	// 	perror("pipe\n");
	// 	printf("Error in creating pipe, %d\n",EXIT_FAILURE);
	// 	exit(EXIT_FAILURE);
	// }

	// if(child_pid == 0) {
	// 	int buf_len;
	// 	char buffer[MSG_SIZE];
	// 	close(pfd[1]);
	// 	read(pfd[0],(char *)(&buf_len),sizeof(int));
	// 	printf("buf_len = %d\n",buf_len);
	// 	read(pfd[0],buffer,buf_len);
	// 	buffer[buf_len] = '\0';
	// 	printf("message recieved = %s\n",buffer);
	// 	close(pfd[0]);
	// 	printf("EXIT_SUCCESS = %d\n",EXIT_SUCCESS);
	// 	exit(EXIT_SUCCESS);
	// }
	// else {
	// 	close(pfd[0]);
	// 	write(pfd[1],(char *)(strlen(message)),sizeof(int));
	// 	write(pfd[1],message,strlen(message));
	// 	close(pfd[1]);
	// 	wait(NULL);
	// 	printf("message written successfully %d\n",EXIT_SUCCESS);
	// 	exit(EXIT_SUCCESS);
	// }

	int pfd[2];
	pid_t child_pid;
	char buf;

	if(pipe(pfd) == -1) {
		perror("pipe\n");
		exit(EXIT_FAILURE);
	}

	child_pid = fork();
	if(child_pid == -1) {
		perror("fork\n");
		exit(EXIT_FAILURE);
	}

	if(child_pid == 0) {
		close(pfd[1]);
		while(read(pfd[0],&buf,1) > 0)
			write(STDOUT_FILENO,&buf,1);
		write(STDOUT_FILENO,"\n",1);
		close(pfd[0]);
		exit(EXIT_SUCCESS);
	}
	else {
		close(pfd[0]);
		write(pfd[1],argv[1],strlen(argv[1]));
		close(pfd[1]);
		wait(NULL);
		exit(EXIT_SUCCESS);
	}
	return 0;
}