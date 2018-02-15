
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
#include <map>
using namespace std;
int n = 0, k;

class node {
public:
	int id;
	int time;
	int etime;
	bool tag;
	bool operator<(const node&t) {
		if (this->id != t.id)return this->id < t.id;
		return this->time < t.time;
	}
};

vector<node>vt0;
vector<node>vt;
int Maxt = -1;
const int MOD = 1000000007;
const int p = 10000019;
vector<string> maxid;
map<int,string>mp;
int getid(char s[]) {
	int len = strlen(s);
	long long sum = 0;
	for (int i = 0; i < len; i++) {
		sum *= p;
		int t;
		if (isupper(s[i]))t = s[i] - 'A';
		else if (islower(s[i]))t = s[i] - 'a';
		else t = s[i] - '0';
		sum = (sum+t)%MOD;
	}
	return sum;
}
bool cmp(node &a, node&b) {
	return a.time < b.time;
}
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d %d\n", &n,&k);
	for (int i = 0; i < n; i++) {
		node t;
		char buff0[8];
		char buff[8];
		int h, m, s;
		scanf("%s %d:%d:%d %s\n",buff0,&h,&m,&s,buff);
		t.id = getid(buff0);
		
		mp[t.id] =buff0;
		t.time = h * 3600 + m * 60 + s;
		if (buff[0] == 'i')t.tag = false;
		else t.tag = true;
		vt0.push_back(t);
	}
	sort(vt0.begin(), vt0.end());
	int diff = 0;
	for (int i = 0; i < vt0.size()-1; i++) {
		if (i != 0 && vt0[i].id != vt0[i - 1].id) {
			diff = 0;
			//Maxt = -1;
		}
		if(vt0[i].id==vt0[i+1].id){
			if (vt0[i].tag == false && vt0[i+1].tag == true) {
				vt0[i].etime = vt0[i+1].time;
				vt.push_back(vt0[i]);
				diff +=(vt0[i+1].time - vt0[i].time);
				if (Maxt < diff) {
					Maxt = diff;
					maxid.clear();
					maxid.push_back(mp[vt0[i].id]);
				}
				else if (Maxt == diff) {
					maxid.push_back(mp[vt0[i].id]);
				}
				i++;
			}
		}
		
	}
	sort(vt.begin(),vt.end(),cmp);
	int j = 0;
	queue<node>q;
	for (int i = 0; i < k; i++) {
		int h, m, s;
		scanf("%d:%d:%d\n",&h,&m,&s);
		int time = h * 3600 + m * 60 + s;
		while (j<vt.size()&&vt[j].time <= time) 
			q.push(vt[j++]);
		int c = q.size();
		while (c--)
		{
			node tmp = q.front();
			q.pop();
			if (tmp.etime > time)q.push(tmp);
		}
		printf("%d\n",q.size());
	}
	//printf();
	sort(maxid.begin(), maxid.end());
	for (int i = 0; i < maxid.size(); i++) {
		printf("%s ",maxid[i].c_str());
	}
	printf("%02d:%02d:%02d",Maxt/3600,Maxt/60%60,Maxt%60);
	return 0;
}
