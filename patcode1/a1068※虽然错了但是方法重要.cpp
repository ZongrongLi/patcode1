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
int A[10200];


bool flag = false;
vector<int>tmp;
vector<int>ans;
void dfs(int k,int sum) {
	if (flag)
		return;
	if (k >= n)return;
	if (sum == m) {
		ans = tmp;
		flag = true;
		return;
	}

	tmp.push_back(A[k]);
	dfs(k + 1, sum + A[k]);
	tmp.pop_back();
	dfs(k + 1, sum);
	
}
int main() {
	freopen("./test.txt", "r", stdin);
	memset(A, 0, sizeof(A));
	scanf("%d %d", &n,&m);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&A[i]);
	}
	sort(A+1, A + n+1);
	//printf();
	dfs(0, 0);
	if (flag) {
		for (int i = 0; i < ans.size(); i++) {
			if (i == 0)continue;
			if (i != ans.size() - 1)
				printf("%d ", ans[i]);
			else printf("%d", ans[i]);

		}
	}
	else
		printf("No Solution");
	return 0;
}
