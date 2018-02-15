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
using namespace std;
int n = 0,m;
int dp[10200] = {0};
vector<int> A;
vector<int>vt;
int H[10200] = { 0 };
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d", &n);
	memset(H, -1, sizeof(H));
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int t;
		scanf("%d",&t);
		if (H[t] == -1) {
			vt.push_back(t);
			H[t] = vt.size()-1;
		}
		
	}
	//printf();
	scanf("%d", &m);
	for (int j = 0; j < m; j++) {
		int t;
		scanf("%d", &t);
		if (H[t] == -1)continue;
		A.push_back(H[t]);
	}
	dp[0] = 1;
	for (int i = 1; i < A.size(); i++) {
		int Max = -1;
		for (int j = 0; j < i; j++) {
			if (A[i] >= A[j]) {
				if (Max < dp[j])Max = dp[j];
			}
		}
		dp[i] = Max >=0 ? Max + 1 : 1;
	}
	printf("%d",dp[A.size()-1]);
	return 0;
}
