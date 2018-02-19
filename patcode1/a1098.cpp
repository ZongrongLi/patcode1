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
int A[200];
int B[200];
int C[200];
void print() {
	for (int i = 1; i <= n; i++) {
		if (i != n)printf("%d ", C[i]);
		else printf("%d", C[i]);
	}
}
bool isequal(int a[], int b[]) {
	for (int i = 1; i <= n; i++)
		if (a[i] != b[i])return false;
	return true;
}

void adjust(int Idx) {
	int i = 1;
	int j = i * 2;
	int tmp = C[1];
	while (j<=Idx)
	{
		if (j + 1 < Idx)
			if (C[j] < C[j + 1])j++;
		if (C[j] > tmp) {
			i = j;
			j *= 2;
		}
		else
			break;
	}
	A[i] = tmp;
}

int main() {
	freopen("./test.txt", "r", stdin);

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &B[i]);
	}
	memcpy(C, A, sizeof(int)*(n + 1));
	//printf();
	bool flag = false;
	int i = 2;
	for (; i <= n; i++) {
		sort(C + 1, C + i + 1);
		if (flag) {
			printf("Insertion Sort\n");
			print();
			return 0;
		}
		if (isequal(B, C))
			flag = true;
	}
	if (flag &&i == n + 1)print();
	if (flag)return 0;
	memcpy(C, A, sizeof(int)*(n + 1));

}