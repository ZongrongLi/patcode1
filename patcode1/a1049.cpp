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

int getl(const string &s,int t) {
	string s1="0";
	for (int i = 0; i < t; i++)s1.push_back(s[i]);
	return atoi(s1.c_str());
}
int getr(const string &s,int t) {
	string s1="0";
	for (int i = t + 1; i < s.size(); i++)s1.push_back(s[i]);
	return atoi(s1.c_str());
}
int cnt1(int k) {//ËÑË÷·½·¨¿Û°Ë·Ö
	char s[20];
	sprintf(s,"%d",k);
	int cnt = 0;
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		if (s[i] == '1')cnt++;
	}
	return cnt;
}
int main() {
	freopen("./test.txt", "r", stdin);

	string s;
	cin >> s;
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		int l = getl(s,i);
		int r = getr(s, i);
		if (s[i] == '0') {
			if (l == 0)continue;
			sum += (l)*pow(10, (s.size() - i)-1);
		}
		else if (s[i] == '1') {
			sum += (l)*pow(10, (s.size() - i) - 1) +r+1;
		}
		else {
			sum += (l+1)*pow(10, (s.size() - i) - 1);
		}

		
	}
	
	printf("%d",sum);

	return 0;
}