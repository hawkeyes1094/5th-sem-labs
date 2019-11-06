//OS Lab week 4, A1

//Created on - 4/11/19
//By - Teja Juluru

//Create an orphan process
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char const *argv[])
{
	pid_t pid;
	pid = fork();
	if(pid < 0) {
		printf("error\n");
		exit(-1);
	}
	if(pid == 0) { //child process
		printf("Child process\n");
		printf("Before sleep, PID = %d, PPID = %d\n",getpid(),getppid());
		sleep(3);
		printf("After sleep, PID = %d, PPID = %d\n",getpid(),getppid());
	}
	else { //parent
		sleep(1);
	}
	return 0;
}