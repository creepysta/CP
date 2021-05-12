#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define ff first
#define ss second
#define endl '\n'

const auto MAX = 1e9 + 5;
const auto MIN = 1e-9;

struct sumtree {
	int size;
	vector<ll> vec;
	void init(int n) {
		size = 1;
		while(size < n) size <<= 1;
		vec.assign(2*size-1, 0);
	}

	void build(const vector<int> &a, int x, int lx, int rx) {
		if(rx - lx == 1) {
			if(lx < (int) a.size()) {
				vec[x] = a[lx];
			}
			return;
		}
		int mid = lx + (rx - lx) /2;
		build(a, 2*x+1, lx, mid);
		build(a, 2*x+2, mid, rx);
		vec[x] = vec[2*x+1] + vec[2*x + 2];
	}

	void build(const vector<int> &a) {
		build(a, 0, 0, size);
	}

	void update(int i, int val, int x, int lx, int rx) {
		if(rx - lx == 1) {
			vec[x] = val;
			return;
		}
		int mid = lx + (rx - lx) /2;
		if(i < mid) {
			update(i, val, 2*x+1, lx, mid);
		} else {
			update(i, val, 2*x+2, mid, rx);
		}
		vec[x] = vec[2*x+1] + vec[2*x+2];
	}

	void update(int i, int val) {
		update(i, val, 0, 0, size);
	}

	ll query(int l, int r, int x, int lx, int rx) {
		if(lx >= r || l >= rx) return 0;
		if(lx >= l && rx <= r) return vec[x];
		int mid = lx + (rx - lx) / 2;
		ll ql = query(l, r, 2*x+1, lx, mid);
		ll qr = query(l, r, 2*x+2, mid, rx);
		return ql + qr;
	}

	ll query(int l, int r) {
		return query(l, r, 0, 0, size);
	}
};


struct mintree {
	int size;
	vector<int> vec;
	void init(int n) {
		size = 1;
		while(size < n) size <<= 1;
		vec.assign(2*size-1, INT_MAX);
	}

	void build(const vector<int> &a, int x, int lx, int rx) {
		if(rx - lx == 1) {
			if(lx < (int) a.size()) {
				vec[x] = a[lx];
			}
			return;
		}
		int mid = lx + (rx - lx) /2;
		build(a, 2*x+1, lx, mid);
		build(a, 2*x+2, mid, rx);
		vec[x] = min(vec[2*x+1],vec[2*x + 2]);
	}

	void build(const vector<int> &a) {
		build(a, 0, 0, size);
	}

	void update(int i, int val, int x, int lx, int rx) {
		if(rx - lx == 1) {
			vec[x] = val;
			return;
		}
		int mid = lx + (rx - lx) /2;
		if(i < mid) {
			update(i, val, 2*x+1, lx, mid);
		} else {
			update(i, val, 2*x+2, mid, rx);
		}
		vec[x] = min(vec[2*x+1],vec[2*x+2]);
	}

	void update(int i, int val) {
		update(i, val, 0, 0, size);
	}

	ll query(int l, int r, int x, int lx, int rx) {
		if(lx >= r || l >= rx) return MAX;
		if(lx >= l && rx <= r) return vec[x];
		int mid = lx + (rx - lx) / 2;
		ll ql = query(l, r, 2*x+1, lx, mid);
		ll qr = query(l, r, 2*x+2, mid, rx);
		return min(ql, qr);
	}

	ll query(int l, int r) {
		return query(l, r, 0, 0, size);
	}
};

struct minCountTree {
	int size;
	vector<pii> vec;
	void init(int n) {
		size = 1;
		while(size < n) size <<= 1;
		vec.resize(2*size-1);
	}

	pii min(const pii &p, const pii &q) {
		if(p.ff < q.ff) return p;
		else if(p.ff > q.ff) return q;
		else return {p.ff, p.ss+q.ss};
	}

	void build(const vector<int> &a, int x, int lx, int rx) {
		if(rx - lx == 1) {
			if(lx < (int) a.size()) {
				vec[x] = {a[lx], 1};
			}
			return;
		}
		int mid = lx + (rx - lx) /2;
		build(a, 2*x+1, lx, mid);
		build(a, 2*x+2, mid, rx);
		vec[x] = min(vec[2*x+1],vec[2*x + 2]);
	}

	void build(const vector<int> &a) {
		build(a, 0, 0, size);
	}

	void update(int i, int val, int x, int lx, int rx) {
		if(rx - lx == 1) {
			vec[x] = {val,1};
			return;
		}
		int mid = lx + (rx - lx) /2;
		if(i < mid) {
			update(i, val, 2*x+1, lx, mid);
		} else {
			update(i, val, 2*x+2, mid, rx);
		}
		vec[x] = min(vec[2*x+1],vec[2*x+2]);
	}

	void update(int i, int val) {
		update(i, val, 0, 0, size);
	}

	pii query(int l, int r, int x, int lx, int rx) {
		if(lx >= r || l >= rx) return {MAX, 1};
		if(lx >= l && rx <= r) return vec[x];
		int mid = lx + (rx - lx) / 2;
		pii ql = query(l, r, 2*x+1, lx, mid);
		pii qr = query(l, r, 2*x+2, mid, rx);
		return min(ql, qr);
	}

	pii query(int l, int r) {
		return query(l, r, 0, 0, size);
	}
};

void operator<<(ostream &cout, const pii &p) {
	cout << p.ff << ' ' << p.ss;
}


int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	//sumtree st;
	//mintree st;
	minCountTree st;
	st.init(n);
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
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
	return 0;
}
