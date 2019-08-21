//OS Lab week 4, Q3

//By - Teja Juluru

//Program to create a child process and display
// the PID of the parent and the child in both the
// parent and the child process
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc, char const *argv[])
{
	pid_t pid;
	pid = fork();
	if(pid < 0) {
		printf("Error creating child process\n");
		exit(-1);
	}
	else if(pid == 0) {
		printf("In child process\n");
		printf("Parent PID = %ld\n",getppid());
		printf("Child PID = %ld\n",getpid());
	}
	else {
		
	}
	return 0;
}