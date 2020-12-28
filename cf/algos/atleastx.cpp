#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

struct segtree {
	int size;
	vector<int> tree;
	void init(int n) {
		size = 1;
		while(size < n) size <<= 1;
		tree.assign(2*size, INT_MIN);
	}
	void build(const vector<int> &a, int x, int lx, int rx) {
		if(rx - lx == 1) {
			if(lx < (int) a.size()) {
				tree[x] = a[lx];
			}
			return;
		}
		int mid = lx + (rx-lx)/2;
		build(a, 2*x+1, lx, mid);
		build(a, 2*x+2, mid, rx);
		tree[x] = max(tree[2*x+1], tree[2*x+2]);
	}
	void build(const vector<int> &a) {
		build(a, 0, 0, size);
	}

	void set(int i, int v, int x, int lx, int rx) {
		if(rx - lx == 1) {
			tree[x] = v;
			return;
		}
		int mid = lx + (rx-lx)/2;
		if(i < mid) set(i, v, 2*x+1, lx, mid);
		else set(i, v, 2*x+2, mid, rx);
		tree[x] = max(tree[2*x+1], tree[2*x+2]);
	}
	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}

	int query(int v, int l, int x, int lx, int rx) {
		if(tree[x] < v || rx <= l) return -1;
		if(rx - lx == 1) return lx;
		int mid = lx + (rx - lx) / 2;
		int res = query(v, l, 2*x+1, lx, mid);
		if(res == -1) {
			res = query(v, l, 2*x+2, mid, rx);
		}
		return res;
	}
	int query(int v, int l) {
		return query(v, l, 0, 0, size);
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int &i : a) cin >> i;
	segtree st;
	st.init(n);
	st.build(a);
	while(m--) {
		int op;
		cin >> op;
		if(op == 1) {
			int i, v;
			cin >> i >> v;
			st.set(i, v);
		} else {
			int x, l;
			cin >> x >> l;
			cout << st.query(x, l) << endl;
		}
	}
	return 0;
}
