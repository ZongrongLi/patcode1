
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
int dfs(node *t) {
	if (t == NULL)return 0;
	int ans =max(dfs(t->l),dfs(t->r))+1;
	if (ans == 1)a1++;
	if (ans == 2)a2++;
	return ans;
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
	dfs(root);
	if (n == 1)swap(a1, a2);
	printf("%d + %d = %d",a2,a1,a1+a2);
	return 0;
}