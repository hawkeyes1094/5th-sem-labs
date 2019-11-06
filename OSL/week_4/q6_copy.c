//OS Lab week 4, Q6

//Created on - 4/11/19
//By - Teja Juluru

//Program to copy the content of one file to another
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char const *argv[])
{
	char file1[50];
	memset(file1,'\0',50);
	char nl;
	printf("Enter the file name of source : \n");
	scanf("%s",file1);
	scanf("%c",&nl);

	char file2[50];
	memset(file2,'\0',50);
	printf("Enter the file name of dest : \n");
	scanf("%s",file2);
	scanf("%c",&nl);

	int fd1 = open(file1, O_RDONLY);
	if(fd1 < 0) {
		printf("error in opening source file\n");
		exit(-1);
	}

	int fd2 = open(file2, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if(fd2 < 0) {
		printf("error in opening dest file\n");
		exit(-1);
	}

	char c;
	while(read(fd1,&c,1)) {
		write(fd2,&c,1);
	}
	return 0;
}