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

struct fenwick {
	vector<ull> bit;
	ll n;
	fenwick(ll _n) {
		n = _n;
		bit.assign(n+1, 0ULL);
	}
	fenwick(vector<ll> a) : fenwick((ll) a.size()) {
		for (size_t i = 0; i < a.size(); i++)
			add(i, a[i]);
	}

	void add(ll idx, ll delta) {
		for(++idx; idx <= n; idx += idx & -idx)
			bit[idx] += delta;
	}
	ll sum(ll idx) {
		ll ret = 0;
		for(++idx; idx > 0; idx -= idx & -idx)
			ret += bit[idx];
		return ret;
	}
	ll sum(ll l, ll r) {
		return sum(r) - sum(l-1);
	}
};
/*
   7 3 
   2 1 1 3 2 3 4 
   2 1 6 
   1 4 6 
   2 1 6 

   8 4
   3 2 4 5 1 1 5 3
   2 1 4
   2 5 6
   1 3 1
   2 1 4
 */
void solve() {
	ll n, q;
	cin >> n >> q;
	vector<ll> a(n);
	for(ll &i : a)
		cin >> i;
	fenwick tree(a);
	while(q--) {
		int op;
		cin >> op;
		if(op == 1) {
			ll i, v;
			cin >> i >> v;
			tree.add(i-1, v - a[i-1]);
			a[i-1] = v;
		} else {
			ll l, r;
			cin >> l >> r;
			cout << tree.sum(l-1, r-1) << endl;
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll t=1;
	for(ll tt=1; tt <= t; tt++) {
		//cout << "case #" << tt << ":\n";
		solve();
	}

	return 0;
}

