
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
int n = 0;
int A[200] = { 0 };
int B[200] = { 0 };
int C[200] = { 0 };
bool eaqual(int a[], int b[]) {
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i])return false;
	}
	return true;
}
int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d",&A[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &C[i]);
	}
	memcpy(B, A, sizeof(int)*n);
	bool flag = false;
	for (int i = 1; i < n; i++) {
		sort(B, B + i+1);
		if (flag) {
			printf("Insertion Sort\n");
			for (int j = 0; j < n; j++) {
				if (j != n - 1)printf("%d ",B[j]);
				else printf("%d", B[j]);
			}
			break;
		}
		if (eaqual(B, C))
			flag = true;
		if (flag&&i == n - 1) {
			printf("Insertion Sort\n");
			for (int j = 0; j < n; j++) {
				if (j != n - 1)printf("%d ", B[j]);
				else printf("%d", B[j]);
			}
			return 0;
		}
	}
	if (flag)return 0;
	printf("Merge Sort\n");
	memcpy(B, A, sizeof(int)*n);
	int diff = 2;
	int i = 0;
	flag = false;
	while (true)
	{
		i = 0;
		while (i < n)
		{
			int end = min(n, i + diff);
			sort(B + i, B + end);
			i += diff;
		}
		if (flag) {
			for (int j = 0; j < n; j++) {
				if (j != n - 1)printf("%d ", B[j]);
				else printf("%d", B[j]);
			}
			return 0;
		}
		
		if (eaqual(C, B)) {
			flag = true;
		}
		if (diff > n)break;
		diff *= 2;
		if (diff > n&&flag) {
			for (int j = 0; j < n; j++) {
				if (j != n - 1)printf("%d ", B[j]);
				else printf("%d", B[j]);
			}
		}
		
	}
	
	return 0;
}
