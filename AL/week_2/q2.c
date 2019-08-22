//Algo Lab week 2, Q2

//By - Teja Juluru
//Created on 2/8/19

//GCD using middle school method
#include<stdio.h>
#include<stdlib.h>

struct array{
	int count;
	int ele[100];
};

struct array PrimeFactors(int n) {
	static struct array factors;
	factors.count = 0;
	int i = 2;
	while(n > 1) {
		if(n % i == 0) {
			factors.ele[factors.count] = i;
			n /= i;
			factors.count++;
		}
		else
			i++;
	}
	return factors;
}

struct array intersection(struct array m_factor,struct array n_factor) {
	struct array result;
	result.count = 0;
	int flag = 0;
	for(int i = 0;i < m_factor.count;i++) {
		for(int j = 0;j < n_factor.count;j++) {
			if(m_factor.ele[i] == n_factor.ele[j]) {
				result.ele[result.count] = m_factor.ele[i];
				result.count++;
				n_factor.ele[j] = 0;
				break;
			}
		}
	}
	return result;
}

int main(int argc, char const *argv[])
{
	int m = 0,n = 0;
	printf("Enter m and n : ");
	scanf("%d %d",&m,&n);
	struct array m_factor = PrimeFactors(m);
	struct array n_factor = PrimeFactors(n);

	printf("Prime factors of %d\n",m);
	for(int i = 0;i < m_factor.count;i++)
		printf("%d ",m_factor.ele[i]);
	printf("\n");

	printf("Prime factors of %d\n",n);
	for(int i = 0;i < n_factor.count;i++)
		printf("%d ",n_factor.ele[i]);
	printf("\n");

	struct array result = intersection(m_factor,n_factor);
	for(int i = 0;i < result.count;i++)
		printf("%d ",result.ele[i]);
	printf("\n");

	int gcd = 1;
	for(int i = 0;i < result.count;i++)
		gcd *= result.ele[i];

	printf("GCD = %d\n",gcd);
	return 0;
}