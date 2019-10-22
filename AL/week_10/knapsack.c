#include <stdio.h>

int max(int a,int b) {
	return a > b ? a : b;
}

int main() {
	int n;
	printf("Enter n : \n");
	scanf("%d", &n);
	int capacity;
	printf("Enter knapsack capacity : \n");
	scanf("%d", &capacity);

	printf("Eter weights and values : \n");
	int value[n], weight[n];
	for(int i=0; i<n; i++) {
		scanf("%d", &weight[i]);
		scanf("%d", &value[i]);
	}
	
	int dp[n+1][capacity+1];

	for(int i=0; i<=n; i++)
		dp[i][0] = 0;
	for(int i=0; i<=capacity; i++)
		dp[0][i] = 0;

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=capacity; j++) {
			if(j-weight[i-1] < 0) {
				dp[i][j] = dp[i-1][j];
			}
			else {
				dp[i][j] = max(dp[i-1][j], value[i-1]+dp[i-1][j-weight[i-1]]);
			}
		}
	}

	printf("\nMax val: %d\n", dp[n][capacity]);
	for(int i=n; i>0; i--) {
		if(dp[i][capacity] == dp[i-1][capacity]) {
			printf("%d not included\n", i-1);
		}
		else {
			printf("%d included\n", i-1);
			capacity = capacity-weight[i-1];
		}

	}
}
