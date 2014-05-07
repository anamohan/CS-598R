#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[101];

int Partition(int a[], int p, int q) {
	int i = p - 1;
	int j = q;
	while (true) {
		while (a[++i] < a[q]);
		while (a[q] < a[--j]) 
			if (j == p) break;
		if (i >= j) break;
		swap(a[i], a[j]);
	}
	swap(a[i], a[q]);
	return i;
}

void QuickSort(int a[], int p, int q) {
	if (q <= p) return;
	int partition = Partition(a, p, q);
	QuickSort(a, p, partition - 1);
	QuickSort(a, partition + 1, q);
	
}



int main() {
	int n, N = 0;
	while (scanf("%d", &n) == 1) {
		a[N] = n;
		N++;
	}
	QuickSort(a, 0, N - 1);
	for (int i = 0; i < N; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}