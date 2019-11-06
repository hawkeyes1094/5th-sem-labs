#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc, char const *argv[])
{
	printf("Enter name of the new directory : \n");
	char path[50];
	scanf("%s",path);
	int ret_val = mkdir(path,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	if(ret_val != 0)
		printf("Error in creating dir\n");
	return 0;
}