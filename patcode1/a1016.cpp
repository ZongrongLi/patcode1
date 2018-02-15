
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
#include<map>
using namespace std;
int n = 0;
class dateM {
public:
	int d;
	int h;
	int m;
	dateM & operator++() {
		m++;
		if (m == 60) {
			m = 0; h++;
		}
		if (h >= 24) {
			h = 0;
			d++;
		}
		return *this;
	}
	bool operator<(const dateM &t) {
		int t1 = this->d * 24 * 60 + this->h * 60 + this->m;
		int t2= t.d * 24 * 60 + t.h * 60 + t.m;
		return t1 < t2;
	}
	int operator-(const dateM &t) {
		int t1 = this->d * 24 * 60 + this->h * 60 + this->m;
		int t2 = t.d * 24 * 60 + t.h * 60 + t.m;
		return t1 - t2;
	}
	bool operator==(const dateM &t) {
		int t1 = this->d * 24 * 60 + this->h * 60 + this->m;
		int t2 = t.d * 24 * 60 + t.h * 60 + t.m;
		return t1 == t2;
	}
	void print() {
		printf("%02d:%02d:%02d",d,h,m);
	}

};
class node {
public:
	dateM time;
	dateM etime;
	string id;
	int tag;
	int m;
	bool operator<(node&t) {
		if(this->id!=t.id)return this->id < t.id;
		return this->time < t.time;
		
	}
};
int T[24];	
vector<node>buff;
vector<node>buff1;

double calc(node &t) {
	dateM t1=  t.time;
	dateM t2 = t.etime;
	double sum = 0;
	while (!(t1==t2))
	{
		sum += 0.01*T[t1.h];
		++t1;
	}
	return sum;
}
map<string, vector<node> > ans;
int main() {
	freopen("./test.txt", "r", stdin);
	for (int i = 0; i < 24; i++)
		scanf("%d", &T[i]);
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		node t;
		char s[30],s1[30];
		scanf("%s %d:%d:%d:%d %s\n", s, &t.m, &t.time.d, &t.time.h, &t.time.m,s1);
		if (s1[1] == 'n')t.tag = 0;
		else if (s1[1] == 'f')t.tag = 1;
		t.id = s;
		buff.push_back(t);
	}
	sort(buff.begin(), buff.end());
	for (int i = 0; i < n-1; i++) {
		if (buff[i].id == buff[i + 1].id&&buff[i].tag == 0 && buff[i + 1].tag == 1) {
			buff[i].etime = buff[i + 1].time;
			//buff1.push_back(buff[i]);
			ans[buff[i].id].push_back(buff[i]);
			i++;
		}
	}
	
	map<string, vector<node>>::iterator it;
	for (it = ans.begin(); it != ans.end(); it++) {
		vector<node>*tmp = &(*it).second;
		printf("%s %02d\n", tmp->at(0).id.c_str(),tmp->at(0).m);
		double tot = 0.0;
		double sum = 0.0;
		for (int i = 0; i < tmp->size(); i++) {
			sum = calc(tmp->at(i));
			tot += sum;
			tmp->at(i).time.print();
			cout << " ";
			tmp->at(i).etime.print();
			printf(" %d $%.2f\n",tmp->at(i).etime -tmp->at(i).time ,sum);
		}
		printf("Total amount: $%.2f\n", tot);
		
	}
	//printf();

	return 0;
}

