#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <utility>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <functional>
using namespace std;
int n = 0,m;
int A[10200] = { 0 };
int dp[10200][200];
bool c[10200][200];
int flag[10200] = {0};
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d %d", &n,&m);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&A[i]);
	}
	sort(A + 1, A + 1 + n,greater<int>());
	for (int i = 0; i <n+1; i++)dp[i][0] = 0;
	for (int i = 0; i < m+1; i++)dp[0][i] = 0;
	for(int i=1;i<=n;i++)
		for (int v = A[i]; v <= m; v++) {
			if (dp[i - 1][v] <= dp[i - 1][v - A[i]]+A[i]) {
				dp[i][v] = dp[i - 1][v - A[i]] + A[i];
				c[i][v] = 1;
			}
			else 
				dp[i][v] = dp[i - 1][v];
		}
	//printf();
	if (dp[n][m] != m) {
		printf("No Solution");
		return 0;
	}
	int t = m;
	int k = n;
	int cnt = 0;
	while (k>=0)
	{
		if (c[k][t] == 1) {
			t -=A[k];
			flag[k] = 1;
			cnt++;
		}
		k--;
	}
	
	for (int i = n; i >=1; i--) {
		if (flag[i] == 1) {
			cnt--;
			printf("%d", A[i]);
			if (cnt != 0)
			printf(" ");
		}	
	}
	return 0;
}
