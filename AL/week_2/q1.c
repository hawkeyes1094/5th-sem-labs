//Algo lab week 1, Q1

//By - Teja Juluru
//Created on 2/8/19

//GCD using consecutive integer checking method
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
	int m = 0,n = 0;
	int opcount = 0;
	printf("Enter m and n : ");
	scanf("%d %d",&m,&n);
	int t = (m > n) ? m : n; //t = min(m,n)
	while(t > 0) {
		opcount++;
		if(m % t == 0 && n % t == 0)
			break;
		t--;
	}
	printf("GCD = %d\n",t);
	printf("opcount = %d\n",opcount);
	return 0;
}