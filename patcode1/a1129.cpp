#include <math.h>
#include <queue>
#include <utility>
#include <vector>
#include <iostream>
#include <string>
#include <set>
using namespace std;
int n = 0,k;
class node {
public:
	int d;
	int fre;
	node() :d(0), fre(0) {};
	bool operator<(const node &t)const {
		if (this->fre != t.fre) {
			return this->fre > t.fre;
		}
		else
			return this->d < t.d;
	}
};
int fre[100200] = {0};
set<node>s;
int main() {
	freopen("./test.txt", "r", stdin);
	scanf("%d %d", &n,&k);
	int t;
	scanf("%d", &t);
	fre[t]=1;
	node tt;
	tt.d = t;
	tt.fre = 1;
	s.insert(tt);
	for (int i = 1; i < n; i++) {
		scanf("%d",&t);
		node tmp;
		
		
		printf("%d:",t);
		set<node>::iterator it;
		int c = 0;
		for (it = s.begin(); it != s.end() && (c++) < k;it++) {
			printf(" %d",it->d);
		}
		printf("\n");
		tmp.d = t;
		tmp.fre = fre[t];
		if (s.find(tmp) != s.end())
			s.erase(tmp);
		tmp.fre++;
		fre[t]++;;
		
		s.insert(tmp);
	}
	//printf();

	return 0;
}
