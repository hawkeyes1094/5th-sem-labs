//OS Lab week 4, Q2

//By - Teja Juluru

//Program to load binary executable in child process
// using exec() system call
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
		fprintf(stderr,"Error in creating child process\n");
		exit(-1);
	}
	else if(pid == 0) {
		execlp("./q1_block_parent.o","q1_block_parent",NULL);
	}
	else {
		wait(NULL);
		printf("Child complete\n");
		exit(0);
	}

	return 0;
}