
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
class node {
public:
	int d;
	node *l;
	node *r;
	node() {
		l = r = NULL;
	}
};
void insert(node *&t,int k) {
	if (t == NULL) {
		t = new node;
		t->d = k;
		return;
	}
	if (k <=t->d ) 
		insert(t->l, k);
	else 
		insert(t->r, k);

}

int a1=0, a2=0;
int H = 0;
int getheight(node*t) {
	if (t == NULL)return 0;
	return max(getheight(t->l), getheight(t->r)) + 1;
}
void dfs(node *t,int d) {
	if (t == NULL)return;
	if (H - d == 2)a1++;
	if (H - d == 1)a2++;
	dfs(t->l, d + 1);
	dfs(t->r, d + 1);
}
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d", &n);
	node *root = NULL;
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d",&t);
		insert(root, t);
	}
	//printf();
	H = getheight(root);
	dfs(root,0);
	
	printf("%d + %d = %d",a2,a1,a1+a2);
	return 0;
}