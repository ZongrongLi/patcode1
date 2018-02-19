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
	node(){
		l = r = NULL;
	}
};
int in[50] = {0};
int post[50] = {0};
void create(node*&t,int il,int ir,int pl,int pr) {
	if (il > ir || pl > pr)return;
	if (t == NULL) {
		t = new node;
		t->d = post[pr];

	}
	if (il == ir) return;
	int idx;
	int tmp = post[pr];
	for (int i = il; i <= ir; i++) {
		if (tmp == in[i]) {
			idx = i;
			break;
		}
	}
	int lenl = idx - il;
	create(t->l,il, il + lenl-1, pl, pl + lenl-1);
	create(t->r, idx+1, ir, pl+lenl, pr-1);
}
node *root = NULL;
queue<node*>q;
vector<int>vt;
bool flag = false;
void levelorder(node* k) {
	q.push(k);
	int last = q.back()->d;
	vt.push_back(k->d);
	while (!q.empty())
	{
		node *t =q.front();
		
		q.pop();
		if(t->l!=NULL)
			q.push(t->l);
		if(t->r!=NULL)
			q.push(t->r);
		if (t->d == last) {
			if(!q.empty())
				last = q.back()->d;
			vector<int>tmp;
			tmp.clear();
			int c = q.size();
			while (c--)
			{
				node *t = q.front();
				tmp.push_back(t->d);
				q.pop();
				q.push(t);
			}
			if (!flag) {
				for (int i = 0; i < tmp.size(); i++)
					vt.push_back(tmp[i]);
				flag = true;
			}
			else {
				for (int i = tmp.size()-1; i >=0; i--)
				vt.push_back(tmp[i]);
				flag = false;
			}
		}
	}

}
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d",&in[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &post[i]);
	}
	
	create(root,0, n - 1, 0, n - 1);
	//printf();
	levelorder(root);
	for (int i = 0; i < vt.size(); i++) {
		if(i!=vt.size()-1)
			printf("%d ",vt[i]);
		else 
			printf("%d", vt[i]);
	}
	return 0;
}
