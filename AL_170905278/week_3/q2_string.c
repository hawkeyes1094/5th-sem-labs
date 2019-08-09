//Algo Lab week3, Q2

//By - Teja Juluru

//Brute force string matching
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int string_match(char* m,int m_len,char* n,int n_len,int* opcount) {
	*opcount = 0;
	for(int i = 0;i <= m_len - n_len;i++) {
		int j;
		for(j = 0;j < n_len;j++) {
			(*opcount)++;
			if(n[j] != m[i+j])
				break;
		}
		if(j == n_len)
			return i;
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	char m[1024];
	char n[1024];
	char new_line;
	printf("Enter m : \n");
	scanf("%[^\n]s",m);
	scanf("%c",&new_line);
	fflush(stdin);
	printf("m = %s\n",m);

	printf("Enter n : \n");
	scanf("%[^\n]s",n);
	scanf("%c",&new_line);
	fflush(stdin);
	printf("n = %s\n",n);

	int opcount = 0;
	int index = string_match(m,strlen(m),n,strlen(n),&opcount);
	if(index == -1)
		printf("Substring not found\n");
	else
		printf("Substring found at index %d\n",index);
	
	printf("opcount = %d\n",opcount);

	return 0;
}