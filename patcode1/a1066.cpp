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
	int h;
	node() {
		l = r = NULL;
		h = 1;
	}
};

int getH(node *t) {
	if(t == NULL)return 0;
	return t->h;
}
int getfactor(node *t) {
	return getH(t->l) - getH(t->r);
}
void updateR(node*t) {
	t->h = max(getH(t->l), getH(t->r))+1;
}
void LL(node *&t) {
	node *p = t->r;
	t->r = p->l;
	p->l = t;
	updateR(t);
	updateR(p);
	t = p;
}

void RR(node *&t) {
	node *p = t->l;
	t->l = p->r;
	p->r = t;
	updateR(t);
	updateR(p);
	t = p;
}


void insert(node*&t, int k) {
	if (t == NULL) {
		t = new node;
		t->d = k;
		return;
	}

	if (k <= t->d) {
		insert(t->l, k);
		updateR(t);
		if (getfactor(t) == 2) {
			if (getfactor(t->l) == 1) {
				RR(t);
			}
			else if (getfactor(t->l) == -1) {
				LL(t->l);
				RR(t);
			}
		}
	}
	else {
		insert(t->r,k);
		updateR(t);
		if (getfactor(t) == -2) {
			if (getfactor(t->r) == 1) {
				RR(t->r);
				LL(t);
			}
			else if (getfactor(t->r) == -1) {
				LL(t);
			}
		}
	}
}
node *root = NULL;
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d", &n); 
	
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d",&t);
		insert(root, t);
	}
	printf("%d",root->d);

	return 0;
}
