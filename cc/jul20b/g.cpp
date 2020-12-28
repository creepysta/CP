#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double

const int max = 1e9 + 5;

struct segtree {
	int size;
	vector<ll> vec;
	void init(int n) {
		size = 1;
		while(size < n) size <<= 1;
		vec.assign(2*size, 0);
	}
	void build(const vector<int> &a, int x, int lx, int rx) {
		if(rx - lx == 0) {
			if(lx < (int) a.size()) {
				vec[x] = (ll) a[lx];
			}
			return;
		}
		int mid = lx + (rx - lx) / 2;
		build(a, 2*x, lx, mid);
		build(a, 2*x+1, mid, rx);
		vec[x] = vec[2*x] + vec[2*x+1];
	}
	void build(const vector<int> &a) {
		int n = a.size();
		init(n);
		build(a, 1, 1, size);
	}

	void update(int i, int v, int x, int lx, int rx) {
		if(rx - lx == 0) {
			vec[x] = v;
		}
		int mid = lx + (rx - lx) / 2;
		if(i < mid) {
			update(i, v, 2*x, lx, mid);
		} else {
			update(i, v, 2*x+1, mid, rx);
		}
		vec[x] = vec[2*x+1] + vec[2*x];
	}
	void update(int i, int v) {
		update(i, v, 0, 1, size);
	}

	ll query(int l, int r, int x, int lx, int rx) {
		if(l >= rx || r <= lx) return 0LL;
		if(l >= lx && r <= rx) return vec[x];
		int mid = lx + (rx - lx) / 2;
		ll lt = query(l, r, 2*x, lx, mid);
		ll rt = query(l, r, 2*x + 1, mid, rx);
		return lt + rt;
	}
	ll query(int l, int r) {
		return query(l, r, 1, 1, size);
	}
};

//struct flattenTree {

//};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	segtree st;
	st.build(a);
	while(m--) {
		int op;
		cin >> op;
		if(op == 1) {
			int i, v;
			cin >> i >> v;
			st.update(i, v);
		} else {
			int l, r;
			cin >> l >> r;
			cout << st.query(l ,r);
			cout << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll t=1;
	//cin >> t;
	for(ll tt=1; tt <= t; tt++) {
		//cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}
