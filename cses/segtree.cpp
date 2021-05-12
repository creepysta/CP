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
#define MID lx+(rx-lx)/2
const ll MOD = 1e9 + 7;

/*
	elements	0 1 2 3 4
	array index	0 1 2 3 4
				10(1)
		3(2)			7(3)
	1(4)	2(5)	3(6)	4(7)

*/

struct segtree {
	vector<ll> a;
	ll size;
	segtree() {};
	segtree(const vector<ll> &v) {
		size = 1LL;
		ll n = v.size();
		while(size < n)
			size <<= 1;
		a.assign(2*size, 0LL);
		build(v, 1, 0, size-1);
	};

	void pull(ll x) {
		a[x] = a[(x<<1)] + a[(x<<1)+1];
	}
	void build(const vector<ll> &v, ll x, ll lx, ll rx) {
		if(rx == lx) {
			if(lx < (ll) v.size()) {
				a[x] = v[lx];
			}
			return;
		}
		ll mid = lx + (rx - lx)/ 2;
		build(v, 2*x, lx, mid);
		build(v, 2*x + 1, mid + 1, rx);
		pull(x);
	}
	void update(ll i, ll v, ll x, ll lx, ll rx) {
		if(rx == lx) {
			a[x] = v;
			return;
		}
		ll mid = lx + (rx - lx) / 2;
		if (i <= mid)
			update(i, v, 2*x, lx, mid);
		else
			update(i, v, 2*x+1, mid+1, rx);
		pull(x);
	}
	void update(ll i, ll v) {
		update(i, v, 1, 0, size-1);
	}
	ll query(ll l, ll r, ll x, ll lx, ll rx) {
		if(l > r) return 0LL;
		if(lx > r || rx < l) return 0LL;
		if(l <= lx && r >= rx) return a[x];
		ll mid = lx + (rx - lx) / 2;
		ll lt = query(l, r, 2*x, lx, mid);
		ll rt = query(l, r, 2*x + 1, mid + 1, rx);
		return lt + rt;
	}
	ll query(ll l, ll r) {
		return query(l, r, 1, 0, size-1);
	}
};

void solve() {
	ll n, q;
	cin >> n >> q;
	vector<ll> a(n);
	for(ll i = 0; i < n; i++)
		cin >> a[i];
	segtree s(a);
	while(q--) {
		ll op;
		cin >> op;
		if(op == 1) {
			ll k, u;
			cin >> k >> u;
			s.update(k-1, u);
		} else {
			ll lx, rx;
			cin >> lx >> rx;
			cout << s.query(lx-1, rx-1) << endl;
		}
	}
}

void test() {
	/*
	// test;
	*/
	vector<ll> a{1, 2, 3, 4};
	segtree s(a);
	for(int i = 1; i <= 4; i++) {
		for(int j = i; j <= 4; j++) {
			cout << i << ' ' << j << endl;
			cout << s.query(i-1, j-1) << endl;
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t=1;
	for(ll tt=1; tt <= t; tt++) {
		//cout << "case #" << tt << ":\n";
		//test();
		solve();
	}

	return 0;
}


