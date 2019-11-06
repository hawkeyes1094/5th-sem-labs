//OS Lab week 4, Q8

//Created on - 4/11/19
//By - Teja Juluru

//Simulate wc command
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

	int fd = open(file1, O_RDONLY);
	char ch;
	int lines = 0,words = 0,characters = 0;
	
	while(read(fd,&ch,1)) {
		
		switch (ch) {
			case '\n' : 
				lines++;
			case ' ' : 
				words++;
			default : 
				characters++;
				break;
		}
	}

	printf("%d %d %d %s\n",lines,words,characters,file1);
	return 0;
}