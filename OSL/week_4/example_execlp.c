//OS Lab week 4, example 4

//By - Teja Juluru

//Example execlp() program
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
		execlp("/bin/ls","ls",NULL);
	}
	else {
		wait(NULL);
		printf("Child complete\n");
		exit(0);
	}

	return 0;
}