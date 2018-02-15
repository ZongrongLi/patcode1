
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
int n = 0,cm,sp,m;
#define INF 0x3fffffff
vector<int>tmp;
vector<int>ans;
int v[1000] = { 0 };
int A[1000][1000];
int w[1000] = { 0 };
int shortP = INF;
int takeback = INF;
int send = INF;
void dfs(int k,int d,int need,int cun) {
	if (v[k] == 1)return;
	v[k] = 1;
	tmp.push_back(k);

	int need1 = 0;
	if (w[k] < 0) {
		if (cun >= -1*w[k]) {
			cun += w[k];
			need1 = 0;
		}
		else {
			need1 =w[k]+ cun;
			cun = 0;
		}

	}
	else
		cun = cun + w[k];
	if (k == sp) {
		if (shortP > d) {
			shortP = d;
			ans = tmp;
			send = need+need1;
			takeback = cun;
		}
		else if (shortP == d) {
			if (send < (need + need1)) {
				ans = tmp;
				takeback = cun;
				send = need+need1;
			}
			else if (send == need + need1) {
				if (takeback > cun) {
					ans = tmp;
					takeback = cun;
					send = need + need1;
				}
			}
		}
		v[k] = 0;
		tmp.pop_back();
		return;
	}
	
	for (int i = 1; i <= n; i++) {
		if (A[k][i] == INF)continue;
		dfs(i, d + A[k][i], need + need1, cun);
	}
	tmp.pop_back();
	v[k] = 0;
}
int main() {
	freopen("./test.txt", "r", stdin);
	fill(A[0], A[0] + 1000 * 1000, INF);
	scanf("%d %d %d %d", &cm,&n,&sp,&m);
	for (int i = 1; i <= n; i++) {
		int t;
		scanf("%d", &t);
		w[i] = t - cm/2;
	}
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d",&a,&b,&c);
		A[b][a] = A[a][b] = c;
	}
	//printf();
	dfs(0, 0, 0, 0);
	printf("%d ",-1*send);
	for (int i = 0; i < ans.size(); i++) {
		if (i != ans.size() - 1)
			printf("%d->",ans[i]);
		else 
			printf("%d ", ans[i]);
	}
	printf("%d", takeback);
	return 0;
}
