
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
int n = 0,m,k,Q;
class node {
public:
	int id;
	int bgt;
	int edt;
	int prot;
	
};
queue<node> buff;
vector<node> ans;
vector<queue<node> >q;
int early = 8 * 60;
int late = 17 * 60;
int getempty() {
	int Min = 65535;
	int idx = -1;
	for (int i = 0; i < n; i++) {
		if (q[i].size() >= m)continue;
		if (Min > q[i].size()) {
			Min = q[i].size();
			idx = i;
		}
	}
	return idx;
}
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d %d %d %d", &n,&m,&k,&Q);
	q.resize(n + 1);
	ans.resize(k + 2);
	for (int i = 1; i <= k; i++) {
		node t;
		t.id = i;
		scanf("%d",&t.prot);
		buff.push(t);
	}
	for (int s = early; s <= 2*late; s++) {
		for (int i = 0; i < n; i++) {
			while (!q[i].empty()&& s >= q[i].front().edt) {
				ans[q[i].front().id] = q[i].front();
				q[i].pop();
			}
		}
		while (!buff.empty()&& getempty()!=-1)
		{
			int t = getempty();
			
			if (q[t].size() == 0) {
				buff.front().edt = s + buff.front().prot;
			}
			else 
				buff.front().edt =q[t].back().edt + buff.front().prot;
			q[t].push(buff.front());
			buff.pop();
		}
	}
	//printf();
	for (int i = 1; i <= Q; i++) {
		int t;
		scanf("%d",&t);
		if (ans[t].edt-ans[t].prot >= late)printf("Sorry\n");
		else 
			printf("%02d:%02d\n", ans[t].edt / 60, ans[t].edt % 60);
	}
	return 0;
}
