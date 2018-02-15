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
int st[100200];
int buff[100200];
int block[100200] = {0};
int c[100200] = { 0 };
int top = -1;
int row = 0,col;
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d\n", &n);
	col = (int)sqrt(1.0*n);
	row = (int)sqrt(1.0*n)+1;
	char s[20];
	for (int i = 0; i < n; i++) {
		memset(s, 0, sizeof(s));
		scanf("%s",s);
		if (s[1] == 'e') {
			if (top < 0) {
				printf("Invalid\n");
				getchar();
				continue;
			}
			int t;
			if ((top+1) % 2 == 0) {
				 t =(top+1) / 2 - 1;
			}
			else 
				t = (top +2)/ 2 - 1;
			t++;
			int sum = 0;
			int cnt = 0;
			while (sum+block[cnt]<t)
			{
				sum += block[cnt++];
			}
			int v = cnt* col;
			
			while (sum + c[v ] < t){
				sum += c[v++];
			}
			printf("%d\n",v);
		}
		if (s[1] == 'o') {
			if (top < 0) {
				printf("Invalid\n");
				getchar();
				continue;
			}
			block[st[top] / col]--;
			c[st[top]]--;
			printf("%d\n",st[top--]);
		}
		if (s[1] == 'u') {
			int t;
			scanf("%d",&t);
			st[++top] = t;
			c[t]++;
			block[t/col]++;
		}
		getchar();
	}
	//printf();

	return 0;
}
