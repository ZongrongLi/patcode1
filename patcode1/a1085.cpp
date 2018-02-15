
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
LL n = 0,p;
LL A[100200] = {0};
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%lld %lld", &n,&p);
	for (int i = 0; i < n; i++) {
		scanf("%lld",&A[i]);
	}
	sort(A, A + n);
	//printf();
	LL Max = -1;
	for (int i = n-1; i >=0; i--) {
		LL M = A[i];
		LL  l = 0;
		LL r = i - 1;
		LL mid =0;
		while (l<=r)
		{
			mid = (l + r) / 2;
			if (mid == l && mid == r)break;
			if (M <= A[mid] * p)r = mid - 1;
			else l = mid + 1;
		}
		if (M > A[mid] * p)mid++;
		int len = i - mid+1;
		if (Max < len) Max = len;
	}
	printf("%lld",Max);
	return 0;
}
