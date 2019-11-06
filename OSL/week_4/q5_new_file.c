//OS Lab week 4, Q5

//Created on - 4/11/19
//By - Teja Juluru

//Create a file and write to it
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char const *argv[])
{
	char file_name[50];
	char nl;
	memset(file_name,'\0',50);
	printf("Enter the file name : \n");
	scanf("%s",file_name);
	scanf("%c",&nl);
	fflush(stdin);

	int fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if(fd < 0) {
		printf("Error in creating file\n");
		exit(-1);
	}
	char buf[256];
	memset(buf,'\0',256);
	printf("Enter text to write into the file : \n");
	scanf("%[^\n]s",buf);

	int bytes = write(fd,buf,strlen(buf));
	if(bytes < 0) {
		printf("Error in writing\n");
		exit(-1);
	}
	printf("written %d bytes\n",bytes);
	close(fd);
	return 0;
}