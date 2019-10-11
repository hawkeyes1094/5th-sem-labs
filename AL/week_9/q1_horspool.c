//Algo Lab, Q1

//By - Teja Juluru
//Created on - 27/9/19

//Horspool's algorithm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TABLESIZE 256

void BadChar(char* pattern,int size,int* shift_table) {
	for(int i = 0;i < TABLESIZE;i++)
		shift_table[i] = size;

	for(int i = 0;i < size - 1;i++) {
		shift_table[(int)pattern[i]] = size - 1 - i;
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
	for(int i = 0;i < TABLESIZE;i++) {
		printf("%d ",shift_table[i]);
	}
	printf("\n");
	//
	int i = pattern_len - 1;
	int comparisions = 0;

	while(i < text_len) {

		int k = 0;
		while(k < pattern_len && pattern[pattern_len-1-k] == text[i-k]) {
			comparisions++;
			k++;
		}
		
		if(k == pattern_len) {
			printf("Pattern found at index = %d\n",i - pattern_len + 1);
			break;
		}
		else {
			i += shift_table[text[i]];
		}
	
	}
	if(i >= text_len)
		printf("Pattern not found\n");

	printf("No. of comparisions = %d\n",comparisions);
	return 0;
}