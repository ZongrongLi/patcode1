
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
int n = 0,l;
vector<int> vt[1020];
int v[1020] = { 0 };
queue<int>q;
int cnt;
void bfs(int k) {
	q.push(k);
	v[k] = 1;
	int last = q.back();
	int level = 0;
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		cnt++;
		for (int i = 0; i < vt[t].size(); i++) {
			if (v[vt[t][i]] == 1)continue;
			q.push(vt[t][i]);
			v[vt[t][i]] = 1;
		}
		if (last == t) {
			level++;
			if (level > l) {
				break;
			}
			if(!q.empty())
				last = q.back();
			else break;
		}
	}
}
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d %d", &n,&l);
	for (int i = 1; i <= n; i++) {
		int c;
		scanf("%d", &c);
		for (int j = 0; j < c; j++) {
			int t;
			scanf("%d", &t);
			vt[t].push_back(i);
		}
	}
	int m;
	scanf("%d",&m);
	for (int i = 0; i < m; i++) {
		memset(v, 0, sizeof(v));
		cnt = 0;
		int t;
		scanf("%d",&t);
		while (!q.empty())q.pop();
		bfs(t);
		printf("%d\n",cnt-1);
	}
	

	return 0;
}
