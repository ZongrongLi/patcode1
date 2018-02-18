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
#define INF 0x3fffffff
using namespace std;
int n = 0,m;
int A[2][600][600];
int d[600];
int T[600];
int vis[600];
int c1, c2;

vector<int>pre1[600];
vector<int>pre2[600];
void dijkstra1(int k,int tag) {
	fill(d, d + 600, INF);
	memset(T, 0, sizeof(T));
	memset(vis, 0, sizeof(vis));
	d[k] = 0;
	T[k] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1;
		int Min = INF;
		for (int j = 0; j < n; j++) {
			if (vis[j] == 1)continue;
			if (Min > d[j]) {
				Min = d[j];
				u = j;
			}
		}
		if (u == -1)return;
		vis[u] = 1;
		for (int v = 0; v < n; v++) {
			if (vis[v] == 1 || A[tag][u][v] == INF)continue;
			if (d[v] > d[u] + A[tag][u][v]) {
				d[v] = d[u] + A[tag][u][v];
				T[v] = T[u] + A[1][u][v];
				pre1[v].clear();
				pre1[v].push_back(u);
			}
			else if (d[v] == d[u] + A[tag][u][v]) {
				if (T[v] > T[u] + A[1][u][v]) {
					pre1[v].push_back(u);
				}
			}
		}
	}
}

bool isequal(vector<int>&a,vector<int>&b) {
	if (a.size() != b.size())return false;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i])return false;
	}
	return true;
}
void dijkstra2(int k, int tag) {
	fill(d, d + 600, INF);
	memset(T, 0, sizeof(T));
	memset(vis, 0, sizeof(vis));
	d[k] = 0;
	T[k] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1;
		int Min = INF;
		for (int j = 0; j < n; j++) {
			if (vis[j] == 1)continue;
			if (Min > d[j]) {
				Min = d[j];
				u = j;
			}
		}
		if (u == -1)return;
		vis[u] = 1;
		for (int v = 0; v < n; v++) {
			if (vis[v] == 1 || A[tag][u][v] == INF)continue;
			if (d[v] > d[u] + A[tag][u][v]) {
				d[v] = d[u] + A[tag][u][v];
				pre2[v].clear();
				pre2[v].push_back(u);
			}
			else if (d[v] == d[u] + A[tag][u][v]) {
					pre2[v].push_back(u);
			}
		}
	}
}
vector<int>ans1;
vector<int>ans2;
vector<int>tmp;

void dfs1(int k) {
	tmp.push_back(k);
	if (k == c1) {
		ans1 = tmp;
		tmp.pop_back();
		return;
	}
	for (int i = 0; i < pre1[k].size(); i++)
		dfs1(pre1[k][i]);
	tmp.pop_back();
}
int MinT = INF;
void dfs2(int k) {
	tmp.push_back(k);
	if (k == c1) {
		if (MinT > tmp.size()) {
			MinT = tmp.size();
			ans2 = tmp;
		}
		tmp.pop_back();
		return;
	}
	for (int i = 0; i < pre2[k].size(); i++)
		dfs2(pre2[k][i]);
	tmp.pop_back();
}
int main() {
	freopen("./test.txt", "r", stdin);
	fill(A[0][0], A[0][0] + 600 * 600, INF);
	fill(A[1][0], A[1][0] + 600 * 600, INF);
	scanf("%d %d", &n,&m);
	for (int i = 0; i < m; i++) {
		int a, b, tag, l, t;
		scanf("%d%d%d%d%d",&a,&b,&tag,&l,&t);
		A[0][a][b] = l;
		A[1][a][b] = t;
		if (tag == 0) {
			A[0][b][a] = l;
			A[1][b][a] = t;
		}
		
	}
	scanf("%d %d",&c1,&c2);
	int maxD = 0;
	dijkstra1(c1, 0);
	dfs1(c2);
	maxD = d[c2];
	dijkstra2(c1, 1);
	tmp.clear();
	dfs2(c2);
	if (!isequal(ans1,ans2)) {
		printf("Distance = %d: ", maxD);
		for (int i = ans1.size() - 1; i >= 0; i--) {
			if (i != 0)printf("%d -> ", ans1[i]);
			else printf("%d", ans1[i]);
		}
		printf("\n");
		printf("Time = %d: ",d[c2]);
		for (int i = ans2.size() - 1; i >= 0; i--) {
			if (i != 0)printf("%d -> ", ans2[i]);
			else printf("%d", ans2[i]);
		}
		return 0;
	}
	
	printf("Distance = %d; Time = %d: ", maxD,d[c2]);
	for (int i = ans1.size() - 1; i >= 0; i--) {
		if (i != 0)printf("%d -> ", ans1[i]);
		else printf("%d", ans1[i]);
	}

	return 0;
}
