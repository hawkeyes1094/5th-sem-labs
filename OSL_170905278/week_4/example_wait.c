//OS Lab week 4, example 3

//By - Teja Juluru

//Example wait() program
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc, char const *argv[])
{
	int status;
	pid_t pid;
	pid = fork();

	if(pid == -1) {
		printf("Error. Child not created\n");
	}
	else if(pid == 0) {
		printf("I'm the child process\n");
		exit(0);
	}
	else {
		// printf("Waiting for the child\n");
		wait(&status);
		printf("I'm the parent\n");
		printf("Child returned : %d\n",status);
	}

	return 0;
}