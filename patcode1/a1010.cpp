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
#define LL long long
LL n1 = 0,n2,tag,radix;
#define LL long long
LL todec(string s,LL r) {
	LL sum = 0;
	for (int i = 0; i <s.size(); i++) {

		sum *= r;
		if (isdigit(s[i])) {
			if (s[i]-'0' >= r)return - 2;
			sum += s[i] - '0';
		}
		else if (isalpha(s[i])) {
			if (s[i] - 'a'+10 >= r)return -2;
			sum += s[i] - 'a' + 10;
		}
		if (sum < 0)return -1;
	}
	return sum;
}
int main() {
	freopen("./test.txt", "r", stdin);
	string s1, s2;
	cin >> s1 >> s2;
	scanf("%lld %lld",&tag,&radix);
	if (tag == 2)swap(s1, s2);
	LL t = 0;
	//printf();
	LL t1 = todec(s1,radix);
	if (t1 < 0) {
		cout << "Impossible";
		return 0;
	}
	LL Max = -1;
	for (int i = 0; i < s2.size(); i++) {
		LL ttt;
		if (isdigit(s2[i]))ttt = s2[i] - '0';
		else ttt = s2[i] - 'a' + 10;
		if (Max < ttt)Max = ttt;
	}
	bool flag = false;
	LL l, r;
	l = Max+1;
	r = t1+100;
	LL minl;
	while(l<=r) {
		LL mid = (l + r) / 2;
		
		LL tmp = todec(s2, mid);
		
		if (tmp!=-1&&tmp < t1)l = mid + 1;
		if (tmp >t1||tmp==-1)r = mid - 1;
		if (tmp == t1) {
			minl = mid;
			r = mid - 1;
			flag = true;
		}
		//if (mid == l && l == r)break;
	}
	if (!flag)printf("Impossible");
	else printf("%lld",minl);
	return 0;
}