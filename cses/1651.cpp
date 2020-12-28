#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","popcnt")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define ff first
#define ss second
#define endl '\n'

const ll MOD = 1e9 + 7;

struct segtree {
	vector<ll> a;
	ll size;
	segtree() {};
	segtree(ll n) {
		size = 1LL;
		while(size < n)
			size <<= 1;
		a.assign(2*size - 1, 0LL);
	};
	void build(const vector<ll> &v, ll x, ll lx, ll rx) {
		if(rx - lx == 1) {
			if(lx < (ll) v.size()) {
				a[x] = v[lx];
			}
			return;
		}
		ll mid = lx + (rx - lx)/ 2;
		build(v, 2*x + 1, lx, mid);
		build(v, 2*x + 2, mid, rx);
		a[x] = a[2*x+1] + a[2*x+2];
	}
	void build(const vector<ll> &v) {
		build(v, 0, 0, size);
	}
	void update(ll l, ll r, ll v, ll x, ll lx, ll rx) {
		if(lx >= r || rx <= l) return;
		/*
		if(rx - lx == 1) {
			a[x] = v;
			return;
		}
		ll mid = lx + (rx - lx) / 2;
		if (i < mid)
			update(i, v, 2*x+1, lx, mid);
		else
			update(i, v, 2*x+2, mid, rx);
		a[x] = a[2*x+1] + a[2*x+2];
		*/
	}
	void update(ll l, ll r, ll v) {
		update(l, r, v, 0, 0, size);
	}
	ll query(ll l, ll r, ll x, ll lx, ll rx) {
		if(lx >= r || rx <= l) return 0LL;
		if(lx >= l && rx <= r) return a[x];
		ll mid = lx + (rx - lx) / 2;
		ll lt = query(l, r, 2*x+1, lx, mid);
		ll rt = query(l, r, 2*x+2, mid, rx);
		return lt + rt;
	}
	ll query(ll l, ll r) {
		return query(l, r, 0, 0, size);
	}
};

struct fenwick {
	int n;
	vector<ll> bit;
	fenwick() {};
	fenwick(const vector<ll> &a) {
		n = a.size();
		bit.assign(n+1,0);
		ll y = 0ll, x;
		for(int i = 0; i < n; i++) {
			x = a[i];
			add(i, x - y);
			y = x;
		}
	}
	void add(int idx, int val) {
		for(++idx; idx <= n; idx += idx & -idx)
			bit[idx] += val;
	}
	void add(int l, int r, int val) {
		add(l, val);
		add(r+1, -val);
	}
	ll sum(int idx) {
		ll ret = 0ll;
		for(++idx; idx > 0; idx -= idx & -idx) {
			ret += bit[idx];
		}
		return ret;
	}
	ll sum(int l, int r) {
		return sum(r) - sum(l-1);
	}
};

void solve() {
	ll n, q;
	cin >> n >> q;
	// segtree s(n);
	vector<ll> a(n);
	for(ll &i : a)
		cin >> i;
	fenwick f(a);
	// s.build(a);
	while(q--) {
		ll op;
		cin >> op;
		if(op == 1) {
			ll l, r, u;
			cin >> l >> r >> u;
			// s.update(a-1, b, u);
			f.add(l-1, r-1, u);
		} else {
			ll idx;
			cin >> idx;
			// cout << s.query(lx-1, rx) << endl;
			cout << f.sum(idx-1) << '\n';
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t=1;
	for(ll tt=1; tt <= t; tt++) {
		//cout << "case #" << tt << ":\n";
		solve();
	}
	return 0;
}

