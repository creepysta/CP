#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &a, int x, int n) {
	int largest = x;
	int lc = 2*x;
	int rc = 2*x + 1;
	if(lc <= n && a[largest] < a[lc]) {
		largest = lc;
	}
	if(rc <= n && a[largest] < a[rc]) {
		largest = rc;
	}
	if(largest != x) {
		swap(a[largest], a[x]);
		heapify(a, largest, n);
	}
}

void hs(vector<int> &a, int n) {
	// build heap
	for(int i = n/2; i > 0; i--) {
		heapify(a, i, n);
	}
	// swap out an elem and construct heap for the rest
	for(int i = n; i > 1; i--) {
		swap(a[1], a[i]);
		heapify(a, 1, i-1);
	}
}


int32_t main () {
	for(int tt = 1; tt <= 100000; tt++) {
		mt19937 rng(tt);
		int n = rng() % 10;
		while(n < 5)
			n = rng() % 10;
		vector<int> a(n);
		set<int> st;
		for(int i = 0; i < n; i++) {
			int x = rng() % 30;
			while(st.find(x) != st.end())
				x = rng() % 30;
			a[i] = x;
		}
		shuffle(a.begin(), a.end(), rng);
		//for(int i : a)
			//cout << i << ' ';
		//cout << '\n';
		hs(a, n);
		//for(int i : a)
			//cout << i << ' ';
		//cout << '\n';
		assert(is_sorted(a.begin(), a.end()));
	}
	return 0;
}
