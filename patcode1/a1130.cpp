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
	string d;
	int l;
	int r;

};
node A[200];
vector<string >ans;
int vis[200] = {0};
void inorder(int root) {
	if (root == -1)return;
	if (A[root].l == -1 && A[root].r == -1) {
		ans.push_back(A[root].d);
		return;
	}
	ans.push_back("(");
	if(A[root].l!=-1)
		inorder(A[root].l);
	ans.push_back(A[root].d);
	if(A[root].r != -1)
		inorder(A[root].r);
	ans.push_back(")");
}
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d\n", &n);
	for (int i = 1; i <= n; i++) {
		char s[20];
		int l, r;
		scanf("%s %d %d\n", s, &l, &r);
		node t;
		if (l != -1)vis[l] = 1;
		if (r != -1)vis[r] = 1;
		t.d = s;
		t.l = l;
		t.r = r;
		A[i] = t;
	}
	int root;
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			root = i;
			break;
		}
	}
	//printf();
	inorder(root);
	if(ans.size()>=3)
	for (int i = 1; i < ans.size() - 1; i++) {
		printf("%s",ans[i].c_str());
	}
	else 
		printf("%s", ans[0].c_str());
	return 0;
}
