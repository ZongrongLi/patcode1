
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
int n = 0,k;

vector< vector<char>> vt;
int H[2000] = { 0 };
int v[2000] = { 0 };
string ans1;
string ans2;
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d", &k);
	string s;
	cin >> s;
	vector<char>t;
	t.push_back(s[0]);
	vt.push_back(t);
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == s[i - 1] &&vt.back().size()<k) {
			vt.back().push_back(s[i]);
		}
		else {
			vector<char>tt;
			tt.push_back(s[i]);
			vt.push_back(tt);
		}
	}

	for (int i = 0; i < vt.size(); i++) {
		if (vt[i].size() < k)H[vt[i][0]] = 1;
		else H[vt[i][0]] = 0;
	}
	//printf();

	for (int i = 0; i < vt.size(); i++) {
		if (H[vt[i][0]] == 1) {
			for (int j = 0; j < vt[i].size(); j++) {
				ans2.push_back(vt[i][j]);
			}
		}
		else {
			if (v[vt[i][0]] == 0) {
				v[vt[i][0]] = 1;
				ans1.push_back(vt[i][0]);
			}
			ans2.push_back(vt[i][0]);
		}
	}
	cout << ans1 << endl << ans2;
	return 0;
}