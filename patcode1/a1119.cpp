#include <math.h>
#include <queue>
#include <utility>
#include <vector>
#include <iostream>
#include <string>
#include <set>
using namespace std;
int n = 0;
int in[50] = { 0 };
int post[50] = { 0 };
bool flag = true;
vector<int>ans;
void test(int il, int ir, int pl,int pr) {
	if (il > ir || pl > pr)return;
	if (il == ir) {
		ans.push_back(post[pr]);
		return;
	}
	//if (!flag)return;
	if (post[pr] != in[il])return;
	int Idx;
	int tmp = post[pr - 1];
	for (int i = il; i <= ir; i++) {
		if (in[i] == tmp) {
			Idx = i;
			break;
		}
	}
	if (Idx - il == 1)flag = false;
	int len = ir - il + 1;
	int lenl = Idx - il-1;
	test(il + 1, Idx - 1, pl, pl + lenl-1);
	ans.push_back(post[pr]);
	test(Idx, ir, pl+ lenl, pr-1);
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
	//printf();
	test(0, n - 1,0,n-1);
	if (flag)printf("Yes\n");
	else printf("No\n");
	for (int i = 0; i < ans.size(); i++) {
		if (i != ans.size() - 1)
			printf("%d ",ans[i]);
		else 
			printf("%d\n", ans[i]);
	}
	return 0;
}
