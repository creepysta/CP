#include <bits/stdc++.h>
using namespace std;

struct SEG {
	vector<int> t, lazy;
	int n;
	SEG(const vector<int> &a) {
		n = 1;
		while(n <= a.size())
			n <<= 1;
		t.resize(n);
		lazy.resize(n);
		build(a, 1, 0, n-1);
	}
	void build(const vector<int>& a, int x, int lx, int rx) {
		if(lx == rx) {
			if(lx < a.size())
				t[x] = a[lx];
			return;
		}
		int mid = (lx + rx) / 2;
		build(a, 2*x, lx, mid);
		build(a, 2*x+1, mid+1, rx);
		//t[x] = t[2*x] + t[2*x + 1];
		t[x] = 0;
	}
	void update(int x, int lx, int rx, int l, int r) {

	}
	int query(int x, int lx, int rx, int X) {
		if(lx == rx) return t[x];
		int mid = (lx + rx) / 2;
		if(X <= mid)
			return t[x] + query(2*x, lx, mid, X);
		else
			return t[x] + query(2*x + 1, mid + 1, rx, X);
	}
}

int main() {
	//int n, m, q;
	//cin >> n;
	//vector<int> a(n);
	//for(int i = 0; i < n; i++)
		//cin >> a[i];
	//cin >> m;
	//for(int i = 0; i < m; i++) {
		//int l, r;
		//cin >> l >> r;
		//seg.update(l, r, 1);
	//}
	//cin >> q;
	//while(q--) {
		//int x;
		//cin >> x;
		//seg.query(x);
	//}
	for(int tt = 1; tt <= 10000; tt++) {
		mt19937 rng(tt);
		int n = 1 + rng() % 10;
		vector<int> a(n);
		for(int i = 0; i < n; i++) {
			a[i] = rng() % 10;
		}
		SEG seg(a);
		int m = rng() % 10;
		int got = -1;
		while(m--) {
			int l = rng() % 10;
			int r = l + rng() % (10 - l);
			seg.update(l, r, 1);
			for(int i = l; i <= r; i++) {
				a[i] += 1;
			}
		}
		int q = rng()%10;
		while(q--) {
			int x = rng() % 10;
			got = seg.query(x);
			assert(got == a[x]);
		}
	}

	return 0;
}
