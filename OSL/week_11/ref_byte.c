//Needs fixing

//OS Lab week 11, additional 2a

//By - Teja Juluru
//Created on - 30/10/19

//Simulate LRU using additional reference byte algo

#include<stdio.h>

int FindLRU(int pages[][2], int n) {
	int lru = 0,lru_byte = pages[0][0];
	for(int i = 0;i < n;i++) {
		if(lru_byte < pages[i][0] || pages[i][1] == -1) {
			lru = i;
			lru_byte = pages[i][0];
		}
	}
	printf("in func. lru = %d\n",lru);
	return lru;
}

int main(int argc, char const *argv[])
{
	printf("LRU using additional reference byte\n");
	int n;
	printf("Enter the no. of pages : ");
	scanf("%d",&n);
	
	// | ref bits | pg. no |
	int pages[n][2];

	for(int i = 0;i < n;i++) {
		pages[i][0] = 0;
		pages[i][1] = -1;
	}

	int pg_req[100];
	printf("Enter the page requests (-1 to end) : \n");
	int no_of_req= 0,x = 0;
	while(1) {
		scanf("%d",&x);
		if(x < 0)
			break;
		pg_req[no_of_req] = x;
		no_of_req++;
	}

	int pg_fault = 0;

	for(int i = 0;i < no_of_req;i++) {

		//search for the page
		int flag = 0;
		int j;
		for(j = 0;j < n;j++) {
			if(pg_req[i] == pages[j][1]) {
				flag = 1;
				break;
			}
		}

		if(flag == 1) { //page in memory
			pages[j][0] = pages[j][0]>>1;
			pages[j][0] = pages[j][0] & 255;
			printf("pg hit for %d, ref byte after shift = %d\n",pages[j][1],pages[j][0]);
		}
		else { //page not int memory. Find a victim
			pg_fault++;
			int lru = FindLRU(pages,n);
			pages[lru][0] = 0;
			pages[lru][1] = pg_req[i];
			printf("pg miss for %d\n",pages[j][1]);
		}

		printf("\npage table is : \n");
		for(int k = 0;k < n;k++)
			printf("%d\t",pages[k][1]);
		printf("\n");
	}
	return 0;
}