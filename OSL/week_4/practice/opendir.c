#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/types.h>

int main(int argc, char const *argv[])
{
	char dir_name[50];
	DIR* dir_p;
	struct dirent * dir;
	printf("Enter directory name : \n");
	scanf("%s",dir_name);

	dir_p = opendir(dir_name);
	if(dir_p == NULL) {
		printf("Error\n");
		exit(-1);
	}

	printf("inode\td_off\td_reclen\td_type\td_name\n");
	while(dir = readdir(dir_p)) {
		printf("%ld\t",dir->d_ino);
		// printf("%ld\t",dir->d_off);
		// printf("%d\t",dir->d_reclen);
		// printf("%c\t",dir->d_type);
		printf("%s\n",dir->d_name);
	}
	closedir(dir_p);

	return 0;
}