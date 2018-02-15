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
int np = 0,ng;
int A[2000];
int H[2000] = {0};
int Map[2000];
vector<int>C[2000];
int ans[2000] = { 0 };
int main() {
	freopen("./test.txt", "r", stdin);
	scanf("%d %d", &np,&ng);
	for (int i = 0; i < np; i++) {
		scanf("%d",&A[i]);
		Map[A[i]] = i;
	}
	for (int i = 0; i < np; i++) {
		int t;
		scanf("%d", &t);
		C[0].push_back(A[t]);
	}
	int j = 0;
	while (true)
	{
		int Max = -1;
		int Maxi = 0;
		int cnt = 0;
		int  i = 0;
		for (; i < C[j].size(); i++) {
			if (C[j][i] == -1)continue;
			if (Max < C[j][i]) {
				Max = C[j][i];
				Maxi = i;
			}
			if ((i+1) % ng == 0) {
				C[j+1].push_back(Max) ;
				 Max = -1;
				 Maxi = 0;
			}
		}
		
		if(Max!=-1)
		{
			C[j + 1].push_back(Max);
		}
		
		
		j++;
		if (C[j].size() == 1)break;
	}
	//printf();
	int cnt = 0;
	for (int i = j; i >= 0; i--) {
		for (int k = 0; k < C[i].size(); k++) {
			if (H[C[i][k]] == 1)continue;
			H[C[i][k]] = 1;
			ans[Map[C[i][k]]] = cnt+1;
		}
		cnt += (C[i].size()-cnt);
	}
	for (int i = 0; i < np; i++) {
		if (i != np - 1)
			printf("%d ",ans[i]);
		else printf("%d", ans[i]);
	}
	return 0;
}
