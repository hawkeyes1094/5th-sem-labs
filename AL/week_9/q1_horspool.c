//Algo Lab, Q1

//By - Teja Juluru
//Created on - 27/9/19

//Horspool's algorithm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TABLESIZE 256

void BadChar(char* pattern,int size,int* shift_table) {
	for(int i = 0,j = size - 1;i < size,j >= 0;i++,j--) {
		shift_table[(int)pattern[i]] = j;
	}
}

int main(int argc, char const *argv[])
{
	char text[2048];
	int text_len;
	char pattern[512];
	int pattern_len;
	char ch;
	printf("Enter the text : \n");
	scanf("%[^\n]s",text);
	scanf("%c",&ch);
	text_len = strlen(text);

	printf("Enter the pattern : \n");
	scanf("%[^\n]s",pattern);
	scanf("%c",&ch);
	pattern_len = strlen(pattern);

	// printf("\n%s\n\n%s\n",text,pattern);
	int* shift_table = (int*)malloc(TABLESIZE*sizeof(int));
	
	BadChar(pattern,strlen(pattern),shift_table);
	
	int l,r,p;
	l = pattern_len - 1;
	r = l;
	while(l < text_len) {
		r = l;
		p = pattern_len - 1;
		while(text[r] == pattern[p]) {
			r--;
			p--;
		}
		if(p < 0) {
			printf("Pattern found at index = %d\n",l - pattern_len + 1);
			break;
		}
		printf("l = %d,r = %d,p = %d\n",l,r,p);
		int shift_len = shift_table[(int)text[r]];
		if(shift_len == 0)
			shift_len = pattern_len - 1;

		printf("shifted by length = %d\n",shift_len);
		l = l + shift_len;
	}
	if(l >= text_len)
		printf("Pattern not found\n");

	// for(int i = 0;i < TABLESIZE;i++) {
	// 	if(shift_table[i] > 0)
	// 		printf("%c -> %d ",(char)i,shift_table[i]);
	// }
	// printf("\n");
	return 0;
}