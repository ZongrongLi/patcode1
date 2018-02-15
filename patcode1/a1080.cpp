
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
int n = 0,m,k;
class node {
public:
	int id;
	int ge;
	int gi;
	int f;
	int tag;
	int L[8];
	node() {
		tag = 0;
	}
	bool operator<(node&t) {
		if (this->f != t.f)return this->f > t.f;
		return this->ge > t.ge;

	}
	bool operator==(node&t) {
		return (this->f == t.f) &&(this->ge == t.ge);

	}
};
int quota[200] = {0};
vector<node>re[200];
vector<node>vt;
bool cmp(node &t1, node &t2) {
	return t1.id < t2.id;
}
int main() {
	freopen("./test.txt", "r", stdin);
	
	scanf("%d %d %d", &n,&m,&k);
	vt.resize(n + 1);
	for (int i = 0; i < m; i++) {
		scanf("%d",&quota[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &vt[i].ge, &vt[i].gi);
		vt[i].f = (vt[i].ge + vt[i].gi) / 2;
		vt[i].id = i;
		for (int j = 0; j < k; j++) {
			scanf("%d",&vt[i].L[j]);
		}
	}

	sort(vt.begin(),vt.end());
	for (int j = 0; j < n; j++){
		for (int i = 0; i < k; i++) {
			if (vt[j].tag == 1)break;
			int z = vt[j].L[i];
			if (re[z].size() >= quota[z]) {
				if ((!re[z].empty()) && (vt[j] == re[z].back())) {
					re[z].push_back(vt[j]);
					vt[j].tag = 1;
					break;
				}
				else 
				continue;
			}
			else {
				re[z].push_back(vt[j]);
				vt[j].tag = 1;
				break;
			}
		}
	}
	//printf();
	for (int i = 0; i < m; i++) {
		sort(re[i].begin(),re[i].end(),cmp);
		for (int j = 0; j < re[i].size(); j++) {
			if (j != re[i].size()-1)printf("%d ",re[i][j].id);
			else printf("%d", re[i][j].id);
		}
		printf("\n");
	}
	return 0;
}
