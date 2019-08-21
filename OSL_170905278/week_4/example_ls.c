//OS Lab week 4, example 1

//By - Teja Juluru

//Example program to simulate the 'ls' command
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>

int main(int argc, char const *argv[])
{
	char dir_name[20];
	DIR* dir_ptr;
	struct dirent* d_entry_ptr;
	printf("Enter directory name\n");
	scanf("%s",dir_name);

	dir_ptr = opendir(dir_name);
	if(dir_ptr == NULL) {
		printf("Cannot find directory\n");
		exit(1);
	}
	while(d_entry_ptr = readdir(dir_ptr)) {
		printf("%s\n",d_entry_ptr->d_name);
	}

	return 0;
}