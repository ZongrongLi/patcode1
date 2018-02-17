
#include <stdio.h>
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
int n = 0;

int A[1050];
int cnt[1050] = {0};
int getroot(int k) {
	int t = k;
	while (A[k] != k)k = A[k];
	while (A[t]!=t)
	{
		int tmp = A[t];
		A[t] = k;
		t = A[t];
	}
	return k;
}
void join(int a,int b) {
	int aa = getroot(a);
	int bb = getroot(b);
	if (aa > bb)swap(aa, bb);
	A[bb] = aa;
}
int B[1020] = { 0 };
vector<int>ans;
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d", &n);
	for (int i = 0; i < 1020; i++) {
		A[i] = i;
	}
	for (int i = 1; i <=n; i++) {
		int c = 0;
		scanf("%d:",&c);
		int tt;
		scanf("%d", &tt);
		B[i] = tt;
		for (int j = 0; j < c-1; j++) {
			int t;
			scanf("%d", &t);
			join(t,tt);
		}
	}
	for (int i = 1; i <= n; i++) 
		cnt[getroot(B[i])]++;
	
	for (int i = 1; i < 1020; i++) {
		if (cnt[i] != 0)ans.push_back(cnt[i]);
	}
	printf("%d\n",ans.size());
	sort(ans.begin(), ans.end());
	for (int i = ans.size() - 1; i >= 0; i--) {
		if (i != 0)printf("%d ",ans[i]);
		else printf("%d", ans[i]);
	}

	return 0;
}
