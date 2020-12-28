#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &a, int x, int n) {
	int largest = x;
	int lc = 2*x + 1;
	int rc = 2*x + 2;
	if(lc < n && a[largest] < a[lc]) {
		largest = lc;
	}
	if(rc < n && a[largest] < a[rc]) {
		largest = rc;
	}
	if(largest != x) {
		swap(a[largest], a[x]);
		heapify(a, largest, n);
	}
}

void mergeSort(vector<int> &a, int n) {
	// build heap
	for(int i = n/2 - 1; i >= 0; i--) {
		heapify(a, i, n);
	}
	// swap out an elem and construct heap for the rest
	for(int i = n-1; i > 0; i--) {
		swap(a[0], a[i]);
		heapify(a, 0, i);
	}
}


int32_t main () {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	mergeSort(a, n);
	for(int i = 0; i < n; i++) cout << a[i] << ' ';
	cout << endl;
	return 0;
}
