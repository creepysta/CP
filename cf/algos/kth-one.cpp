#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

struct segtree {
	int size;
	vector<int> tree;

	void init(int n) {
		size = 1;
		while(size < n) size<<=1;
		tree.assign(2*size, 0);
	}

	void build(vector<int> &a, int x, int lx, int rx) {
		if(rx-lx == 1) {
			if(lx < (int) a.size()) {
				tree[x] = a[lx];
			}
			return;
		}
		int mid = lx + (rx - lx) / 2;
		build(a, 2*x+1, lx, mid);
		build(a, 2*x+2, mid, rx);
		tree[x] = tree[2*x+1] + tree[2*x+2];
	}
	void build(vector<int> &a) {
		build(a, 0, 0, size);
	}

	void set(int i, int v, int x, int lx, int rx) {
		if(rx - lx == 1) {
			tree[x] = v;
			return;
		}
		int mid = lx + (rx - lx) / 2;
		if(i < mid) {
			set(i, v, 2*x+1, lx, mid);
		} else {
			set(i, v, 2*x+2, mid, rx);
		}
		tree[x] = tree[2*x+1] + tree[2*x+2];
	}
	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}

	int calc(int k, int x, int lx, int rx) {
		if(rx-lx == 1) {
			return lx;
		}
		int mid = lx + (rx-lx) / 2;
		int lc = tree[2*x+1];
		if(k < lc) {
			return calc(k, 2*x+1, lx, mid);
		} else {
			return calc(k-lc, 2*x+2, mid, rx);
		}
	}
	int calc(int k) {
		return calc(k, 0, 0, size);
	}
};

int32_t main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	segtree st;
	st.init(n);
	st.build(a);
	while(m--) {
		int op; cin >> op;
		if(op == 1) {
			ll i;
			cin >> i;
			a[i] = 1 - a[i];
			st.set(i, a[i]);
		} else {
			int k; cin >> k;
			cout << st.calc(k) << endl;
		}
	}

	return 0;
}
