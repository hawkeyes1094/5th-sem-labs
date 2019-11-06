#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char const *argv[])
{
	pid_t pid;
	pid = fork();
	if(pid < 0) {
		printf("error\n");
		exit(-1);
	}
	if(pid == 0) { //child process
		printf("executing ls\n");
		execlp("/bin/ls","ls",NULL);
	}
	else { //parent
		int status;
		wait(NULL);
		printf("child complete\n");
	}
	return 0;
}