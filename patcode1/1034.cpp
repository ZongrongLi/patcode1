
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
#include<map>
using namespace std;
int n = 0,k;
vector<string>vt;
map<string, int>mp;
int A[2100][2100];
int v[2100] = { 0 };
int MaxK = -1;
string MaxId ;
int sum;
int cnt = 0;
void dfs(int k) {
	if (v[k] == 1)return;
	v[k] = 1;
	cnt++;
	int tsum = 0;
	for (int i = 0; i < vt.size(); i++) {
		if (i == k)continue;
		if (A[k][i] != 0) {
			dfs(i);
			tsum += A[k][i];
		}
	}
	if (MaxK < tsum) {
		MaxK = tsum;
		MaxId = vt[k];

	}
	sum += tsum;
	
}
class node {
public:
	string id;
	int c;
	bool operator<(node &t) {
		return this->id < t.id;
	}
};
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d %d\n", &n,&k);
	fill(A[0], A[0] + 2100 * 2100, 0);
	for (int i = 0; i < n; i++) {
		char s1[8], s2[8];
		int t;
		scanf("%s %s %d\n",s1,s2,&t);
		int a,b;
		
		if (mp.find(s1) == mp.end()) {
			vt.push_back(s1);
			mp[s1] = vt.size() - 1;
		}
		a = mp[s1];

		if (mp.find(s2) == mp.end()) {
			vt.push_back(s2);
			mp[s2] = vt.size() - 1;
		}
		b = mp[s2];
		A[b][a] += t;
		A[a][b]+= t;
	}
	//printf();

	vector<node>ans;
	for (int i = 0; i < vt.size(); i++) {
		if (v[i] == 1)continue;
		sum = 0;
		cnt = 0;
		MaxK = -1;
		dfs(i);
		if (sum/2 <= k||cnt<=2)continue;
		node t;
		t.id = MaxId;
		t.c = cnt;
		ans.push_back(t);
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) 
		printf("%s %d\n",ans[i].id.c_str(),ans[i].c);
	
	return 0;
}
