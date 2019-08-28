#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char const *argv[])
{
	char filename[50];
	printf("Enter filename : ");
	scanf("%s",filename);

	int fd1 = open(filename,O_RDONLY);
	int fd2 = open("secret.txt",O_WRONLY | O_CREAT,0644);
	char c;

	while(read(fd1,&c,1)) {
		if(c == ' ') {
			write(fd2," ",1);
			continue;
		}
		else {
			c = c+1;
			write(fd2,&c,1);
		}
	}
	write(fd2,"\n\r",2);
	close(fd1);
	close(fd2);

	return 0;
}