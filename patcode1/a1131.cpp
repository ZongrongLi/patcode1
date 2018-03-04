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
#define INF 0x3fffffff
int n = 0,m;
int A[10000][10000];
int st, ed;
int C[10000];
bool vis[10000];
int d[10020];
vector<int> vt[10000];

vector<int>tmp;
vector<int>ans;
int Minpath;
int Mintran;
void dfs(int k) {
	tmp.push_back(k);
	vis[k] = 1;
	if (k == ed) {
		
		int cnt = 0;
		for (int j = 1; j < tmp.size() - 1; j++) {
			if (A[tmp[j - 1]][tmp[j]] != A[tmp[j]][tmp[j + 1]]) {
				cnt++;
			}
		}
		if (Minpath > tmp.size()) {
			Minpath = tmp.size();
			Mintran = cnt;
			ans = tmp;
		}
		else if(Minpath==tmp.size()){
			if (Mintran > cnt) {
				Mintran = cnt;
				ans = tmp;
			}
		}
		tmp.pop_back();
		vis[k] = 0;
		return;
	}
	for (int i = 0; i < vt[k].size(); i++) {
		if(vis[vt[k][i]]==0)
			dfs(vt[k][i]);
	}
	vis[k] = 0;
	tmp.pop_back();
}
int main() {
	freopen("./test.txt", "r", stdin);
	memset(C, 0, sizeof(C));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int c;
		scanf("%d",&c);
		int pre;
		scanf("%d",&pre);
		C[pre]++;
		for (int j = 1; j < c; j++) {
			int t;
			scanf("%d",&t);
			A[pre][t] = i;
			A[t][pre] = i;
			vt[pre].push_back(t);
			vt[t].push_back(pre);
			C[t]++;
			pre = t;
		}
	}
	//printf();
	scanf("%d",&m);
	for (int i = 0; i < m; i++) {
		tmp.clear();
		Minpath = INF;
		Mintran = INF;
		memset(vis, 0, sizeof(vis));
		ans.clear();
		scanf("%d %d",&st,&ed);
		dfs(st);
		printf("%d\n",ans.size()-1);
		if (ans.size() == 2) {
			printf("Take Line#%d from %04d to %04d.\n",A[ans[0]][ans[1]],st,ed);
		}
		else {
			int pre = ans[0];
			for (int j = 1; j < ans.size() - 1; j++) {
				if (A[ans[j-1]][ans[j]] != A[ans[j]][ans[j+1]]) {
					printf("Take Line#%d from %04d to %04d.\n", A[ans[j-1]][ans[j]], pre, ans[j]);
					pre = ans[j];
				}
			}
			printf("Take Line#%d from %04d to %04d.\n", A[ans[ans.size() - 2]][ans[ans.size()-1]], pre, ans[ans.size() - 1]);
		}
		//cout << endl;
	}
	return 0;
}
