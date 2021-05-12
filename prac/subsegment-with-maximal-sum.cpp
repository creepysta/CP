#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

struct item {
	ll seg, pref, suf, sum;
};

struct segtree {
	ll size;
	vector<item> values;
	const item NEUTRAL_ELEMENT = {0LL, 0LL, 0LL, 0LL};

	void init(ll n) {
		size = 1;
		while(size < n) size *= 2;
		values.resize(2*size);
	}

	item merge(const item &a, const item &b) {
		return {
			max(a.seg, max(b.seg, a.suf+b.pref)),
			max(a.pref, a.sum + b.pref),
			max(b.suf, b.sum + a.suf),
			a.sum + b.sum
		};
	}

	item single(ll v) {
		if(v > 0) {
			return {v, v, v, v};
		} else {
			return {0LL, 0LL, 0LL, v};
		}
	}

	void build(vector<ll> &a, ll x, ll lx, ll rx) {
		if(rx-lx==1) {
			if(lx < (ll) a.size()) {
				values[x] = single(a[lx]);
			}
			return;
		}
		ll mid = lx + (rx-lx)/2;
		build(a, 2*x+1, lx, mid);
		build(a, 2*x+2, mid, rx);
		values[x] = merge(values[2*x+1], values[2*x+2]);
	}

	void build(vector<ll> &a) {
		build(a, 0, 0, size);
	}

	void set(ll i, ll v, ll x, ll lx, ll rx) {
		if(rx-lx == 1) {
			values[x] = single(v);
			return;
		}
		ll mid = lx + (rx-lx)/2;
		if(i<mid) {
			set(i, v, 2*x+1, lx, mid);
		} else {
			set(i, v, 2*x+2, mid, rx);
		}
		values[x] = merge(values[2*x+1], values[2*x+2]);
	}

	void set(ll i, ll v) {
		set(i, v, 0, 0, size);
	}

	item calc(ll l, ll r, ll x, ll lx, ll rx) {
		if(lx >= r || rx <= l) return NEUTRAL_ELEMENT;
		if(lx >= l && rx <= r) return values[x];
		ll mid = lx + (rx - lx) / 2;
		item s1 = calc(l, r, 2*x + 1, lx, mid);
		item s2 = calc(l, r, 2*x + 2, mid, rx);
		return merge(s1, s2);
	}

	item calc(ll l, ll r) {
		return calc(l, r, 0, 0, size);
	}
};

int32_t main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll n, m;
	cin >> n >> m;

	segtree st;
	st.init(n);
	vector<ll> a(n);
	for(ll &i : a) cin >> i;
	st.build(a);
	cout << st.calc(0, n).seg << endl;
	while(m--) {
		ll i, v;
		cin >> i >> v;
		st.set(i, v);
		cout << st.calc(0, n).seg << "\n";
	}

	return 0;
}
